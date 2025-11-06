import sys
input = sys.stdin.readline

class Node:
    def __init__(self, data):
        self.data = data
        self.prev = None
        self.next = None

class Doubly_linked_list:
    def __init__(self):
        self.head = Node(None)
        self.tail = Node(None)
        self.head.next = self.tail
        self.tail.prev = self.head
        self.cursor = self.tail
    
    def insert(self, data):
        prev_node = self.cursor.prev
        new_node = Node(data)

        #새 노드와 이전 노드 연결
        prev_node.next = new_node
        new_node.prev = prev_node

        #새 노드와 커서 노드 연결
        new_node.next = self.cursor
        self.cursor.prev = new_node

    def delete(self):
        #커서 바로 이전 노드를 삭제
        prev_node = self.cursor.prev

        #지울 노드가 head가 아니라면 (지울 노드가 head라는 말은 지울 노드가 없다는 뜻)
        if prev_node != self.head:
            before_prev_node = prev_node.prev

            before_prev_node.next = self.cursor
            self.cursor.prev = before_prev_node

    def move_left(self):
        if self.cursor.prev != self.head:
            self.cursor = self.cursor.prev
    
    def move_right(self):
        if self.cursor != self.tail:
            self.cursor = self.cursor.next

    def print(self):
        self.cursor = self.head.next

        while self.cursor != self.tail:
            print(self.cursor.data, end = "")
            self.cursor = self.cursor.next


testCase = int(input())

for i in range(testCase):
    word = input().rstrip()
    linked_list_A = Doubly_linked_list()
    for x in word:
        if x == "<":
            linked_list_A.move_left()
        elif x == ">":
            linked_list_A.move_right()
        elif x == "-":
            linked_list_A.delete()
        else:
            linked_list_A.insert(x)
    
    linked_list_A.print()
    print()