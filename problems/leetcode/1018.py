class Solution:
    def prefixesDivBy5(self, A):
        res = [False for _ in range(len(A))]
        nowN = 0
        for i in range(len(A)):
            nowN = nowN << 1
            nowN += (A[i] == 1)
            if nowN % 5 == 0:
                res[i] = True
        return res

test = Solution()
print(test.prefixesDivBy5([0,1,1,1,1,1]))