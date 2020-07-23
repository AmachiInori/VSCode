class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        left, right = 0, len(numbers) - 1
        sum = numbers[left] + numbers[right]
        while sum != target:
            if sum > target:
                right = right - 1
            elif sum < target:
                left = left + 1
            sum = numbers[left] + numbers[right]
        return [left + 1, right + 1]