import sys
input = sys.stdin.readline

def swap(A, B):
    while A < B:
        temp = basket[A]
        basket[A] = basket[B]
        basket[B] = temp
        A += 1
        B -= 1
        
N, M = map(int, input().split())
basket = [i for i in range(1, N + 1)]

for _ in range(M):
    a, b = map(int, input().split())
    a -= 1
    b -= 1
    swap(a, b)

print(*basket)