#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        digits[digits.size() - 1]++;
        for (int i = digits.size() - 1; i > 0; i--){
            if (digits[i] == 10) {
                digits[i] = 0;
                digits[i - 1]++;
            }
        }
        if (digits[0] == 10) {
            vector<int> newRes = vector(digits.size() + 1, 0);
            newRes[0] = 1;
            newRes[1] = 0;
            for (int i = 1; i < digits.size(); i++){
                newRes[i + 1] = digits[i];
            }
            return newRes;
        }
        return digits;
    }
};