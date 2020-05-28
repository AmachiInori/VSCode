#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int max = 0;
        for (int i = 0; i < matrix.size(); i++){
            for (int j = 0; j < matrix[i].size(); j++){
                if (matrix[i][j] == '0') continue;
                int addNumber;
                bool isWrong = false;
                for (addNumber = 1; i + addNumber < matrix.size() && j + addNumber < matrix[i].size(); addNumber++){
                    for (int k = j; k <= j + addNumber; k++){
                        if (matrix[i + addNumber][k] == '0'){
                            isWrong = true;
                            break;
                        } 
                    }
                    if (isWrong) break;
                    for (int k = i; k <= i + addNumber; k++){
                        if (matrix[k][j + addNumber] == '0'){
                            isWrong = true;
                            break;
                        } 
                    }
                    if (isWrong) break;
                }
                max = max > addNumber ? max : addNumber;
            }
            
        }
        return max * max;
    }
};

int main(){
    Solution s;
    vector<vector<char>> a = {{'1','1','1','1'},{'1','1','1','1'},{'1','1','1','1'}};
    std::cout << s.maximalSquare(a);
    system("pause");
    return 0;
}