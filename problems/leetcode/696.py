class Solution:
    def countBinarySubstrings(self, s: str) -> int:
        res = 0
        count = [1]
        for i in range(1, len(s)):
            if s[i] == s[i - 1]:
                count[-1] += 1
            else:
                count.append(1);
        for i in range(0, len(count) - 1):
            res += min(count[i], count[i + 1])
        return res;
