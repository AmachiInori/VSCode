/*
 * @Author: your name
 * @Date: 2020-04-20 13:05:05
 * @LastEditTime: 2020-04-20 13:39:22
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \VSCode\problems\leetcode\200.cpp
 */
#include <vector>
using std::vector;

class Solution {
public:
    void destroy(vector<vector<char>>& grid, int x, int y){
        grid[x][y] = 0;
        if (x > 0 && grid[x - 1][y] == '1') destroy(grid, x - 1, y);
        if (y > 0 && grid[x][y - 1] == '1') destroy(grid, x, y - 1);
        if (x < grid.size() - 1 && grid[x + 1][y] == '1') destroy(grid, x + 1, y);
        if (y < grid[x].size() - 1 && grid[x][y + 1] == '1') destroy(grid, x, y + 1);
    }
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        for (int i = 0; i < grid.size(); i++){
            for (int j = 0; j < grid[i].size(); j++){
                if(grid[i][j] == '1'){
                    count++;
                    destroy(grid, i, j);
                }
            }
        }
        return count;
    }
};