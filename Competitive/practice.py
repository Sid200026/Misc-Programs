import itertools

n = int(input())
k = int(input())
a = [1,2,3,1]
for j in range(1,len(a)+1):
    for i in itertools.combinations([1,2,3,1],j):
        if(len(i))