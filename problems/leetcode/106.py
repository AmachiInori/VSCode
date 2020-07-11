class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def buildTree(self, inorder: List[int], postorder: List[int]) -> TreeNode:
        if not postorder and not inorder:
            return None
        loca = 0
        for i in range(len(inorder)):
            if inorder[i] == postorder[len(postorder) - 1]:
                loca = i
                break
        root = TreeNode(inorder[loca])
        root.left = self.buildTree(inorder[0:loca], postorder[0:loca])
        root.right = self.buildTree(inorder[loca + 1:len(inorder)], postorder[loca:len(postorder) - 1])
        return root
