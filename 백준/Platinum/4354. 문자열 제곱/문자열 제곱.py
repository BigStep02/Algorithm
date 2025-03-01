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
    cycle = len(S) - failure[-1] # 문자열의 길이에서 실패함수 마지막 인덱스 값을 빼면 사이클의 길이를 구할 수 있음
    if len(S) % cycle == 0: # 문자열의 길이에서 사이클을 나눈 나머지가 0이 아니라면 생긴 나머지 만큼은 반복이 안됌
        answer = len(S) // cycle # 문자열의 길이에서 사이클을 나누면 몇번의 사이클이 생기는지 알 수 있음
    print(answer)