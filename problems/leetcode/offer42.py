class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        nowSum, res = 0, -inf
        for i in nums:
            if nowSum < 0:
                nowSum = 0
            nowSum += i
            if nowSum > res:
                res = nowSum
        return res