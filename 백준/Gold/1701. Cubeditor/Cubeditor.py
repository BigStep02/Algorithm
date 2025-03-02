import sys
input = sys.stdin.readline

def Fail_Func(pattern):
    global answer

    failure = [0 for _ in range(len(pattern))]
    idx = 0
    for i in range(1, len(pattern)):
        while idx > 0 and pattern[i] != pattern[idx]:
            idx = failure[idx - 1]
        if pattern[i] == pattern[idx]:
            failure[i] = idx + 1
            idx += 1
        answer = max(answer, failure[i])

    return answer

S = input().rstrip()
answer = 0

for i in range(len(S)):
    pattern = S[i:]
    answer = max(answer, Fail_Func(pattern))

print(answer)