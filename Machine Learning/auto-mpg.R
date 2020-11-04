data_url = "https://archive.ics.uci.edu/ml/machine-learning-databases/autos/imports-85.data"

library(data.table)
library(ggplot2)
library(stats)
library(tigerstats)
library(ggplot2)
library(corrplot)
library(dplyr)
library(caret)
library(car)
library(Metrics)

# 
# Importing the data into the R environment
# 

# Read the csv file and display the first few columns

data = fread(data_url, sep=",")
head(data)

# Structure of data

str(data)

# Column names

names(data)

# Dimension of data

dim(data)

# 
# Data Preprocessing
#

# Convert real number column to numeric data type

data$V1 = as.numeric(data$V1)
data$V2 = as.numeric(data$V2)
data$V14 = as.numeric(data$V14)
data$V17 = as.numeric(data$V17)
data$V19 = as.numeric(data$V19)
data$V20 = as.numeric(data$V20)
data$V21 = as.numeric(data$V21)
data$V22 = as.numeric(data$V22)
data$V23 = as.numeric(data$V23)
data$V24 = as.numeric(data$V24)
data$V25 = as.numeric(data$V25)
data$V26 = as.numeric(data$V26)

# Checking for null values in every column

colSums(is.na(data))

# Removing the rows in which the target column ie. V26 is NA

data = data[!is.na(data$V26),]

# Replacing other NA with mean of that column

isNACharacter = function(X) {
  return(X=="?")
}

replaceNaWithMeanOrMode = function(X) {
  if(!any(is.na(X))) {
    if(is.character(X)) {
      X_mode = replace(X, isNACharacter(X), names((sort(-table(X)))[1]))
      return(X_mode)
    } else {
      return(X)
    }
  } else {
    X_mean = replace(X, is.na(X), mean(X, na.rm = TRUE))
    return(X_mean)
  }
}

data = data[, lapply(.SD, replaceNaWithMeanOrMode)]
colSums(is.na(data)) # Checking if all null values have been removed

# Distribution of categorical data

for(name in names(data)) {
  X = data[[name]]
  if(!is.double(X)) {
    distribution = xtabs(formula = as.formula(paste("~", name)), data=data)
    rowPercentage = rowPerc(distribution)
    print(distribution)
    print(rowPercentage)
    pie(distribution, main=name, radius=1)
  }
}

# Histogram of numerical column and summary

for(name in names(data)) {
  X = data[[name]]
  if(!is.character(X)) {
    print(name)
    print(summary(X))
    hist(X, main=name)
  }
}

# Advanced Exploration of the dataset

xtabs(~V3+V9, data=data)

plot(data$V1, data$V26)
plot(data$V2, data$V26)

boxplot(data$V2)

qqplot(data$V1, data$V26)

ggplot(data) +
  aes(x = V26) +
  geom_density()


# Correlation Plot

cor(select_if(data, is.numeric)[,])

M = cor(select_if(data, is.numeric))
corrplot(M, method = "number")

favstats(~V1, data=data)

densityplot(~V2,data=data,
            groups=V6,
            auto.key=TRUE)

summary(data)

# One Hot Encoding

dummy <- dummyVars(" ~ .", data=data)
newdata <- data.table(predict(dummy, newdata = data)) 

data = newdata

# Normalise the data

normalize <- function(x) {
  return ((x - min(x)) / (max(x) - min(x)))
}

data = data[, lapply(.SD, normalize)]

# Anova Test

residuals<-aov(V26~.,data=data)
summary.aov(residuals)

# Checking if linear regression is linear in parameters

data = data.table(data, check.names = TRUE)

column_names = names(data[,1:74])
input_form = paste(column_names, collapse="+")
formula = as.formula(paste("V26 ~ ", input_form))

mod <- lm(formula=formula, data=data)
summary(mod)

# The mean of residuals is zero
mean(mod$residuals)

# Homoscedasticity of residuals or equal variance
par(mfrow=c(2,2))
plot(mod)

# No autocorrelation of residuals
acf(mod$residuals)

# The X variables and residuals are uncorrelatedThe X variables and residuals are uncorrelated

checkCorrelationWithMod = function(X) {
  print(cor.test(X, mod$residuals))
}

lapply(data, checkCorrelationWithMod)

# The number of observations must be greater than number of Xs

nrow(data) > ncol(data)

# Variability of X

checkVariate = function(X) {
  print(var(X))
}

lapply(data, checkVariate)

# Check if X and Y have inverse relationship ( Does not hold true here)

for(i in names(data)) {
  if( i != "V26") {
    plot(data[[i]], data$V26, xlab = i)
  }
}

# No perfect multicollinearity

## Removing linearly dependent variables
ld.vars <- attributes(alias(mod)$Complete)$dimnames[[1]]
formula.new <- as.formula(
  paste(
    paste(deparse(formula), collapse=""), 
    paste(ld.vars, collapse="-"),
    sep="-"
  )
)

mod.new = lm(formula.new, data=data)

vif(mod.new)

# Split the whole dataset into training (80%) and testing (20%).
dt = sort(sample(nrow(data), nrow(data)*.8))
train<-data[dt,]
test<-data[-dt,]

# Prediction Model

model = lm(V26~., data=train)
sigma(model)

summary(model)$coef

options(warn=-1)
pred<-model%>%predict(test)
options(warn=1)

summary(model)

actual = test$V26
predicted = pred

range(data$V26)

rmse(actual, predicted)
mae(actual, predicted)
