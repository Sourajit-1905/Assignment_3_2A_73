class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class Solution:
    def detectLoop(self, head):
        slow = head
        fast = head
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
            if slow == fast:
                return True
        return False

def build_linked_list_with_loop(values, loop_index):
    if not values:
        return None
    nodes = []
    head = Node(values[0])
    nodes.append(head)
    current = head
    for val in values[1:]:
        new_node = Node(val)
        nodes.append(new_node)
        current.next = new_node
        current = new_node
    if loop_index != -1:
        current.next = nodes[loop_index]
    return head

head = build_linked_list_with_loop([1, 2, 3, 4, 5], 2)
sol = Solution()
print(sol.detectLoop(head))