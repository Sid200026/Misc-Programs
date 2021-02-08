## NAME : Siddharth Singha Roy
## Reg No. : 18BCE1065
## Date : 8.2.21
## Lab - 2

library(knitr)
library(dplyr)
library(data.table)
library(stringr)
library(lubridate)
library(tidyr)
library(ggplot2)
library(tigerstats)
library(e1071)
library(ggpubr)
library(DMwR)
library(randomForest)
library(pROC)
library(MLmetrics)
library(car)
library(caret)
library(corrplot)
library(Metrics)

# Constant Declaration

DATA_PATH = "/Users/apple/Downloads/train.csv"

# End of Constant Declaration

data = fread(DATA_PATH)
head(data)

# Information about the dataset

dim(data) # Dimensions of data
colnames(data) # Column names
anyNA(data) # No data is missing
str(data) # Structure of data

# Converting datatypes from int to num

convert_int_to_num = function(X) {
  if(is.integer(X)) {
    return(as.numeric(X))
  }
  return(X)
}

data = data[, lapply(.SD, convert_int_to_num)]

# Drop certain columns

data = select(data, -"City")
data = select(data, -"Id")
data = select(data, -"Open Date")
data = select(data, -"City Group")

# Statistical analysis on the data

summary(data)

xtabs(~Type, data=data) # How Type variable is distributed
data = data[Type != 'DT', .SD]
rowPerc(xtabs(~Type, data=data)) # Row percentage of Type variable
favstats(data$revenue)

numeric_columns = unlist(lapply(data, is.numeric))  
cor(data[, ..numeric_columns], use="na.or.complete") # Correlation score among the columns

# Normalize the data

for(i in colnames(data)) {
  if(is.numeric(data[[i]])) {
    data[[i]] = scale(data[[i]]) # Scale the continuous value columns
  }
}

# Exploratory data analysis

hist(data$revenue, col="pink", xlab="Revenue", ylab="Count", main="Revenue Histogram")
ggqqplot(data$revenue) # Best fit line for age

# QQ-Plot to check if the data is normal

qqnorm(data$revenue)
qqline(data$revenue)

# Correlation plot

corrplot(cor(data[, ..numeric_columns], use="na.or.complete"), method="number")

# One hot encoding for categorical string columns

dummy = dummyVars(" ~ .", data=data)
data = data.frame(predict(dummy, newdata = data)) 

# Checking condition for regression

# 1. Checking if linear regression is linear in parameters

input_columns = names(data[,1:ncol(data)-1])
input_form = paste(input_columns, collapse="+")
formula = as.formula(paste("revenue ~ ", input_form))
mod <- glm(formula=formula, data=data)
summary(mod)

# 2. The mean of residuals is zero

mean(mod$residuals)

# 3. Homoscedasticity of residuals or equal variance

par(mfrow=c(2,2))
plot(mod)

# 4. No autocorrelation of residuals

acf(mod$residuals)

# 5. The X variables and residuals are uncorrelatedThe X variables and residuals are uncorrelated

checkCorrelationWithMod = function(X) {
  print(cor.test(X, mod$residuals))
}

lapply(data, checkCorrelationWithMod)

# 6. The number of observations must be greater than number of Xs

nrow(data) > ncol(data)

# 7. Variability of X

checkVariate = function(X) {
  print(var(X))
}

lapply(data, checkVariate)

# 8. Check if X and Y have inverse relationship ( Does not hold true here)

for(i in names(data)) {
  if( i != "target") {
    plot(data[[i]], data$Class, xlab = i)
  }
}

# Shuffle the data

set.seed(1000)
data = data[sample(nrow(data), replace = T),]
head(data)

# Train Test Split

smp_size= floor(0.8 * nrow(data))

set.seed(123)
train_ind = sample(seq_len(nrow(data)), size = smp_size)

train = data[train_ind, ]
test = data[-train_ind, ]

train$target = as.factor(train$revenue)
test$target = as.factor(test$revenue)

# Logistic Regression
step(lm(formula = formula,data=train),direction="both") # Forward selection and backward elimination

model.logistic = glm(revenue ~ P1 + P2 + P4 + P5 + P7 + P8 + P15 + P17 + 
                       P18 + P19 + P20 + P21 + P22 + P23 + P24 + P25 + P26 + P28 + 
                       P29 + P32 + P34 + P35 + P36 + P37, data=train, family = 'gaussian')

print(model.logistic)
pred.logistic = predict(model.logistic, test, type = "response")
rmse(test$revenue, pred.logistic)
mae(test$revenue, pred.logistic)
