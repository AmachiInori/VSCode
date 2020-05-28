#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int left(0), right(0);
        int max(0);
        while (left <= right && right < A.size()) {
            while (right < A.size() &&(A[right] || K != 0)) {
                if (!A[right]) K--;
                right++;
            }
            max = std::max(right - left, max);
            if (A[left]) left++;
            else left++, right++;
        }
        return max;
    }
};

int main() {
    Solution s;
    vector<int> test = {0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1};
    cout << s.longestOnes(test, 3);
    return 0;
}