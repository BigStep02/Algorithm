import sys
input = sys.stdin.readline

def KMP():
    global cnt, answer
    idx = 0

    for i in range(len(word)): # KMP 알고리즘(문자열 매칭 실패시 불필요한 연산을 줄임)
        while idx > 0 and word[i] != target[idx]:
            idx = failure[idx - 1]
        if word[i] == target[idx]:
            if idx == len(target) - 1:
                cnt += 1
                answer.append(i - len(target) + 2)
                idx = failure[idx]
            else:
                idx += 1

def failure_func(): # 문자열 매칭에 실패했을때 얼마나 건너뛰어야 하는지 계산(최장 접미사를 구함)
    idx = 0
    for i in range(1, len(target)):
        while idx > 0 and target[i] != target[idx]:
            idx = failure[idx - 1]
        if target[i] == target[idx]:
            failure[i] = idx + 1
            idx += 1
        else :
            failure[i] = 0

word = input().rstrip()
target = input().rstrip()
failure = [0 for _ in range(len(target))]
cnt = 0
answer = []

failure_func()
KMP()

print(cnt)
print(*answer)