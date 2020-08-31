class Solution:
    def sumZero(self, n):
        res = [0 for _ in range(n)]
        nowNumber = 1
        for i in range(n & 1, (n + 1) // 2):
            res[i] = nowNumber
            res[-i - 1 + (n & 1)] = -nowNumber # 按位与运算优先级很低
            nowNumber = nowNumber + 1
        return res

s = Solution()
s.sumZero(4)