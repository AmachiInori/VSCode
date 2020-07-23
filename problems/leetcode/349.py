class Solution:
    def intersection(self, nums1: List[int], nums2: List[int]) -> List[int]:
        hash1 = {}
        hash2 = {}
        res = []
        for num in nums1:
            hash1[num] = 1
        for num in nums2:
            hash2[num] = 1
        for i in hash1.keys():
            if i in hash2.keys():
                res.append(i)
        return res