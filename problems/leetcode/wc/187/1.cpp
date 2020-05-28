#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        int i;
        for (i = 0; i < paths.size(); i++) {
            bool isCorrect = true;
            for (int j = 0; j < paths.size(); j++){
                if (paths[i][1] == paths[j][0]){
                    isCorrect = false;
                    break;
                }
            }
            if (isCorrect) return paths[i][1];
        }
        return paths[i][1];
    }
};