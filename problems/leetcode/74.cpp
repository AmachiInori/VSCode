#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int up = 0, down = matrix.size() - 1, mid;
        if (matrix.empty() || matrix[0].empty() || target < matrix.front().front() || target > matrix.back().back()) return false;
        while (up < down) {
            mid = (up + down) / 2;
            if (matrix[mid].front() > target) down = mid;
            else if (matrix[mid].back() < target) up = mid + 1;
            else break;
        }
        up = 0, down = matrix[mid].size() - 1;
        int newMid;
        while (up < down) {
            newMid = (up + down) / 2;
            if (matrix[mid][newMid] > target) down = newMid;
            else if (matrix[mid][newMid] < target) up = newMid + 1;//二分查找必须有进行步骤
            else return true;
        }
        return matrix[mid][up] == target;
    }
};