from collections import deque
import sys
input = sys.stdin.readline

Test_case = int(input())

queue = deque()
for _ in range(Test_case):
    test = list(input().split())
    if test[0] == 'push':
        queue.append(int(test[1]))
    elif test[0] == 'pop':
        if queue:
            print(queue.popleft())
        else:
            print(-1)
    elif test[0] == 'size':
        print(len(queue))
    elif test[0] == 'empty':
        if queue:
            print(0)
        else: print(1)
    elif test[0] == 'front':
        if queue:
            print(queue[0])
        else:
            print(-1)
    else:
        if queue:
            print(queue[-1])
        else:
            print(-1)