class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class Solution:
    def reverseList(self, head):
        prev = None
        current = head
        while current is not None:
            next_node = current.next
            current.next = prev
            prev = current
            current = next_node
        head = prev
        return head

def build_linked_list(values):
    if not values:
        return None
    head = Node(values[0])
    current = head
    for val in values[1:]:
        current.next = Node(val)
        current = current.next
    return head

def print_list(head):
    while head:
        print(head.data, end=' ')
        head = head.next
    print()

head = build_linked_list([1, 2, 3, 4, 5])
sol = Solution()
reversed_head = sol.reverseList(head)
print_list(reversed_head)