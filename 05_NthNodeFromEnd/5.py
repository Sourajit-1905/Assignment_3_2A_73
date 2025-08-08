class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class Solution:
    def getKthFromLast(self, head, k):
        main = head
        ref = head
        for _ in range(1, k):
            ref = ref.next
            if not ref:
                return -1
        while ref.next:
            ref = ref.next
            main = main.next
        return main.data

def build_linked_list(values):
    if not values:
        return None
    head = Node(values[0])
    current = head
    for val in values[1:]:
        current.next = Node(val)
        current = current.next
    return head

head = build_linked_list([10, 20, 30, 40, 50])
k = 2
sol = Solution()
print(sol.getKthFromLast(head, k))