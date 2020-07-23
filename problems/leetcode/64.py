class Solution:
    def minPathSum(self, grid) -> int:
        if not grid or not grid[0]:
            return 0
        dp = []
        for i in range(len(grid)):
            dp.append([])
            for j in range(len(grid[0])):
                dp[i].append(0)
        dp[0][0] = grid[0][0]
        for i in range(1, len(grid[0])):
            dp[0][i] = grid[0][i] + dp[0][i - 1]
        for i in range(1, len(grid)):
            dp[i][0] = grid[i][0] + dp[i - 1][0]
        for i in range(1, len(dp)):
            for j in range(1, len(dp[0])):
                if dp[i - 1][j] >= dp[i][j - 1]:
                    dp[i][j] = grid[i][j] + dp[i][j - 1]
                else:
                    dp[i][j] = grid[i][j] + dp[i - 1][j]
        return dp[-1][-1]
#创建二维列表注意。不可以用*，*是引用

test = [[7,4,8,7,9,3,7,5,0],[1,8,2,2,7,1,4,5,7],[4,6,4,7,7,4,8,2,1],[1,9,6,9,8,2,9,7,2],[5,5,7,5,8,7,9,1,4],[0,7,9,9,1,5,3,9,4]]
st = Solution()
print(st.minPathSum(test))
