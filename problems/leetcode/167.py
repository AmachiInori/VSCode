class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        hash = {}
        for i in range(len(numbers)):
            hash[numbers[i]] = i
        for i in range(len(numbers)):
            if target - numbers[i] in hash.keys():
                res = [i + 1, hash[target - numbers[i]] + 1]
                return sorted(res)