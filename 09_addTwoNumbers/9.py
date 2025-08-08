class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class Solution:
    def reverse(self, head):
        prev = None
        curr = head
        while curr is not None:
            nextNode = curr.next
            curr.next = prev
            prev = curr
            curr = nextNode
        return prev

    def trimLeadingZeros(self, head):
        while head and head.data == 0:
            head = head.next
        return head

    def countNodes(self, head):
        length = 0
        curr = head
        while curr is not None:
            length += 1
            curr = curr.next
        return length

    def addTwoLists(self, num1, num2):
        num1 = self.trimLeadingZeros(num1)
        num2 = self.trimLeadingZeros(num2)
        len1 = self.countNodes(num1)
        len2 = self.countNodes(num2)
        if len1 < len2:
            return self.addTwoLists(num2, num1)
        carry = 0
        num1 = self.reverse(num1)
        num2 = self.reverse(num2)
        res = num1
        while num2 is not None or carry != 0:
            num1.data += carry
            if num2 is not None:
                num1.data += num2.data
                num2 = num2.next
            carry = num1.data // 10
            num1.data = num1.data % 10
            if num1.next is None and carry != 0:
                num1.next = Node(0)
            num1 = num1.next
        return self.reverse(res)

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

num1 = build_linked_list([0, 1, 2, 3])
num2 = build_linked_list([9, 9, 9])
sol = Solution()
result = sol.addTwoLists(num1, num2)
print_list(result)