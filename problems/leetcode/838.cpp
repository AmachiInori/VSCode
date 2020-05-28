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
    string pushDominoes(string dominoes) {
        string result(dominoes.length(), '.');
        for (int i = 0; i < dominoes.length(); i++){
            if (dominoes[i] == 'L') {
                int fin = 0;
                bool isFull = true;
                for (int j = i - 1; j >= 0; j--){
                    if (dominoes[j] == 'R') {
                        isFull = false;
                        fin = j;
                        break;
                    }
                    if (dominoes[j] == 'L') {
                        fin = j;
                        break;
                    }
                }
                if (isFull) 
                    for (int j = i; j >= fin; j--) result[j] = 'L';
                else 
                    for (int j = i; j > (fin + i) / 2; j--) result[j] = 'L';
            }
            if (dominoes[i] == 'R') {
                int fin = dominoes.length() - 1;
                bool isFull = true;
                for (int j = i + 1; j < dominoes.length(); j++){
                    if (dominoes[j] == 'L') {
                        isFull = false;
                        fin = j;
                        break;
                    }
                    if (dominoes[j] == 'R') {
                        fin = j;
                        break;
                    }
                }
                if (isFull) 
                    for (int j = i; j <= fin; j++) result[j] = 'R';
                else 
                    for (int j = i; j < (fin + i + 1) / 2; j++) result[j] = 'R';
            }
        }
        return result;
    }
};

int main() {
    Solution s;
    string test = ".L.R...LR..L..";
    std::cout << s.pushDominoes(test);
    system("pause");
    return 0;
}