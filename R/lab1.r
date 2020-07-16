# @lab 1

# Q1
x = vector("numeric", length=10)
x = 1:5
print(x)

# Q2
print(as.logical(x))
print(as.complex(x))

# Q3

q3_var1 = 0
q3_var2 = 1
q3_var3 = 0
q3_var4 = 6
q3_var5 = 5

vec = c(q3_var1, q3_var2, q3_var3, q3_var4, q3_var5)
vec

# Q4

identity_matrix = diag(3)
identity_matrix

# Q5

mat = matrix(c(1:12), nrow = 3)
mat

# Q6

matrow = matrix(c(1:12), nrow = 3, byrow = TRUE)
matrow

# Q7

print(matrow[3,])

# Q8

print(matrow[,2])

# Q9

print(matrow[1,1])
print(matrow[3,4])

# Q10

month_vec = c('Jan', 'Feb', 'Mar', 'Apr', 'May', 'Jun', 'Jul', 'Aug', 'Sep', 'Oct', 'Nov', 'Dev')
month_vec

# Q11

number_of_days = c(31,28,31,30,31,30,31,31,30,31,30,31)
number_of_days

# Q12

combined_matrix = cbind(month_vec, number_of_days)
combined_matrix

# Q13

q13_var1 = 4
q13_var2 = 5
q13_var3 = 6
q13_var4 = 2
q13_var5 = 9
lst = list(c(q13_var1, q13_var2, q13_var3, q13_var4, q13_var5))
lst

# Q14

x1 = c(157:164); x1
x2 = c(c(15:18),c(20:24)); x2
x3 = c(10:1); x3
x4 = c(c(-1071:-1075), c(-1074:-1071)); x4
x5 = seq(1.5,5.5,1); x5

# Q15

y1 = (10:20) * 2; y1
y2 = 105:(30 * 3); y2
y3 = 10:20*2; y3
y4 = 1 + 1:10/10; y4
y5 = 2^(0:5); y5

# Q16

z1 = c(1:6) *5; z1
z2 = c(0:15) %% 4; z2
z3 = c(1:8)/c(5:12); z3
z4 = c(1:2) * (1:10); z4

# Q17

seq(from=20, to=80, by=20)
seq(from=-10, to=5, by=0.5)
seq(from=10, to=-3, by=-2)
seq(from=0.01, to=0.09, by=0.02)

# Q18

w1 = rep(5,7); w1
w2 = rep(c(5:7), 5); w2
w3 = rep(c(10,16,71), 3); w3

# Q19

c(rep(5,4), rep(8,4), rep(-3,4), rep(0.34,4))
c(rep(-0.1,2), rep(-0.9,2), rep(-0.6,2))
rep(c(rep(1,2), rep(2,2), rep(3,2)),3)

# Q20

rep(seq(97,102), 3)
rep(seq(-5,-8,-1), each=4)
rep(seq(13,29,4), each=2, times=2)

# Q21

rep(seq(97,102), 3)
rep(seq(-5,-8,-1), each=4)
rep(seq(13,29,4), each=2, times=2)
rep(c(seq(1:3), seq(2,0,-1)), 3)
