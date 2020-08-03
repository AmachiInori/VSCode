#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) {
        for (auto &i : num1)
            i -= '0';
        for (auto &i : num2)
            i -= '0';
        if (num1.size() < num2.size())
            swap(num1, num2);
        for (size_t i = 1; i <= num2.size(); i++) {
            num1[num1.size() - i] = num1[num1.size() - i] + num2[num2.size() - i];
        }
        for (size_t i = num1.size() - 1; i > 0; i--) {
            if (num1[i] >= 10) {
                num1[i] -= 10;
                num1[i - 1] += 1;
            }
            num1[i] += '0';
        }
        if (num1.front() >= 10) {
            num1.front() -= 10;
            num1.insert(0, "1");
            num1[1] += '0';
        } else {
            num1.front() += '0';
        }
        return num1;
    }
};

int main(){
    Solution s;
    string test1 = "1230", test2 = "2340";
    cout << s.addStrings(test1, test2);
    return 0;
}