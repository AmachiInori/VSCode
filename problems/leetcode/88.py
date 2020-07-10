class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        pointA = 0;
        pointB = 0;
        nowLength = m;
        while pointA < m + n and pointB < n:
            if pointA < nowLength:
                if nums1[pointA] < nums2[pointB]:
                    pointA += 1;
                else:
                    for i in range(nowLength, pointA, -1):
                        nums1[i] = nums1[i - 1];
                    nums1[pointA] = nums2[pointB];
                    pointA += 1;
                    pointB += 1;
                    nowLength += 1;
            elif pointA >= nowLength:
                nums1[pointA] = nums2[pointB];
                pointA += 1;
                pointB += 1;
                nowLength += 1;