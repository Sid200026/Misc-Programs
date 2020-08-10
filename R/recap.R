# Five basic or atomic classes of objects
# 
# 1. Character
# 2. Numeric
# 3. Integer
# 4. Complex
# 5. Logical
# 
# The most basic object is a vector.
# A vector can only contain objects of the same class. However a list which is also represented as a vector can
# contain objects of different classes.
# 
# Numbers in R are treated as double precision real number. To specify integer say 34, we use 34L
# 
# 1/0 returns infinity
# 0/0 returns NaN

x<-1
print(x) # [1] 1 -> Output. The [1] indicates that x is a vector and 1 is the first element

msg = "Hello"
msg

int_x = 3L
int_x

# Sequencing

x = 1:20 # Both are inclusive
x

# The c() function can be used to create vector of objects.

x = c(0.4,0.1)
x

x = c(0+4i, 2+3i)
x

x = c(TRUE, FALSE)
x

x = vector("numeric",length=10)
x

# Vectors needs to have elements of the same class. If we provide elements of different classes, then coercion
# occurs

y = c('a',TRUE)
y

b = c(0,TRUE)
b

# Objects can be explicitly coerced from one class to another using *.function

x = 0.6
class(x)
x = as.logical(x)
x

x = 0:6
class(x)
as.character(x)
as.complex(x)

# Coercion can also provide some erraneous result

x <- c("a", "b", "c")
x
as.numeric(x)

# MATRIX
# Data inside a matrix is entered column wise, so entries can be thought of starting in the upper-left
# corner and running down the columns.
# However this default behaviour can be overrided by setting byRow to true

x = matrix(nrow=3, ncol=2)
x

dimensions = dim(x)
dimensions

attributes(x)

x = matrix(1:6, nrow=2, ncol=3)
x

x = matrix(1:6, nrow=2, ncol=3, byrow = TRUE)
x

# We can create matrix from vectors as well

x = 1:10
dim(x) = c(2,5) # 2 rows, 5 columns, byrow = False
x

# We can also create a matrix from n>2 vectors using cbind or rbing

x = 1:5
y = 55:59
x
y
cbind(x,y)
rbind(x,y)

# Lists are a special type of vector that can contain elements of different classes.

x = list(1, "a", TRUE, 1+4i)
x

x[2]

# Factors are used to represent categorical data. Factor is an integer vector where each
# integer has a label
# Using factor with labels are better than having factors with integer data because they are self-describing

x = factor(c("yes", "no", "yes", "yes", "no", "yes"))
x
table(x)
unclass(x)

x = factor(c("yes", "no", "yes", "yes", "no", "yes"), labels=c("YES", "NO"))
x
table(x)
unclass(x)

# Missing values

# is.na() for missing values
# is.nan() to check if it is not a number

# NaN is NA but vice-versa is not true

x = c(1,2,3,4,5)
x
is.na(x)
is.nan(x)

x = c(1,NaN, NA, NA, 4)
x
is.na(x)
is.nan(x)

# Dataframes

# They are used to store tabular data. Each column needs to have the same length

# Unlike matrices, data frames can store different classes of objects in each column (just like lists);
# matrices must have every element be the same clas

# Data frames are usually created by calling read.table() or read.csv()
# Data frame can be converted into a matrix using data.matrix()

x = 1:5
y = c(TRUE, FALSE, NA, FALSE, FALSE)

x = data.frame(x,y)
x
is.na(x)
nrow(x)
ncol(x)
data.matrix(x)

# Naming a R object

# Every R object can have a name

x = 1:3
names(x)

names(x) = c("One", "Two", "Three")
x
names(x)

x <- list(a = 1, b = 2, c = 3)
x

m <- matrix(1:4, nrow = 2, ncol = 2)
m
dimnames(m) = list(c("R1", "R2"), c("C1","C2"))
m

# Identity Matrix

diag(5)

# Indexing

m <- matrix(1:4, nrow = 2, ncol = 2)
m

m[1,] # Row 1
m[,2] # Column 2
m[2,2] # Last element

# Sequencing

(0:10) * 2 # First 10 even numbers

(0:10) * (2) + 1 # First 10 odd numbers

# 1 2 4 8 16 32

2**(1:5)

(10:1)

1 + 1:10/10

# seq(from, to, by= )

seq(1,10,3)

seq(1,2,0.1)

# rep(x, times)

rep(5,5)

rep(c(5,7),2)

rep(c(1,2,3), 3, each=2)

rep(c(0.1, 0.9, 0.6)*-1, each=2)

# Arrays

# Arrays are the R data objects which can store data in more than two dimensions

v1 <- c(1,2,3)
v2 <- c(4,5,6,7,8,9)
A1 <- array(c(v1,v2),dim = c(3,3,2))
A1
A1[1,1,2]


