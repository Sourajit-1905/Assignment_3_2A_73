class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class Solution:
    def searchKey(self, n, head, key):
        temp = head
        while temp:
            if temp.data == key:
                return True
            temp = temp.next
        return False

def build_linked_list(values):
    if not values:
        return None
    head = Node(values[0])
    current = head
    for val in values[1:]:
        current.next = Node(val)
        current = current.next
    return head

head = build_linked_list([1, 2, 3, 4, 5])
key = 3
n = 5
sol = Solution()
print(sol.searchKey(n, head, key))