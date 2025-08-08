class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

def deleteNode(head, x):
    if not head:
        return None
    
    if x == 1:
        head = head.next
        return head
    
    i = 1
    temp = head
    while i < x - 1:
        i += 1
        temp = temp.next
        
    node = temp.next
    temp.next = node.next
    node = None
    
    return head

def createLinkedList(arr):
    if not arr:
        return None
    head = Node(arr[0])
    current = head
    for val in arr[1:]:
        current.next = Node(val)
        current = current.next
    return head

def printLinkedList(head):
    current = head
    while current:
        print(current.data, end=" -> ")
        current = current.next
    print("None")

if __name__ == "__main__":
    arr = [10, 20, 30, 40, 50]
    head = createLinkedList(arr)
    print("Original Linked List:")
    printLinkedList(head)

    x = 3
    head = deleteNode(head, x)
    print("\nLinked List After Deleting Node", x, ":")
    printLinkedList(head)