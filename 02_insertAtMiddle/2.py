class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

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

class Solution:
    def insertInMiddle(self, head, x):
        newnode = Node(x)
        
        if not head:
            return newnode
            
        slow = head
        fast = head
        while fast and fast.next:
            fast = fast.next.next
            if not fast: 
                break
            slow = slow.next
            
        newnode.next = slow.next
        slow.next = newnode
        
        return head

if __name__ == "__main__":
    arr = [1, 2, 3, 4]
    head = createLinkedList(arr)
    
    print("Original Linked List:")
    printLinkedList(head)

    x = 99
    sol = Solution()
    head = sol.insertInMiddle(head, x)
    
    print("\nLinked List After Insertion:")
    printLinkedList(head)