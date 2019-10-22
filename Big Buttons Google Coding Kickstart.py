test_cases = int(input())
for i in range (test_cases):
    details = input().split()
    list_of_strings = []
    n = int(details[0])
    p = int(details[1])
    total = pow(2,n)
    check = []
    for j in range (p):
        pattern = input()
        check.append(pattern)
    check.sort()
    for pattern in check:
        print(pattern, sum([pattern.find(i) for i in list_of_strings]), len(list_of_strings)*-1)
        if sum([pattern.find(i) for i in list_of_strings]) == len(list_of_strings)*-1 :
            total -= pow(2,n-len(pattern))
            list_of_strings.append(pattern)
    print("Case #{0}: {1}".format(i+1,total))
