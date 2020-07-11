class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def kthToLast(self, head: ListNode, k: int) -> int:
        length = 0;
        ptn = head;
        while ptn != None:
            length += 1;
            ptn = ptn.next;
        ptn = head;
        for i in range(length - k):
            ptn = ptn.next;
        return ptn.val;

class Solution:
    def kthToLast(self, head: ListNode, k: int) -> int:
        res = [];
        ptn = head;
        while ptn != None:
            res.append(ptn.val);
            ptn = ptn.next;
        return res[len(res) - k];
