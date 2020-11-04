data_path = "/Users/apple/Downloads/Concrete_Data.csv"

# Name : Siddharth Singha Roy
# Reg No. : 18BCE1065
# Faculty : Prof TULASI PRASAD SARIKI

# File was initially converted to csv from xls using bash script because OSX
# does not have proper support for csv

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
library(readxl)
library(ggpubr)
library(BBmisc)

#
# 1. Read the dataset into the R environment
#

data = fread(data_path, check.names = TRUE)
head(data)

#
# 2. Descriptive Analysis
#

# Structure of the data

str(data)

# Column names

column_names = names(data)
target_column = column_names[length(column_names)]
input_column = column_names[1:length(column_names)-1]
column_names
target_column
input_column

# Dimension of data
dim(data)

# Data Preprocessing

# Convert character columns to numeric

convertToNumeric = function(X) {
  X1 = as.numeric(X)
  return(X1)
}

data = data[, lapply(.SD,convertToNumeric)]

# Check for null values

colSums(is.na(data)) # -> No null values

# Histogram for numerical data

par(mfrow=c(3,3))
for(name in names(data)) {
  X = data[[name]]
  print(name)
  print(summary(X))
  hist(X, main=name)
}

par(mfrow=c(1,1))

# Density plot for target variable

ggdensity(data, x = "Concrete.compressive.strength.MPa..megapascals..", 
          fill = "#0073C2FF", color = "#0073C2FF",
          add = "mean", rug = TRUE)

# Boxplot for input columns

for(name in input_column) {
  boxplot(data[[name]], main=name)
}

# QQ Plot for input columns against target column

for(name in input_column) {
  qqplot(data[[name]], data$Concrete.compressive.strength.MPa..megapascals.., xlab=name)
}

# Analysis on each column

## Column Cement..component.1..kg.in.a.m.3.mixture.

a = ggplot(data, aes(x = Cement..component.1..kg.in.a.m.3.mixture.))

a + geom_density() +
  geom_vline(aes(xintercept = mean(Cement..component.1..kg.in.a.m.3.mixture.)), 
             linetype = "dashed", size = 0.6)

a + geom_histogram(bins = 30, color = "black", fill = "gray") +
  geom_vline(aes(xintercept = mean(Cement..component.1..kg.in.a.m.3.mixture.)), 
             linetype = "dashed", size = 0.6)

## Column Blast.Furnace.Slag..component.2..kg.in.a.m.3.mixture.

a = ggplot(data, aes(x = Blast.Furnace.Slag..component.2..kg.in.a.m.3.mixture.))

a + geom_density() +
  geom_vline(aes(xintercept = mean(Blast.Furnace.Slag..component.2..kg.in.a.m.3.mixture.)), 
             linetype = "dashed", size = 0.6)

a + geom_histogram(bins = 30, color = "black", fill = "gray") +
  geom_vline(aes(xintercept = mean(Blast.Furnace.Slag..component.2..kg.in.a.m.3.mixture.)), 
             linetype = "dashed", size = 0.6)

## Column Fly.Ash..component.3..kg.in.a.m.3.mixture.

a = ggplot(data, aes(x = Fly.Ash..component.3..kg.in.a.m.3.mixture.))

a + geom_density() +
  geom_vline(aes(xintercept = mean(Fly.Ash..component.3..kg.in.a.m.3.mixture.)), 
             linetype = "dashed", size = 0.6)

a + geom_histogram(bins = 30, color = "black", fill = "gray") +
  geom_vline(aes(xintercept = mean(Fly.Ash..component.3..kg.in.a.m.3.mixture.)), 
             linetype = "dashed", size = 0.6)

## Column Water...component.4..kg.in.a.m.3.mixture.

a = ggplot(data, aes(x = Water...component.4..kg.in.a.m.3.mixture.))

a + geom_density() +
  geom_vline(aes(xintercept = mean(Water...component.4..kg.in.a.m.3.mixture.)), 
             linetype = "dashed", size = 0.6)

a + geom_histogram(bins = 30, color = "black", fill = "gray") +
  geom_vline(aes(xintercept = mean(Water...component.4..kg.in.a.m.3.mixture.)), 
             linetype = "dashed", size = 0.6)

## Column Superplasticizer..component.5..kg.in.a.m.3.mixture.

a = ggplot(data, aes(x = Superplasticizer..component.5..kg.in.a.m.3.mixture.))

a + geom_density() +
  geom_vline(aes(xintercept = mean(Superplasticizer..component.5..kg.in.a.m.3.mixture.)), 
             linetype = "dashed", size = 0.6)

a + geom_histogram(bins = 30, color = "black", fill = "gray") +
  geom_vline(aes(xintercept = mean(Superplasticizer..component.5..kg.in.a.m.3.mixture.)), 
             linetype = "dashed", size = 0.6)

