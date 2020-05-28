#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <string>

using std::vector;
using std::stack;
using std::string;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        for (int i = 1; i < grid[0].size(); i++)
            grid[0][i] = grid[0][i] + grid[0][i - 1];
        for (int i = 1; i < grid.size(); i++)
            grid[i][0] = grid[i][0] + grid[i - 1][0];
        for (int i = 1; i < grid.size(); i++){
            for (int j = 1; j < grid[i].size(); j++){
                grid[i][j] = std::min(grid[i][j - 1], grid[i - 1][j]) + grid[i][j];
            }
        }
        return grid.back().back();
    }
};

int main(){
    Solution s;
    vector<vector<int>> test = {{0}};
    std::cout << s.minPathSum(test);
    return 0;
}