class Solution:
    def isPalindrome(self, x: int) -> bool:
        thestr = str(x)
        for i in range(len(thestr) // 2):
            if thestr[i] == thestr[len(thestr) - 1 - i]:
                continue
            else:
                return False
        return True