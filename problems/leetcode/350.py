class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        res = []
        hash = {}
        for num in nums1:
            if num not in hash.keys():
                hash[num] = 1
            else:
                hash[num] += 1
        for num in nums2:
            if num not in hash.keys() or hash[num] == 0:
                continue
            else:
                res.append(num)
                hash[num] -= 1
        return res