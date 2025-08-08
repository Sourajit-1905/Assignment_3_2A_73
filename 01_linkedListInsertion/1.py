class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class Solution:
    def insertAtEnd(self, head, x):
        new_node = Node(x)
        if head is None:
            return new_node
        
        current = head
        while current.next:
            current = current.next
        current.next = new_node
        return head

def printList(head):
    current = head
    while current:
        print(current.data, end=" --> ")
        current = current.next
    print("None")


head = Node(10)
head.next = Node(20)

solution = Solution()
head = solution.insertAtEnd(head, 30)  

printList(head)