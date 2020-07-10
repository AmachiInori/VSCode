class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        for i in range(len(nums)):
            for j in range(i + 1, len(nums)):
                if nums[i] + nums[j] == target:
                    return [i, j];

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        hash = {};
        for i in range(len(nums)):
            hash[nums[i]] = i;
        for i in range(len(nums)):
            if target - nums[i] in hash:
                if i != hash[target - nums[i]]:
                    return sorted([i, hash[target - nums[i]]]);