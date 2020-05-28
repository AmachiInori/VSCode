#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int max(vector<int> a, int i) {
        int res = INT_MIN;
        for (int j = 0; j < i; j++) if (a[j] > res) res = a[j];
        return res;
    }

    int maxR(vector<vector<int>> a, int i ,int j) {
        int res = INT_MIN;
        for (int c = 0; c < j; c++) if(a[c][i] > res) res = a[c][i];
        return res;
    }

    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() < nums2.size()) {
            vector<int> temp = vector(&nums1[0], &nums1[nums1.size()]);
            nums1 = nums2;
            nums2 = temp;
        }
        int maxl = INT_MIN;
        vector<vector<int>> matrix(nums1.size());
        for (auto &it : matrix) it.resize(nums2.size());
        vector<vector<int>> dp(nums1.size());
        for (auto &it : dp) it = vector(nums2.size(), 0);

        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++){
                matrix[i][j] = nums1[i] * nums2[j];
                cout << matrix[i][j] << ' ';
            }
            cout << endl;
        }
        cout << endl << endl;
        for (int i = 0; i < dp.size(); i++) {
            for (int j = 0; j < dp[i].size(); j++) {
                if (i == 0) dp[i][j] = matrix[i][j];
                else if (j == 0) dp[i][j] = matrix[i][j];
                else {
                    dp[i][j] = std::max(matrix[i][j] + max(dp[i - 1], j), matrix[i][j] + maxR(dp, j - 1, i));
                    dp[i][j] = std::max(dp[i][j], matrix[i][j]);
                }
                if (dp[i][j] > maxl) maxl = dp[i][j];
                cout << dp[i][j] << ' ';
            }
            cout << endl;
        }
        return maxl;
    }
};