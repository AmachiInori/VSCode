class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        prices.append(0);
        res = 0;
        stack = [];
        for num in prices:
            if len(stack) == 0:
                stack.append(num);
            else:
                if num >= stack[len(stack) - 1]:
                    stack.append(num);
                else:
                    res += stack[len(stack) - 1] - stack[0];
                    while stack:
                        stack.pop();
                    stack.append(num);
        return res;
