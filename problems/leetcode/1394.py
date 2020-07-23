class Solution:
    def findLucky(self, arr: List[int]) -> int:
        res = -1
        hash = {}
        for num in arr:
            if num not in hash.keys():
                hash[num] = 1
            else:
                hash[num] += 1
        for key, va in hash.items():
            if key == va:
                if res < key:
                    res = key
        return res