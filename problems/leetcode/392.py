class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        strA, strB = 0, 0
        while strA != len(s) and strB != len(t):
            if s[strA] == t[strB]:
                strA += 1
            strB += 1
        return strA == len(s)