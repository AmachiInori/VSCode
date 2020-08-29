#include <bits/stdc++.h>
using namespace std;

class Solution {
    bool isPalind(string s) {
        for (int i = 0; i < s.length() / 2; i++) {
            if (s[i] != s[s.length() - 1 - i]) return false;
        }
        return true;
    }
public:
    string shortestPalindrome(string s) {
        int longestPre = 0;
        string res;
        for (int i = s.length(); i > 0; i--) {
            if (isPalind(string(&s[0], &s[i]))) {
                longestPre = i;
                break;
            }
        }
        for (int i = s.length() - 1; i >= longestPre; i--) {
            res.push_back(s[i]);
        }
        res.append(s);
        return res;
    }
};

int main() {
    string te = "aacecaaa";
    Solution test;
    cout << test.shortestPalindrome(te);
    return 0;
}