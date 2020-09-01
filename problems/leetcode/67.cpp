#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        string *longer, *shorter;
        if (a.size() >= b.size()) {
            longer = &a;
            shorter = &b;
        } else {
            longer = &b;
            shorter = &a;
        }
        int lsize = longer->size(), ssize = shorter->size();

        bool isAdd = false;
        for (int i = 1; i <= lsize; i++) {
            char tempL = longer->operator[](lsize - i), tempS = (i >= ssize + 1)? '0' : shorter->operator[](ssize - i);
            int tempI = tempL + tempS - 2 * '0' + (int)isAdd;
            if (tempI >= 2) {
                tempI -= 2;
                isAdd = true;
            } else {
                isAdd = false;
            }
            longer->operator[](lsize - i) = tempI + '0';
        }
        if (isAdd) {
            *longer = "1" + *longer;
        }
        return *longer;
    }
};

int main() {
    Solution test;
    cout << test.addBinary("11", "1");
    return 0;
}