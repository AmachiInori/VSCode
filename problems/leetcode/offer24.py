class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        if head == None:
            return None
        p, q = None, head
        r = q.next
        while q != None:
            q.next = p
            p = q
            q = r
            if r != None:
                r = r.next
        return p