import sys
input = sys.stdin.readline

def segment_partial_product(start_index, end_index):
    answer = 1
    while start_index <= end_index:
        if start_index % 2 == 1:
            answer *= (segment[start_index]) % 1000000007
            start_index += 1
        if end_index % 2 == 0:
            answer *= (segment[end_index]) % 1000000007
            end_index -= 1
        start_index //= 2
        end_index //= 2

    return answer

def segment_update(node, change):
    segment[node] = change

    while node > 1:
        node //= 2
        segment[node] = (segment[node * 2] * segment[node * 2 + 1]) % 1000000007

def segment_init():
    for i in range(base, base + N):
        a = int(input())
        segment[i] = a

def segment_cunsum():
    for i in range(base - 1, 0, -1):
        segment[i] = (segment[i * 2] * segment[i * 2 + 1]) % 1000000007

N, M, K = map(int, input().split())
base = 1

while base < N:
    base <<= 1

segment = [1 for _ in range(base * 2)]

segment_init()
segment_cunsum()

for _ in range(M + K):
    a, b, c = map(int, input().split())
    if a == 1:
        start_index = b + base - 1
        segment_update(start_index, c)
    if a == 2:
        start_index = b + base - 1
        end_index = c + base - 1
        print(segment_partial_product(start_index, end_index) % 1000000007)