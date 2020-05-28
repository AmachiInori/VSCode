#include <iostream>
#include <vector>
#include <string>

using std::string;
using std::vector;

class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> res;
        for (int i = 1; i <= n && i <= target[target.size() - 1]; i++){
            bool isExist = false;
            for (int j = 0; j < target.size(); j++){
                if (target[j] == i){
                    isExist = true;
                    break;
                }
            }
            if (isExist) res.push_back("Push");
            else {
                res.push_back("Push");
                res.push_back("Pop");
            }
        }
        return res;
    }
};