vector1 <- c(5,9,3)
vector2 <- c(10,11,12,13,14,15)
# Take these vectors as input to the array.
array1 <- array(c(vector1,vector2),dim = c(3,3,2)) # Create two vectors of different lengths. vector3 <- c(9,1,0)
vector4 <- c(6,0,11,3,14,1,2,6,9)
array2 <- array(c(vector1,vector2),dim = c(3,3,2)) # create matrices from these arrays.
matrix1 <- array1[,,2]
matrix2 <- array2[,,2]
# Add the matrices.
result <- matrix1+matrix2; print(result)

x <- c("a", "b", "c", "c", "d", "a")
x
x[2:3]
x[x > "b"]

u <- x > "a"
u

# By default, when a single element of a matrix is retrieved, it is returned as a vector of
# length 1 rather than a 1 ?? 1 matrix. This behavior can be turned off by setting drop =
#   FALSE.

x <- list(foo = 1:4, bar = 0.6)
x$foo

x[u]

# [ always returns an object of the same class as the original; can be used to select
# more than one element (there is one exception)

# [[ is used to extract elements of a list or a data frame; it can only be used to
# extract a single element and the class of the returned object will not necessarily be
# a list or data frame

# $ is used to extract elements of a list or data frame by name; semantics are
# similar to hat of [[.

x <- c("a", "b", "c", "c", "d", "a")
x
x[1]
x[[1]]

x[1:3]
# x[[1:3]] : ERROR

x <- matrix(5:10, 2, 3)
x
x[1,2]
x[1,,drop=FALSE]
x[[2]]

lst = list(1,2,3)
lst[1:2]
lst[1]
lst[[1]]
lst

x <- list(foo = 1:4, bar = 0.6)
x[1]
x[[1]]
x$foo
x$bar
x["bar"]

x <- list(foo = 1:4, bar = 0.6, baz = "hello")
x[[2]]
x[c(1, 3)]
x[1:3]

x <- list(a = list(10, 12, 14), b = c(3.14, 2.81))
x[[c(1,3)]]
x[[1]][[3]]
x[[c(2, 1)]]

x <- list(ad = 1:5)
x[["a"]]
x[["a", exact=FALSE]]
x[["ad"]]

# Removing NA Values

x <- c(1, 2, NA, 4, NA, 5)
x[!is.na(x)]

x <- c(1, 2, NA, 4, NA, 5)
y <- c("a", "b", NA, "d", NA, "f")
good = complete.cases(x,y)
good
x[good]
y[good]

airquality[1:6,]
good = complete.cases(airquality)
airquality[good, ][1:6, ]

# Vectorized Operations

x <- matrix(1:4, 2, 2); y <- matrix(rep(10, 4), 2, 2)
x
y

x*y # Element wise multiplication
x %*% y # Matrix multiplication 

count <- 0
while(count < 10) {
  print(count)
  count <- count + 1
}

n = readline(prompt="Enter n");
fac = 1
for(i in 1:n) {
  fac = fac * i
}
fac

x <- c("a", "b", "c", "d")
for(i in 1:4) {
  print(x[i])
}
for(i in seq_along(x)) {
  print(x[i])
}
for(letter in x) {
  print(letter)
}
for(i in 1:4) print(x[i])

x <- matrix(1:6, 2, 3)
for(i in seq_len(nrow(x))) {
  for(j in seq_len(ncol(x))) {
    print(x[i, j])
  }
}

i = 0
repeat {
  i = i+1
  if(i==3) {
    break;
  }
  print(i)
}

if(i>2) {
  print("I is greater than 2")
} else {
  print("I is less than or equal to 2")
}

Scores = c(36, 42, 31, 85, 22, 90, 72, 68, 42, 85, 25)
max(Scores)

a = c(1,2,3,4,5)
b = c(4,5,6,7)
union(a,b)
intersect(a,b)
setdiff(a,b)
sort(Scores, decreasing = TRUE)
resp = match(12,a)
if(is.na(resp)) {
  print("-1")
} else {
  print(resp)
}
length(Scores)


my_vector <- c (28, 29, NA, 75, NA, 55, 67)
my_vector
my_vector = my_vector[!is.na(my_vector)]
my_vector

my_vector <- c (28, 29, NA, 75, NA, 55, 67)
my_vector = replace(my_vector, is.na(my_vector), 12)
my_vector

my_vector <- c (28, 29, NA, 75, NA, 55, 67)

# Count the number of NA in a vector
length(which(is.na(my_vector)))
na.omit(my_vector)

Name <- c("Rohan","Lakshmi")
Age <- c(21,20)
Number<-c("18BCE1200","18BCE1201")
my_df <- data.frame(Number,Name,Age)
my_df

