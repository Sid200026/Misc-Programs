library(knitr)
library(dplyr)
library(data.table)
library(stringr)
library(lubridate)
library(tidyr)
library(ggplot2)
#library(tigerstats)

packageVersion("data.table")

data = read.csv("/home/siddharth/Desktop/Misc-Programs/R/titanic.csv")

# Display Some information

head(data)

# Display the structure of the dataset

str(data)

# Find information about all the survived passengers

filter(data, Survived==1)

# Number of Females that survived

nrow(filter(data, Survived == 1, Sex == 0))

# Check if Sex is missing for any data

filter(data, is.na(Sex))

# Sort the data by age. If Same, then sort by Fare

arrange(data, Age, desc(Fare))

# Select columns that start with F

select(data, starts_with("F"))

# Select all columns that do not start with A and F

select(data, -starts_with("F"), -starts_with("A"))

# Select columns that contains 'as'

select(data, contains('as'))


# Reading the csv file as a data.table

dt = fread('https://raw.githubusercontent.com/selva86/datasets/master/Cars93_miss.csv')
head(dt)
typeof(dt)

# Read only the first 3 rows

fread('/home/siddharth/Desktop/Misc-Programs/R/titanic.csv', nrows=3)

# Only import Sex and Age

fread('/home/siddharth/Desktop/Misc-Programs/R/titanic.csv', select=c('Sex', 'Age'))

# Get number of rows and columns in the data.table

nrow(dt)
ncol(dt)

# Get datatype and summary statistics

sapply(dt, class)
summary(dt)

# Get all column names

colnames(dt)

# Get Manufacturer, Model and Type has the highest price

dt[Price == max(Price, na.rm=TRUE)][,list(Manufacturer, Model, Type)]
# Alternative
select(filter(dt, Price == max(dt$Price, na.rm = TRUE)), Manufacturer, Model, Type)

# Rename RPM to RevolutionsPerMinute

colnames(dt)[14] = 'RevolutionsPerMinute'
colnames(dt)

# Revert the change

dt = rename(dt, c("RPM" = "RevolutionsPerMinute"))
colnames

# Check if any data is missing

anyNA(dt)

is.na(dt)

# Get column and row number of missing values

for(i in 1:nrow(dt)) {
  for(j in 1:ncol(dt)) {
    if(is.na(dt[i,j,with=F][1])) {
      print(paste("Row :", i, "Column : ", j, sep=" "))
    }
  }
}

# Number of missing values in each column

for(i in colnames(dt)) {
  print(paste("Column :", i, "Missing Values :", sum(is.na(dt[, ..i])), sep=" "))
}

# Replace all missing values with 0
copy = dt
dt[is.na(dt)] = 0
anyNA(dt)

dt = copy
replace_with_mean <- function(x){ifelse(is.na(x) && is.numeric(x),mean(x, na.rm = TRUE),x)}

replace_mean = function(x) {
  if(is.na(x) && is.numeric((x)))
    return(mean(x, na.rm=TRUE))
  return(x)
}

# Same functions

output <- lapply(dt, replace_mean)
anyNA(output)

# Ignore Missing Values

dt = copy
anyNA(dt)

dt = dt[,na.omit(dt)]
anyNA(dt)
dt

dt = copy
# Mean of all vehicles having price > 30

mean(filter(dt, Price>30)$Price, na.rm=TRUE)

# Cars under each manufacturer

dt[, .(.N), by = Manufacturer]

# Calculate mean Price for every Manufacturer, Type combination in DT Order by Type

dt[, mean(Price), by = .(Manufacturer, Type)][order(Type)]

# Get numeric columns

colnames(select(dt, where(is.numeric)))

# Remove a column
colnames(select(dt, -'Width'))

# Get all rows where AirBags are Driver & Passenger & No data.

filter(dt, AirBags %in% c('Driver & Passenger', 'No data'))

# Get last row

dt[.N]

# Get SD of price for every manufacturer

dt[, .(Manufacturer, SD=sd(Price, na.rm = TRUE))]

# Calculate mean for every manufacturer but exclude mid size

dt[Type != "MidSize", .(Mean=mean(Price, na.rm = TRUE), by=Manufacturer)]

# Number of Airbag categories

dt[, .(Categories = length(AirBags), by=Manufacturer)]

# Range of a particular column

range(dt$Price, na.rm = TRUE)

# Get one-hot encodings for columns Gender & Degree in the data.table DT and append it as columns.

DT <- data.table(Gender = c("M","M","F","F"), E_Id =c(1,2,3,4), Degree = c("UG","PG","PhD","UG") )

output <- dcast(melt(DT, id.vars='E_Id'), E_Id ~ variable + value, fun = length)

output

# Compute the correlation score

output <- dt[, .SD, .SDcols = which(sapply(dt, is.numeric))]
cor(output, use = "na.or.complete")

# Normalize columns

DT <- data.table(V1= runif(10, 1, 100), V2 =runif(10, 1, 80), V3 = runif(10, 1, 100))

output <- DT[, lapply(.SD, scale)]
output

# Shuffle Rows

set.seed(1000)
dt[sample(nrow(dt), replace = T),]

dt<-fread('https://raw.githubusercontent.com/code4kunal/eda-with-python/master/Automobile%20(1).csv')
head(dt)
copy = dt

# Dimensions

dim(dt)

# Replace Fuel Type gas with Petrol

dt$fuel_type
dt$fuel_type[dt$fuel_type=='gas'] = 'petrol'
dt$fuel_type

# Count missing values
dt
sum(is.na(dt))

# Finding rows with city_mpg==21

filter(dt, city_mpg==21)

# Histogram of engine_size

hist(dt$engine_size)

colnames(data)

xtabs(~Sex, data=data)
#rowPerc(xtabs(~Age, data=data))
#rowPerc(xtabs(~Age+Sex, data=data))
#favStats(data$Sex)