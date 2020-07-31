class Solution:
    def findMagicIndex(self, nums) -> int:
        left, right = 0, len(nums) - 1
        res = -1
        while right >= left:
            mid = (left + right) // 2
            if nums[mid] < mid:
                right = mid - 1
            elif nums[mid] > mid:
                left = mid + 1
            else:
                res = mid
                right = mid - 1
        return res

s = Solution()
test = [0, 2, 3, 4, 5]
print(s.findMagicIndex(test))