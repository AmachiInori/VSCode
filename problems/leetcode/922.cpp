#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        vector<int> res(A.size());
        size_t one_loca = 1, two_loca = 0;
        for_each(A.begin(), A.end(), [&](int i) {
            if (i % 2) {
                res[one_loca] = i;
                one_loca += 2;
            } else {
                res[two_loca] = i;
                two_loca += 2;
            }
        });
        return res;
    }
};