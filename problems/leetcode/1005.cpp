#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestSumAfterKNegations(vector<int>& A, int K) {
        while (K) {
            int minLoca(0);
            for (int i(0); i < A.size(); i++)
                if (A[i] < A[minLoca]) minLoca = i;
            A[minLoca] = -A[minLoca];
            K--;
        }
        int res(0);
        for (auto &i : A) res += i;
        return res;
    }
};