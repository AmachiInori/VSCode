#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if (matrix.size() == 0) return;
        vector<int> line;
        vector<int> updown;
        for (int i = 0; i < matrix.size(); i++){
            for (int j = 0; j < matrix[i].size(); j++)
                if(!matrix[i][j]){
                    line.push_back(i);
                    updown.push_back(j);
                }
        }
        for (int i = 0; i < line.size(); i++){
            for (int j = 0; j < matrix[0].size(); j++){
                matrix[line[i]][j] = 0;
            }
        }
        for (int i = 0; i < updown.size(); i++){
            for (int j = 0; j < matrix.size(); j++){
                matrix[j][updown[i]] = 0;
            }
        }
    }
};