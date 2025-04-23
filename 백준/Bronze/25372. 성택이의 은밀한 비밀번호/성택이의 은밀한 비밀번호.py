N = int(input())

for _ in range(N):
    word = input()
    if len(word) >= 6 and len(word) <= 9:
        print("yes")
    else: print("no")