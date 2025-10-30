

class Node:
    def __init__(self,data):
        self.data = data
        self.next = None 

node1 = Node(3)
node2 = Node(5)
node3 = Node(12)
node4 = Node(312)
node5 = Node(21)

node1.next = node2
node2.next = node3
node3.next = node4
node4.next = node5
node5.next = node1

currentNode = node1

while currentNode:
    print(currentNode.data,end=" -> ")
    currentNode = currentNode.next
print("NULL")
