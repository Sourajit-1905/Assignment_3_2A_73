class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class Solution:
    def removeLoop(self, head):
        slow = head
        fast = head
        hasCycle = False
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
            if slow == fast:
                hasCycle = True
                break
        if not hasCycle:
            return False
        slow = head
        if slow == fast:
            while fast.next != slow:
                fast = fast.next
        else:
            while slow.next != fast.next:
                slow = slow.next
                fast = fast.next
        fast.next = None
        return True

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

def print_list(head, limit=20):
    count = 0
    current = head
    while current and count < limit:
        print(current.data, end=' ')
        current = current.next
        count += 1
    print()

head = build_linked_list_with_loop([1, 2, 3, 4, 5], 2)
sol = Solution()
sol.removeLoop(head)
print_list(head)