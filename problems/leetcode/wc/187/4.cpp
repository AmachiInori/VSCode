#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        vector<int> index = vector(mat.size(), 0);
        int minLoca = 0, min = INT_MAX;
        for (int i = 0; i < k; i++){
            for (int j = 0; j < mat.size(); j++){
                if (mat[j][index[j]] < min){
                    min = mat[j][index[j]];
                    minLoca = j;
                }
            }
    }
};