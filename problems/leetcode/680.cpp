#include <bits/stdc++.h>
using namespace std;

class Solution {
    bool isDeleted = false;
public:
    bool validPalindrome(string s) {
        int strL = 0, strR = s.length() - 1;
        while (strR - strL >= 1) {
            if (s[strR] == s[strL]) strL++, strR--;
            else {
                if (isDeleted) return false;
                else {
                    isDeleted = true;
                    string sa = string(&s[strL], &s[strR]);
                    string sb = string(&s[strL + 1], &s[strR + 1]);
                    return validPalindrome(sa) || validPalindrome(sb);
                }
            }
        }
        if (strR - strL < 1) return true;
        return false;
    }
};