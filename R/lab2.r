# Q1

char_vec = c(letters)
char_vec

vowel_vec = char_vec[c(1,5,9,15,21)]
vowel_vec

consonant_vec = char_vec[-c(1,5,9,15,21)]
consonant_vec

# Q2

num_vec = c(1:20)
num_vec

even_vec = num_vec[seq(1:10)*2]
even_vec

odd_vec = num_vec[-seq(1:10)*2]
odd_vec

prime_vec = num_vec[c(2,3,5,7,11,13,17,19)]
prime_vec

# Q3

common_vec = intersect(odd_vec,prime_vec)
common_vec

# Q4

Scores = c(36, 42, 31, 85, 22, 90, 72, 68, 42, 85, 25)
Scores
min(Scores)
max(Scores)

# Q5

n_val = readline(prompt="Value of n: ")
n_val = as.integer(n_val)
n_val

Desc_Scores = sort.int(Scores, decreasing=TRUE)
Desc_Scores

if(n_val < length(Desc_Scores)) {
  nth_max = Desc_Scores[n_val]
} else {
  nth_max = -1
}
nth_max

# Q6

descending_scores = sort.int(Scores, decreasing=TRUE)
ascending_scores = sort.int(Scores, decreasing=FALSE)

descending_scores
ascending_scores

# Q7

marks = readline(prompt="Enter marks: ")
marks = as.integer(marks)
marks
Scores
match(marks, Scores)

# Q8

new_marks = readline(prompt="Enter new marks: ")
new_marks = as.integer(new_marks)
new_marks
index = match(new_marks, Scores)
if(is.na(index)) {
  index = -1
}
index

# Q9

Scores
unique_scores = unique(Scores)
unique_scores

# Q10

Scores
reverse_scores = rev(Scores)
reverse_scores

# Q11

my_vector <- c (28, 29, NA, 75, NA, 55, 67)
my_vector

# 11.a

length_of_my_vector = length(my_vector)
length_of_my_vector

# 11.b

my_vector[!is.na(my_vector)]

# 11.c

replace(my_vector, is.na(my_vector), 12)

# 11.d

length(which(is.na(my_vector)))

# 12

Name=c("Rohan", "ANMOL", "RAMYA", "Sai", "KESHAV")
Subject1 = c(34, NA, 21, 56, 57)
Subject2 = c(NA, 52, 46, 44, 20)

my_df <- data.frame(Name, Subject1, Subject2,stringsAsFactors=FALSE)
my_df

my_df[complete.cases(my_df[ , 1:2]),]

# 13

na.omit(my_df)
