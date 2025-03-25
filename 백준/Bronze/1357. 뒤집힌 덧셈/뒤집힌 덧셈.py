num1, num2 = map(str, input().split())
num1, num2 = num1[::-1], num2[::-1]
print(int(str(int(num1) + int(num2))[::-1]))