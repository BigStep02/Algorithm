import sys
sys.stdin.readline

def segment_partial_sum(start_index, end_index, node_left, node_right, node): # 지연된 값이 있을 수 있으므로 루트노드부터 지연된 값을 더해주면서 연산해야함
    propagation(node, node_left, node_right) # 지연된 값이 있는지 확인하고 연산하는 작업
    if start_index > node_right or end_index < node_left: # 범위를 하나도 걸치지 않은 노드(연산을 할 필요가 없음)
        return 0 
    if start_index <= node_left and end_index >= node_right: # 범위에 완전히 걸친 노드(지연된 값이 있다면 이미 위에서 처리를 해줬기 떄문에 연산하면 됌)
        return segment[node][0]
    
    mid = (node_left + node_right) // 2
    left = segment_partial_sum(start_index, end_index, node_left, mid, node * 2) # 왼쪽 자식 노드 호출
    right = segment_partial_sum(start_index, end_index, mid + 1, node_right, node * 2 + 1) # 오른쪽 자식 노드 호출

    return left + right # 루트노드 기준 왼쪽 자식 노드들 에서 계산한 누적합과 오른쪽 자식 노드들에서 계산한 결과를 합쳐야 누적합이 됌

def segment_update(start_index, end_index, change, node, node_left, node_right): # 많은 구간을 할꺼번에 업데이트 해야할 때 지연 전파를 해야함(시간복잡도)
    propagation(node, node_left, node_right) # 현재 노드에 지연된 값이 있다면 연산을 해주고 지연 된 값을 자식 노드들로 전파해줘야함
    if start_index > node_right or end_index < node_left: # 범위에 하나도 걸치지 않은 노드
        return
    if start_index <= node_left and end_index >= node_right: # 범위에 완전히 걸친 노드
        segment[node][1] += change # 범위에 완전히 걸친 노드는 연산을 바로 해줘야 함
        propagation(node, node_left, node_right)
        return
    mid = (node_left + node_right) // 2
    segment_update(start_index, end_index, change, node * 2, node_left, mid) # 왼쪽 자식 노드 호출
    segment_update(start_index, end_index, change, node * 2 + 1, mid + 1, node_right) # 오른쪽 자식 노드 호출
    segment[node][0] = segment[node * 2][0] + segment[node * 2 + 1][0] # 더 이상 자식으로 내려갈 필요가 없거나 이미 리프노드인 경우 업데이트 된 값으로 연산

def propagation(node, node_left, node_right): # 지연 전파
    if segment[node][1] != 0: # 해당 노드에 지연된 값이 있을 때
        segment[node][0] += segment[node][1] * (node_right - node_left + 1) # 완전히 걸치는 부분만 계산하기 때문에 리프노드들 개수만큼 곱해줘야 함
        if node_left != node_right: # 리프노드인지 아닌지 판단
            segment[node * 2][1] += segment[node][1] # 리프노드들의 지연값 저장 공간에 현재 지연된 값을 전파해야함
            segment[node * 2 + 1][1] += segment[node][1]
        segment[node][1] = 0 # 현재 노드는 지연된 값을 처리했기 때문에 지연값 삭제

def segment_prefix_sum():
    for i in range(base - 1, 0, -1):
        segment[i][0] = segment[i * 2][0] + segment[i * 2 + 1][0]

def segment_init(base):
    for i in range(base, base + N):
        a = int(input())
        segment[i][0] = a

N, M, K = map(int, input().split())
base = 1
while base < N:
    base <<= 1

segment = [[0, 0] for _ in range(base * 2)]

segment_init(base)
segment_prefix_sum()

for _ in range(M + K):
    nums = list(map(int, input().split()))
    if nums[0] == 1:
        start_index, end_index, change = nums[1], nums[2], nums[3]
        segment_update(start_index, end_index, change, 1, 1, base)
    if nums[0] == 2:
        start_index, end_index = nums[1], nums[2]
        print(segment_partial_sum(start_index, end_index, 1, base, 1))