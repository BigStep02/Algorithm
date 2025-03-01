import sys
input = sys.stdin.readline

def Failure_Func():
    idx = 0
    for i in range(1, len(S)):
        while idx > 0 and S[i] != S[idx]:
            idx = failure[idx - 1]
        if S[i] == S[idx]:
            failure[i] = idx + 1
            idx += 1

while True:
    S = input().rstrip()
    if S == '.':
        break
    failure = [0 for _ in range(len(S))]
    Failure_Func()
    answer = 1
    cycle = len(S) - failure[-1]
    if len(S) % cycle == 0:
        answer = len(S) // cycle
    print(answer)