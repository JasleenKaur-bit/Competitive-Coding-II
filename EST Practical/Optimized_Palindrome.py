class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:
    def isPalindrome(self, head):
        if not head or not head.next:
            return True
        slow = fast = head
        # Find the middle node
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
        # Reverse the second half
        prev = None
        current = slow
        while current:
            next_node = current.next
            current.next = prev
            prev = current
            current = next_node
        # Compare both halves
        first = head
        second = prev
        while second:
            if first.val != second.val:
                return False
            first = first.next
            second = second.next
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