class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def kthToLast(self, head: ListNode, k: int) -> int:
        strt = head
        for i in range(k):
            head = head.next
        while head != None:
            strt = strt.next
            head = head.next
        return strt.val