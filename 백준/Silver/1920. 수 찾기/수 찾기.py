N = int(input())
temp = list(map(int, input().split()))
num1 = {}

for i, x in enumerate(temp):
    num1[x] = {i}

M = int(input())
num2 = list(map(int, input().split()))
for i in range(M):
    if num2[i] in num1:
        print(1)
    else: print(0)