## Column Fine.Aggregate..component.7..kg.in.a.m.3.mixture.

a = ggplot(data, aes(x = Fine.Aggregate..component.7..kg.in.a.m.3.mixture.))

a + geom_density() +
  geom_vline(aes(xintercept = mean(Fine.Aggregate..component.7..kg.in.a.m.3.mixture.)), 
             linetype = "dashed", size = 0.6)

a + geom_histogram(bins = 30, color = "black", fill = "gray") +
  geom_vline(aes(xintercept = mean(Fine.Aggregate..component.7..kg.in.a.m.3.mixture.)), 
             linetype = "dashed", size = 0.6)

## Column Age..day.

a = ggplot(data, aes(x = Age..day.))

a + geom_density() +
  geom_vline(aes(xintercept = mean(Age..day.)), 
             linetype = "dashed", size = 0.6)

a + geom_histogram(bins = 30, color = "black", fill = "gray") +
  geom_vline(aes(xintercept = mean(Age..day.)), 
             linetype = "dashed", size = 0.6)

#
# 3. Perform required Diagnostic data analytics on the explored dataset.
#

# Correlation Coefficients

cor(select_if(data, is.numeric)[,])

# Correlation Plot

M = cor(select_if(data, is.numeric))
corrplot(M, method = "number", tl.pos='n') # Due to large size of column names, they are removed

# Statistical Analysis

favstats(~Cement..component.1..kg.in.a.m.3.mixture., data=data)
favstats(~Blast.Furnace.Slag..component.2..kg.in.a.m.3.mixture., data=data)
favstats(~Fly.Ash..component.3..kg.in.a.m.3.mixture., data=data)
favstats(~Water...component.4..kg.in.a.m.3.mixture., data=data)
favstats(~Superplasticizer..component.5..kg.in.a.m.3.mixture., data=data)
favstats(~Coarse.Aggregate...component.6..kg.in.a.m.3.mixture., data=data)
favstats(~Fine.Aggregate..component.7..kg.in.a.m.3.mixture., data=data)
favstats(~Age..day., data=data)
favstats(~Concrete.compressive.strength.MPa..megapascals.., data=data)

summary(data)

# Normalise the data

data = normalize(data, method = "standardize", range = c(0, 1), margin = 1L, on.constant = "quiet")

#
# 4. Check for the assumptions of Regression on the loaded dataset.
#

# Assumption 1 : Checking if linear regression is linear in parameters

input_form = paste(input_column, collapse="+")
formula = as.formula(paste("Concrete.compressive.strength.MPa..megapascals.. ~ ", input_form))

mod <- lm(formula=formula, data=data)
summary(mod)

# Assumption 2 : The mean of residuals is zero -> Holds

mean(mod$residuals)

# Assumption 3 : Homoscedasticity of residuals or equal variance -> Holds
par(mfrow=c(2,2))
plot(mod)
par(mfrow=c(1,1))
# Assumption  4 : No autocorrelation of residuals -> Holds
acf(mod$residuals)

# Assumption 5 : Input and Target columns are uncorrelated -> Holds

checkCorrelationWithMod = function(X) {
  print(cor.test(X, mod$residuals))
}

lapply(data, checkCorrelationWithMod)

# Assumption 6 : The number of observations must be greater than number of Xs -> Holds

nrow(data) > ncol(data)

# Assumption 7 : Variability of X -> Holds

checkVariate = function(X) {
  print(var(X))
}

lapply(data, checkVariate)

# Assumption 8 : Check if X and Y have inverse relationship -> Does not hold for Age..dat column

for(i in input_column) {
  plot(data[[i]], data$Concrete.compressive.strength.MPa..megapascals.., xlab = i)
}

# Assumption 9 :-No perfect multicollinearity -> Does not hold

vif(mod)

# Assumption 10:-Normality of residuals

par(mfrow=c(2,2))
plot(mod)
par(mfrow=c(1,1))

#
# 5. Split the whole dataset into training (80%) and testing (20%).
#

dt = sort(sample(nrow(data), nrow(data)*.8))
train<-data[dt,]
test<-data[-dt,]

#
# 6. Design a predictive model for predicting the target attribute from training data.
#

model = lm(Concrete.compressive.strength.MPa..megapascals..~., data=train)
sigma(model)

summary(model)$coef

#
# 7. Apply the designed model on test data.
#

pred = model%>%predict(test)
summary(model)

actual = test$Concrete.compressive.strength.MPa..megapascals..
predicted = pred

range(test$Concrete.compressive.strength.MPa..megapascals..)

#
# 8. Evaluate the designed model by means of RMSE or MAE.
#

rmse(actual, predicted) # In the target range -1.7 to 2.8, our model can accurately predict with an error boundary of 0.6
mae(actual, predicted)
