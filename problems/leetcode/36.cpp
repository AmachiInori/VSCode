#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <string>
#include <cmath>

using std::vector;
using std::stack;
using std::string;

class Solution {
    const int index[9] = {0,0,0,3,3,3,6,6,6};
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < board.size(); i++){
            for (int j = 0; j < board[i].size(); j++){
                if (board[i][j] != '.') {
                    char theChar = board[i][j];
                    int count = 0;
                    for (int k = 0; k < board[i].size(); k++){
                        if (board[i][k] == theChar) count++;
                        if (count == 2) return false;
                    }
                    count = 0;
                    for (int k = 0; k < board.size(); k++){
                        if (board[k][j] == theChar) count++;
                        if (count == 2) return false;
                    }
                    count = 0;
                    for (int k = 0; k < 3; k++){
                        for (int l = 0; l < 3 ; l++) {
                            if (board[index[i] + k][index[j] + l] == theChar) count++;
                            if (count == 2) return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};