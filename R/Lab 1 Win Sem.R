## NAME : Siddharth Singha Roy
## Reg No. : 18BCE1065
## Date : 1.2.21
## Lab - 1

##loading a built in data set from R.
library(MASS)
library(tigerstats)
library(ggplot2)


data(Cars93)

##Viewing the top 10 values of the data set.
head(Cars93,10)
## Viewing the structure of the dataset.
str(Cars93)

##Question 1: Mention the name of the categorical and its possiblevalues in your dataset.

##From unique(iris) we see that there are 5 variables and the 5th variable has categorical data.
str(Cars93)
## It has level 3. Hence there are 3 distinct values.
levels(Cars93$Origin)
levels(Cars93$Make)
levels(Cars93$Man.trans.avail)
levels(Cars93$AirBags)
levels(Cars93$DriveTrain)
levels(Cars93$Type)
levels(Cars93$Model)
levels(Cars93$Manufacturer)


##Question 2:Consider  each  categorical  variable  separately  (one  factor  variable)  and describe it using numeric measures.ie. Give the frequency of each variable in your dataset. Also, mention the percentage
table(Cars93$Origin)
rowPerc(xtabs(~Origin,Cars93))

table(Cars93$Make)
rowPerc(xtabs(~Make,Cars93))

table(Cars93$Man.trans.avail)
rowPerc(xtabs(~Man.trans.avail,Cars93))

table(Cars93$AirBags)
rowPerc(xtabs(~AirBags,Cars93))

table(Cars93$DriveTrain)
rowPerc(xtabs(~DriveTrain,Cars93))

table(Cars93$Type)
rowPerc(xtabs(~Type,Cars93))

table(Cars93$Model)
rowPerc(xtabs(~Model,Cars93))

table(Cars93$Manufacturer)
rowPerc(xtabs(~Manufacturer,Cars93))


##Question 3: What is the distribution of each categorical variable, graphically depcit the same.
xtabs(~Origin,data=Cars93)
plot(Cars93$Origin)

xtabs(~Make,data=Cars93)
plot(Cars93$Make)

xtabs(~Man.trans.avail,data=Cars93)
plot(Cars93$Man.trans.avail)

xtabs(~AirBags,data=Cars93)
plot(Cars93$AirBags)

xtabs(~DriveTrain,data=Cars93)
plot(Cars93$DriveTrain)

xtabs(~Model,data=Cars93)
plot(Cars93$Model)

xtabs(~Type,data=Cars93)
plot(Cars93$Type)

xtabs(~Manufacturer,data=Cars93)
plot(Cars93$Manufacturer)

##Question 4: Contingency table of between variables.

##A.
##Making contengency table between two variables.
table1<-table(Cars93$Type, Cars93$Origin)
table2<-table(Cars93$Type,Cars93$AirBags)

table1
table2

##Pecentage from contengency tables.
prop.table(table(Cars93$Type, Cars93$Origin))
prop.table(table(Cars93$Type, Cars93$AirBags))

##B.Two way bar charts.
barplot(table1, ylab="Car_Type", xlab="Car_Origin", main="Side-By-Side Bar Chart", col=c("turquoise4", "turquoise2", "turquoise" ), beside=TRUE, width=.3)

barplot(table2, ylab="Car_Type", xlab="Air_Bags", main="Side-By-Side Bar Chart", col=c("turquoise4", "turquoise2", "turquoise" ), beside=TRUE, width=.3)

##Question 5: Mention the name of the numerical attributes and describe the following : mean, median,min ,max.
str(Cars93)

## FavStats of a few numeric variables.
favstats(Cars93$Min.Price)
favstats(Cars93$Weight)
favstats(Cars93$Price)

##Question 6: Analyse the spread of your data using different quantiles 20, 40, 60,80 and 90, considering all the numeric variables in your dataset. Also, give the IQR for the same variables. Infer the most spread out data in your dataset.

##For Min_Price Variable
quantile(Cars93$Min.Price,0.2)
quantile(Cars93$Min.Price,0.4)
quantile(Cars93$Min.Price,0.6)
quantile(Cars93$Min.Price,0.8)
quantile(Cars93$Min.Price,0.9)
IQR(Cars93$Min.Price)

##For Weight Variable.
quantile(Cars93$Weight,0.2)
quantile(Cars93$Weight,0.4)
quantile(Cars93$Weight,0.6)
quantile(Cars93$Weight,0.8)
quantile(Cars93$Weight,0.9)
IQR(Cars93$Weight)

##For Price Variable.
quantile(Cars93$Price,0.2)
quantile(Cars93$Price,0.4)
quantile(Cars93$Price,0.6)
quantile(Cars93$Price,0.8)
quantile(Cars93$Price,0.9)
IQR(Cars93$Price)

##Most spread out is weight variable.
##Question 7: Analyse your numerical variables graphically using different histograms 

##Histogram of a few numeric data.
hist(Cars93$Price)
hist(Cars93$Weight)
hist(Cars93$Min.Price)

##Question 8: Also,present  the  density  plot  of  all  the  numerical  variables  and  analyse  the distribution of your data. Is it symmetric?
##The peaks of a Density Plot help display where values are concentrated over the interval.

# Compute the density Price
dens <- density(Cars93$Price)
# plot density
plot(dens, frame = FALSE, col = "steelblue", 
     main = "Density plot of Price") 

##Most values are around 20 as the peak is near about value 20.
##NO the graph is not symmetric.

# Compute the density Weight
dens <- density(Cars93$Weight)
# plot density
plot(dens, frame = FALSE, col = "steelblue", 
     main = "Density plot of Weight")

##Most values are around 2500 as the peak is near about value 2500.
##NO the graph is not symmetric.

# Compute the density Min.Price
dens <- density(Cars93$Min.Price)
# plot density
plot(dens, frame = FALSE, col = "steelblue", 
     main = "Density plot of Min.Price") 
##Most values are around 18-20 as the peak is near about value 18-20
##NO the graph is not symmetric.

##Question 9: Use the appropriate plot to check for outliers and write the inference

##boxplots are also useful to detect potential outliers.

##A boxplot helps to visualize a quantitative variable by displaying five common location summary (minimum, median, first and third quartiles and maximum) and any observation that was classified as a suspected outlier using the interquartile range (IQR) criterion. 
##Variable Min_Price.
boxplot(Cars93$Min.Price,ylab = "Min_Price")
##Inference : Observations considered as potential outliers by the IQR criterion are displayed as points in the boxplot. Based on this criterion, there are 2 potential outliers (see the 4 points above the vertical line, at the top of the boxplot).

##Variable_Weight
boxplot(Cars93$Weight,ylab = "Weight")

##Inference: There are no outliers.

##Inference: There are no outliers.

## According  to  the  chosen  dataset,  analyse  your  data  combining  the  suitable categorical and numerical variables and present the ploti)by combining the histograms ii) by grouping the density plots.

# Histogram plot
ggplot(Cars93, aes(x=Passengers, fill = DriveTrain)) + geom_histogram(bins=100, alpha = 0.2, aes(y = ..density..), position = 'identity') + geom_bar(width=2)

# Density plot
ggplot(Cars93, aes(x=Passengers, fill = DriveTrain)) + geom_density(alpha = 0.2)
