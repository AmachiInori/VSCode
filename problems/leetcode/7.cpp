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
    int reverse(int x) {
        int isNagetive = 1;
        if (x < 0) isNagetive = -1;
        string temp = std::to_string(x);
        for (int i = 0; i < temp.length() / 2; i++){
            char tempC = temp[i];
            temp[i] = temp[temp.length() - 1 - i];
            temp[temp.length() - 1 - i] = tempC;
        }
        long res = isNagetive;
        res *= std::stol(temp);
        if (res > INT_MAX || res < INT_MIN) return 0;
        return res;
    }
};