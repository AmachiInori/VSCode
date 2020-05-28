#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string lastSubstring(string s) {
        char temp = 0;
        string res;
        vector<char> maxC(s.length());
        for (int i(s.length() - 1); i >= 0; i--) {
            if (s[i] > temp) temp = s[i];
            maxC[i] = temp;
        }
        for (int i(0); i < s.length(); i++) {
            if (s[i] == maxC[i] && (!i || s[i - 1] < s[i])) {
                if (strcmp(&res[0], &s[i]) < 0) 
                    res = &s[i];
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    string test = "babcbd";
    cout << s.lastSubstring(test);
    return 0;
}