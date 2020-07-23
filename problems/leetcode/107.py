class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def levelOrderBottom(self, root: TreeNode) -> List[List[int]]:
        if not root:
            return []
        queue = [root]
        res = []
        while queue:
            count = len(queue)
            tempRes = []
            while count != 0:
                if queue[0].left:
                    queue.append(queue[0].left)
                if queue[0].right:
                    queue.append(queue[0].right)
                count -= 1
                tempRes.append(queue[0].val)
                queue.pop(0)
            res.append(tempRes)
        res.reverse()
        return res