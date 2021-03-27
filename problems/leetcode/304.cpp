#include <bits/stdc++.h>
using namespace std;

class NumMatrix {
    vector<vector<int>> sum_matrix;
public:
    NumMatrix(vector<vector<int>>& matrix) : 
    sum_matrix(matrix.size() + 1, 
               vector<int>(matrix.empty() ? 
                           1 : matrix[0].size() + 1, 0)) {
        for (size_t i = 1; i < matrix.size() + 1; i++) {
            for (size_t j = 1; j < matrix[0].size() + 1; j++) {
                sum_matrix[i][j] = sum_matrix[i - 1][j] + sum_matrix[i][j - 1] - sum_matrix[i - 1][j - 1] + matrix[i - 1][j - 1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return sum_matrix[row2 + 1][col2 + 1] - sum_matrix[row2 + 1][col1] - sum_matrix[row1][col2 + 1] 
               + sum_matrix[row1][col1];
    }
};