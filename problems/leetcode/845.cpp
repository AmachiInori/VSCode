#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestMountain(vector<int>& A) {
        A.insert(A.begin(), {INT_MAX});
        A.insert(A.end(), {INT_MAX});
        vector<int> miniums;
        for (size_t i = 1; i < A.size() - 1; i++) {
            if (A[i] <= A[i - 1] && A[i] < A[i + 1]) {
                miniums.push_back(i);
            }
        }
        int res = 0;
        for (size_t i = 1; i < miniums.size(); i++) {
            res = max(miniums[i] - miniums[i - 1] + 1, res);
        }
        return res;
    }
};