class Solution:
    def reverse(self, x: int) -> int:
        if x < 0:
            isNagetive = -1;
            x = -x;
        else:
            isNagetive = 1;
        res = 0;
        while x > 0:
            res *= 10;
            res += x % 10;
            x //= 10;
        res *= isNagetive;
        if res > 2 ** 31 - 1 or res < - 2 ** 31:
            return 0;
        else:
            return res;