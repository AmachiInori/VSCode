#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        for (int j = triangle.size() - 2; j >= 0; j--){
            for (int i = 0; i < triangle[j].size(); i++)
                triangle[j][i] = std::min(triangle[j + 1][i], triangle[j + 1][i + 1]) + triangle[j][i];
        }
        return triangle[0][0];
    }
};