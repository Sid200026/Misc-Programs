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

# 1

dt = fread("/Users/apple/Downloads/Data.csv")
head(dt)

# 2

xtabs(~Gender, data=dt)/dt[,.N]

# 3

gender_table = dt[, .N, by=.(Gender)]
gender_table[N==max(N), .(Gender)]

# 4 ( Since YOA was already present in the table, YOA2 is used)
regno = dt$Register_No
yoa2 = substr(regno, 1, 2)
dt = dt[, .(Register_No, Student_Name, Gender, School, DOB, Program, Initial, YOA, Age, YOA2 = yoa2)]

# 5

# Frequency of year of admission

xtabs(~YOA, data=dt)

# Relative frequency of year of admission

xtabs(~YOA, data=dt)/dt[, .N]

# 6

school <- dt$School
year_of_admission <- dt$YOA
total_count <- rep(1, length(school))
data <- data.frame(school,year_of_admission,total_count)

ggplot(data, aes(fill=year_of_admission, y=total_count, x=school)) + geom_bar(position="stack", stat="identity")

# 7

#SCOPE has most admissions over the course of 4 years followed by SENSE and then a equal number of admissions in SELECT and SENSE.
#In 2013, SENSE had more admissions. SMEC had no admissions
#In 2017, SCOPE had more admissions. SMEC had no admissions
#In 2018, SENSE had more admissions. SMEC and SELECT had no admissions.
#In 2019, SMEC and SCOPE had same admissions. SENSE did not have any admission.

# 8

# Percentage stacked bar plot

ggplot(data, aes(fill=year_of_admission, y=total_count, x=school)) + 
  geom_bar(position="fill", stat="identity")

# 9

#From the above plot, we can visualise how the admission is distributed over the years for each school. In the earlier stacked bar chart, only the frequency was taken into consideration. So we could compare the on the basis of the admission count for different schools. In a percentage stacked bar chart, we can visualise for each school how the admision number is distributed.

# 10

dt = select(dt, -starts_with('YOA')) # Will drop both YOA and YOA2
head(dt)
