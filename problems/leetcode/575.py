class Solution:
    def distributeCandies(self, candies: List[int]) -> int:
        hash = {}
        for candi in candies:
            hash[candi] = 1;
        if len(hash.keys()) > len(candies) // 2:
            return len(candies) // 2
        else:
            return len(hash.keys())