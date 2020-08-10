#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<string> res;
    vector<int> temp;
    void runner(string s, int m) {
        if (s.length() == 0) return;
        if (m == 3) {
            if (s[0] == '0' && s.length() > 1) return;
            long tempInt = stol(s);
            if (tempInt <= 255) {
                string tempString = to_string(temp[0]) + "." + to_string(temp[1]) + "." + to_string(temp[2]) + ".";
                tempString += s;
                res.push_back(tempString);
                return;
            }
            else return;
        }
        for (int i = 1; i < s.length() && i <= 3; i++) {
            string left(&s[0], &s[i]);
            string right(&s[i], &s[s.size()]);
            if (left.size() > 1 && left[0] == '0') continue;
            int leftVal = stol(left);
            if (leftVal > 255) break;
            temp[m] = leftVal;
            runner(right, m + 1);
        }
    }
public:
    vector<string> restoreIpAddresses(string s) {
        if (s.length() > 12) return {};
        temp = vector<int>(4, int(0));
        runner(s, 0);
        return res;
    }
};