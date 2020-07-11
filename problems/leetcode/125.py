class Solution:
    def isPalindrome(self, s: str) -> bool:
        stack = []
        s.lower()
        for i in range(0, len(s) // 2):
            
            stack.append(s[i])
        for i in range(len(s) // 2 + 1, len(s)):
            if s[i] != stack[len(stack) - 1]:
                return False
            elif not stack:
                return False
            else:
                stack.pop()
        if not stack:
            return True
        else:
            return False