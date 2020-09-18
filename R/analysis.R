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

# https://cran.r-project.org/web/packages/data.table/vignettes/datatable-intro.html

## DT[i, j, by]

##   R:       i                 j        by
## SQL:  where | order by   select | update  group by

dt = fread("/Users/apple/Downloads/forestfires.csv")
head(dt)

# Get information about data

str(dt)
dim(dt)

# Check if any data is null

anyNA(dt) # No data is null

# Get information about the month of March

dt[month=='mar']

# Get the mean of wind during sundays

mean(dt[day=='sun']$wind, na.rm=FALSE)

# Standardize the numerical columns

normalise_numeric = function(x) {
  if(!is.na(x) && is.numeric((x)))
    return(scale(x))
  return(x)
}

dt = dt[, lapply(.SD, normalise_numeric)] # .SD selects the subset of the dataset

# Get the mean of the data per day

dt[, mean(wind.V1), by=(day)]

# Count of records in dec

dt[month=='dec', .N]

# Maximum wind speed per month

dt[, .(max_speed = max(wind.V1, na.rm=TRUE)), by=.(month)]

# Maximum wind speed per month and day

dt[, .(max_speed = max(wind.V1, na.rm=TRUE)), by=.(month, day)]

# Get the last row

dt[.N]

# Get a X and Y

head(dt[, .(X.V1, Y.V1)])

# Range of X

range(dt[, .(X.V1)])

# Shuffle rows

set.seed(1000)
head(dt[sample(nrow(dt), replace = T),])

# Number of observations of month

dt[, .(.N), by=.(month)]

# Select columns that starts_with D

select(dt, starts_with('D'))

# Select columns that does not start with D

select(dt, -starts_with('D'))

# Select columns that does not contain V1

select(dt, -contains('V1'))

# Frequency of count per day

xtabs(~day, data=dt)

# Row Percentage of day

rowPerc(xtabs(~day, data=dt))

# Frequency of count per day and month

xtabs(~day+month, data=dt)

# Row Percentage of Days and Month count

rowPerc(xtabs(~day+month, data=dt))

# Statistical Analysis on column wind

favstats(dt$wind.V1)

# Get the month and day having max wind

dt[wind.V1 == max(dt$wind.V1), .(month, day)]

## Refer to statistical analysis PDF

# Get relative frequency of month

xtabs(~month, data=dt) /dt[, .N]

# Barchart of months

colors = c("red", "green", "blue")

barplot(xtabs(~month, data=dt), col=colors)

# Piechart of days

pie(xtabs(~day, data=dt))

# Find the mean of wind for month march

dt[month=='mar', .(mean_of_wind = mean(wind.V1, na.rm = TRUE))]

# Frequency distribution of wind

range_of_wind = range(dt$wind.V1)
min_wind = range_of_wind[1]
max_wind = range_of_wind[2]

sequence = seq(min_wind, max_wind, (max_wind-min_wind)/10) # Separate them into 10 bins
separated_data = cut(dt$wind.V1, sequence, right=FALSE)
table(separated_data)

# Convert frequency distribution to a column format

cbind(table(separated_data))

# Barchart of wind

barplot(table(separated_data))

# Histogram of wind

hist(dt$wind.V1, right=FALSE, col = colors)

# Relative frequency of wind

table(separated_data) / dt[, .N]

# Cumulative freuency of wind

cumsum(table(separated_data))

# Plot the cumulative frequency graph for wind

cumulative_sum = c(0, cumsum(table(separated_data))) # Add 0 as initial point

plot(sequence, cumulative_sum)
lines(sequence, cumulative_sum) # Join the lines

# Cumulative relative frequency distribution and plotting

cumsum(table(separated_data)) / dt[, .N]

cum_rel_sum = c(0, cumsum(table(separated_data)) / dt[, .N])
plot(sequence, cum_rel_sum)
lines(sequence, cum_rel_sum)

# Stem of X

stem(dt$X.V1)

# Scatter plot of X and Y

plot(dt$X.V1, dt$Y.V1)
abline(lm(dt$X.V1~dt$Y.V1))

# Mean, Median of X

dt[, .(mean = mean(dt$X.V1), median = median(dt$X.V1))]

# 10, 34, 56,88 Percentile of X column

quantile(dt$X.V1, c(.10, .34, .56, .88))

# Range of Y

range(dt$Y.V1)

# Interquartile range of Y

IQR(dt$Y.V1)

# Boxplot of wind for mar sep

march_data = dt[month=='mar', .(wind.V1)]$wind.V1
sep_data = dt[month=='sep', .(wind.V1)]$wind.V1
boxplot(march_data, sep_data)

# Variance of X : How data is dispersed around the mean

var(dt$X.V1)

# Standard deviation of X : Square root of variance || How data is spread from the mean

sd(dt$wind.V1)

# Covariance of X and Y

cov(dt$X.V1, dt$Y.V1)

# Correlation of X and Y

cor(dt$X.V1, dt$Y.V1)

# Find the 16th central moment of wind

moment(dt$wind.V1, center = TRUE, order = 16)

# Skewness of wind

skewness(dt$wind.V1) # Skewed to the right

# Visualise the skewness

hist(dt$wind.V1, breaks = 15)

# Kurtosis of wind

kurtosis(dt$wind.V1)

# “Covariance” indicates the direction of the linear relationship 
# between variables. “Correlation” on the other hand measures both the strength 
# and direction of the linear relationship between two variables.

# Pearson Kendall and Spearman Coefficient

cor(dt$X.V1, dt$Y.V1, method=c('kendall'))
cor(dt$X.V1, dt$Y.V1, method=c('pearson'))
cor(dt$X.V1, dt$Y.V1, method=c('spearman'))

# Get the correlation coefficient and p-value

cor.test(dt$X.V1, dt$Y.V1, method=c('kendall'))

# Visualise the correlation using scatter plot

ggscatter(dt, x='X.V1', y='Y.V1', add='reg.line',
          conf.int = TRUE, cor.coef = TRUE, cor.method = 'pearson',
          xlab = 'X', ylab = 'Y')
cor.test(dt$X.V1, dt$Y.V1, method=c('pearson'))
cor.test(dt$X.V1, dt$Y.V1, method=c('spearman'))

# Check if X and Y are normal

shapiro.test(dt$X.V1) # W = 0.93757, p-value = 6.707e-14 || Since p val < 0.05, data is not normal
shapiro.test(dt$Y.V1)

shapiro.test(seq(1,100,2))

# Visually check if X and Y are normal from QQ plot

ggqqplot(dt$X.V1)
ggqqplot((seq(1,100,2)))
