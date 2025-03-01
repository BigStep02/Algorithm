import sys
input = sys.stdin.readline

def Failure_Func():
    idx = 0
    for i in range(1, N):
        while idx > 0 and word[i] != word[idx]:
            idx = failure[idx - 1]
        if word[i] == word[idx]:
            failure[i] = idx + 1
            idx += 1

N = int(input())
word = input().rstrip()
failure = [0 for _ in range(N)]

Failure_Func()
print(len(word) - failure[-1])