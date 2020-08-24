class Solution:
    def repeatedSubstringPattern(self, s: str) -> bool:
        res = False
        for i in range(1, len(s) // 2 + 1):
            tempRes = True
            if len(s) % i != 0:
                continue
            mode = s[:i]
            modePointer = 0
            for j in range(0, len(s)):
                if mode[modePointer] != s[j]:
                    tempRes = False
                    break;
                modePointer = modePointer + 1
                modePointer = modePointer % len(mode)
            res = res or tempRes
        return res