names(my_df) # Column names
nrow(my_df)
ncol(my_df)
length(my_df) # returns length of the list, same as ncol()
dim(my_df)
str(my_df) # String is treated as factors || Displays the structure

df1 <- data.frame("Number" = c("18BCE1202","18BCE1203") , "Age" = c(21,20), "Name" = c("Keshav","Jivitesh"), stringsAsFactors = FALSE)
str(df1)

df2 <- data.frame(c("18BCE1204","18BCE1205") ,c(21,20), c("Ankit","Sruti"), stringsAsFactors = FALSE)
names(df2) = c("Number", "Age", "Name")


x <- df2["Name"]
y <- df2$Name
z <- df2[["Name"]]
w <- df2[[3]]

x
y
z
w
class(x)
class(y)
class(z)
class(w)

# Accessing with [[ or $ is similar. However, it differs for [ in that, 
# indexing with [ will return us a data frame 
# but the other will reduce it into a vector.

df2
df2$Name
df2[[1]]
df2
df2[1:2, 1:2]

big_df <- rbind(my_df,df1,df2)
big_df

big_df = cbind(big_df, Gender = c("F","M","F","M", "M", "F"))
big_df

big_df$Gender <- NULL
big_df
big_df$Gender<-c("M","F","M","M","M","F")
big_df

big_df <- big_df[-1,]
big_df

df = read.csv("https://raw.githubusercontent.com/datasciencedojo/datasets/master/titanic.csv")
df[1:6,]

library(dplyr)
sample_n(df,3) # Select 3 random rows

df
distinct(df) # Distinch for each column

names(df) # Get all column names

dim(df)
x2 = distinct(df, Sex, .keep_all= TRUE) # Distinct for a particular column
dim(x2)

mydata = select(df, Sex, Fare) # Select particular columns
mydata[1:6,]

df

# Dropping Variables
# Use select with - sign before columns

mydata = select(df, -Sex, -Fare) # Select particular columns
mydata[1:6,]

my = select(df, starts_with("a"));
my

# Selecting or Dropping Variables starts with 'Y'
# 
# mydata3 = select(mydata, starts_with("Y"))
# 
# mydata4 = select(mydata, -starts_with("Y"))

# Other functions
# ends_with() 	Ends with a prefix
# contains() 	Contains a literal string
# matches() 	Matches a regular expression
# num_range() 	Numerical range like x01, x02, x03.
# one_of() 	Variables in character vector.
# everything() 	All variables.
df
my = select(df, contains("a")); my
big_df
big_df = select(big_df, Gender, everything()) # Rearrange columns
big_df

big_df = rename(big_df, Sheks=Gender)
names(big_df)

big_df

big_df = filter(big_df, Sheks == 'F')
big_df

big_df = filter(big_df, Age %in% 30:38) # Multiple selection criteria
big_df

summarise(big_df)

df
names(df)
summarise(df, Age_Mean = mean(Age), Fare_Median=median(Fare))

library(nycflights13)

str(flights)
names(flights)
flights[1:2,]
class(flights)
filter(flights, arr_delay >= 120)

filter(flights, dest %in% c("HOU", "IAH"))
filter(flights, is.na(dep_time))

arrange(flights, desc(dep_delay)) # Sorting of dataframe

select(flights, starts_with("d"))

# DATES

# POSIXct is an integer based storage method ??? stores date/time values as number of seconds since January 1, 1970
# POSIXlt is a component based storage method ??? stores them as list with elements second, minute, hour, day, month, and year

date()
as.Date("28/09/20", format="%d/%m/%Y")
as.POSIXct("2020-8-5")
as.POSIXlt("2020-8-5 20:30:41")

Sys.Date()

d = as.Date("2020-8-7")
d
weekdays(d)
d+5
weekdays(d+5)

dt <- seq(d,by="2 months",length.out = 6) 
dt

months(d)
months(dt)
quarters(dt)

df
subset1 <- subset(df, select=c(PassengerId, Survived)) ; subset1
names(df)
subset2 <- subset(df,Sex == "female" & Age>50, select=c(Sex, Age)) ; subset2
big_df

summarise(df, Age_Mean = mean(Age), Fare_Median=median(Fare), Fare_Min=min(Fare))

arrange(filter(df, Fare>400), desc(Fare))
sbs = subset(df, Fare>250, select=c("Fare"))
sbs
mutate(sbs, adjusted_fare = Fare*3/2) # Adds a new column

# Name, English, Maths
n = 2
name = vector()
english = vector()
maths = vector()
while(n>0) {
  nam = readline(prompt = "Enter name\n")
  eng = readline(prompt = "Enter English\n")
  math = readline(prompt = "Enter Maths\n")
  name = append(name, nam)
  english = append(english, eng)
  maths = append(maths, math)
  n = n-1
}

name
english
maths

df = data.frame(name, english, maths)
df
