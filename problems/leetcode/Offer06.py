class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def reversePrint(self, head: ListNode) -> List[int]:
        res = []
        ptn = head
        while ptn != None:
            res.append(ptn.val)
            ptn = ptn.next
        res.reverse()
        return res
