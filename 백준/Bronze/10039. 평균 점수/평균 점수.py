import sys
input = sys.stdin.readline

nums = [int(input()) for _ in range(5)]
total = 0

for x in nums:
    if x < 40:
        total += 40
        continue
    total += x

print(total // 5)