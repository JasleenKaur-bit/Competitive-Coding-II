class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:
    def isPalindrome(self, head):
        stack = []
        current = head
        # Push all values into stack
        while current:
            stack.append(current.val)
            current = current.next
        current = head
        # Compare values with stack top
        while current:
            if current.val != stack.pop():
                return False
            current = current.next
        return True
def createLinkedList(arr):
    dummy = ListNode()
    current = dummy
    for value in arr:
        current.next = ListNode(value)
        current = current.next
    return dummy.next
arr = list(map(int, input("Enter linked list elements: ").split()))
head = createLinkedList(arr)
obj = Solution()
result = obj.isPalindrome(head)
print("Input:", arr)
print("Is Palindrome:", result)