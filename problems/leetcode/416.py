class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        sum = 0
        for i in nums:
            sum = sum + i
        if sum % 2 == 1:
            return False
        dp = [[False] * (sum // 2 + 1) for _ in range(len(nums))]
        if nums[0] <= sum // 2:
            dp[0][nums[0]] = True
        for i in range(1, len(nums)):
            for j in range(sum // 2 + 1):
                dp[i][j] = dp[i - 1][j]
                if j == nums[i]:
                    dp[i][j] = True
                    continue
                if (nums[i] < j):
                    dp[i][j] = dp[i - 1][j] or dp[i - 1][j - nums[i]]
        return dp[len(nums) - 1][sum // 2]