library(knitr)
library(dplyr)
library(data.table)
library(stringr)
library(lubridate)
library(tidyr)
library(ggplot2)
library(tigerstats)
library(corrplot)

data = read.csv("/Users/apple/Documents/Misc-Programs/R/titanic.csv")
head(data)

# Assumption 1

print("A regression model is linear in parameter. This means that a model is linear when each term is either a constant or the product of a parameter and a predictor.A linear equation is constructed by adding the results for each term.")

# Assumption 2

# Value is almost 0 ie. mean residuals is 0

mod <- lm(Cabin ~ Sex, data=data)
mean(mod$residuals)

# Assumption 3

# Homoscedasticity of residuals or equal variance

par(mfrow=c(2,2))
mod_1 <- lm(Cabin ~ Sex, data=data)
plot(mod_1)

# Assumption 4

# No autocorrelation of residuals

lmMod <- lm(X ~ Cabin, data=data)
acf(lmMod$residuals)

# Assumption 5

# Cabin and Survived is uncorrelated

mod.lm <- lm(Cabin ~ Survived, data=data)
cor.test(data$Survived, mod.lm$residuals)

# Assumption 6

print("The number of observations must be greater than number of Xs. This can be directly observed by looking at the data.")

# Assumption 7

# The variance of Cabin is positive

var(data$Cabin)  

# Assumption 8

print("This means that if the Y and X variable has an inverse relationship, the model equation should be specified appropriately.")

# Assumption 9

# No perfect multicollinearity

mod2 <- lm(Cabin ~ ., data=data)
corrplot(cor(data[, -1]))

# Assumption 10

# Normality of residuals

par(mfrow=c(2,2))
mod <- lm(Cabin ~ Survived, data=data)
plot(mod)
