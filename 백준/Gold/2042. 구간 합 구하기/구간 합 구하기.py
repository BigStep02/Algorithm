import sys
input = sys.stdin.readline

def segment_partial_sum(start_index, end_index): # 세그먼트트리의 부분합을 구하는 함수
    global partial_sum
    while start_index <= end_index: #시작 인덱스가 끝 인덱스보다 커졌을 경우 모든 합을 다 찾으니 함수 종료
        if start_index % 2 == 1: # 시작 인덱스가 홀수라는 것은 오른쪽 자식이란 얘기기 때문에 자식 두명의 합을 가진 부모노드는 선택할 수 없음(오른쪽 자식의 값만 필요하기 때문)
            partial_sum += segment[start_index]
            start_index += 1 # 오른쪽 자식이면 오른쪽의 부모노드로 들어가야 하기 떄문에 +1
        if end_index % 2 == 0: # 끝 인덱스가 짝수라는 것 또한 오른쪽 자식이란 얘기기 때문에 자식 두명의 합을 가진 부모노드를 선택해야함(자식 둘의 값이 다 필요하기 때문)
            partial_sum += segment[end_index]
            end_index -= 1 # start와 반대
        start_index //= 2 # 부모노드 접근
        end_index //= 2


def segment_update(node, change): # 세그먼트트리의 값을 변경하기 위한 함수
    if node < 1: # 루트에 도달하면 더이상 바꿀 값이 없으니 함수 종료
        return

    segment[node] += change # 해당 인덱스에 있던 값 - 바꿀 값을 하면 변경되는 값의 차를 알 수 있음. 부모 노드로 올라가면서 부모 노드만 값을 바꿔주면 됌
    segment_update(node // 2, change) # 부모 노드 호출

def segment_prefix_sum(): # 세그먼트트리의 누적합을 구하는 함수
    for i in range(len(segment) - 1, 0, -1):
        segment[i // 2] += segment[i] # 부모노드로 올라가면서 자식노드들의 값을 다 더해주면 됌

def segment_init(base): # 세그먼트트리의 초기값을 설정하는 함수
    for i in range(base, base + N): # 2의 k승부터 노드를 초기홯 해줘야 함
        a = int(input())
        segment[i] = a

N, M, K = map(int, input().split())
base = 1 # 배열의 사이즈 및 인덱스 범위 설정을 위한 변수
while base < N: # 세그먼트트리의 구조상 배열의 범위는 입력값 N보다 큰 2의 K승에 2를 곱해준 값이여야 함. 시프트연산자를 통해서 2의 K승을 찾는 과정
    base <<= 1 

segment = [0 for _ in range(base * 2)] # 세그먼트트리의 사이즈

segment_init(base)
segment_prefix_sum()

for _ in range(M + K):
    a, b, c = map(int, input().split())
    if a == 1:
        start_index = b + base - 1 # 입력값과 세그먼트트리에 값이 저장된 위치가 다르기 때문에 start_index, end_index 를 다시 지정해줘야 함
        change = c - segment[start_index]
        segment_update(start_index, change)
    if a == 2:
        start_index = b + base - 1
        end_index = c + base - 1
        partial_sum = 0
        segment_partial_sum(start_index, end_index)
        print(partial_sum)