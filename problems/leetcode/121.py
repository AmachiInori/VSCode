class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if len(prices) == 0:
            return 0;
        minPrice = prices[0];
        res = 0;
        for num in prices:
            if num > minPrice:
                if res < num - minPrice:
                    res = num - minPrice;
            else:
                minPrice = num;
        return res;