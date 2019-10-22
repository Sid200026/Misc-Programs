def fact(n):
    if n==1 or n==0:
        return 1
    else:
        return n*fact(n-1)

n = 50
l = [fact(i) for i in range(50)]
print(l)
