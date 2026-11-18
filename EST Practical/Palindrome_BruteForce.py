class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:
    def isPalindrome(self, head):
        values = []
        current = head
        # Store linked list values
        while current:
            values.append(current.val)
            current = current.next
        # Compare original and reversed values
        return values == values[::-1]
# Create linked list from user input
def createLinkedList(arr):
    dummy = ListNode()
    current = dummy
    for value in arr:
        current.next = ListNode(value)
        current = current.next
    return dummy.next
# Take input and display result
arr = list(map(int, input("Enter linked list elements: ").split()))
head = createLinkedList(arr)
obj = Solution()
result = obj.isPalindrome(head)
print("Input:", arr)
print("Is Palindrome:", result)