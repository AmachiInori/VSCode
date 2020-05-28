#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<vector<int>> index;
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        index.resize(matrix.size() * 2 - 1);
        int nowLoca = 1;
        int iLoca;
        for (int i = 0; i < index.size(); i++) {
            if (i < matrix.size()) index[i].resize(i + 1);
            else index[i].resize(2 * matrix.size() - (i + 1));
            for (int j = 0; j < index[i].size(); j++){
                if (nowLoca == k) iLoca = i;
                if (i < matrix.size()) index[i][j] = matrix[i - j][j];
                else index[i][j] = matrix[matrix.size() - j - 1][i + j - matrix.size() + 1];
                nowLoca++;
            }
        }
        sort(index[iLoca].begin(), index[iLoca].end());
        int spm = 0;
        for (int i = 0; i < iLoca; i++) spm += index[i].size();
        spm = k - spm - 1;
        return index[iLoca][spm];
    }
};

int main()  {
    Solution s;
    vector<vector<int>> test = {{1, 3, 5}, {6, 7, 12}, {11, 14, 14}};
    cout << s.kthSmallest(test, 3);
    return 0;
}