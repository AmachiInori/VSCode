#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int _max = 0;
        for (size_t i = 0; i < matrix.size(); i++) {
            vector<bool> last_good_line(matrix[0].size(), true);
            for (size_t j = i; j < matrix.size(); j++) {
                int temp = 0;
                for (size_t k = 0; k < matrix[0].size(); k++) {
                    if (!last_good_line[k]) continue;
                    bool is_good_line = true;
                    if (!matrix[j][k]) {
                        is_good_line = false;
                        last_good_line[k] = false;
                        continue;
                    }
                    temp++;
                }
                if (!temp) {
                    break;
                }
                _max = max(temp * static_cast<int>(j - i + 1), _max);
            }
        }
        return _max;
    }
};