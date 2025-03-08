import sys
sys.setrecursionlimit(10 ** 5)

def DFS(Root_idx, last_idx):
    if Root_idx > last_idx:
        return
    right_index = Root_idx + 1
    Root = node[Root_idx]
    while right_index <= last_idx:
        if node[right_index] > Root:
            break
        right_index += 1
    DFS(Root_idx + 1, right_index - 1)
    DFS(right_index, last_idx)

    print(Root)

node = [int(readline.rstrip()) for readline in sys.stdin]
DFS(0, len(node) - 1)