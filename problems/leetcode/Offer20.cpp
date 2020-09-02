#include <bits/stdc++.h>
using namespace std;

class Solution {
    int state = 0;
    bool isDigit(char c) { return (c >= '0' && c <= '9'); }
public:
    bool isNumber(string s) {
        while (!s.empty() && s.back() == ' ') s.pop_back();
        while (!s.empty() && s.front() == ' ') s.erase(0, 1);
        if (s.empty()) return false;
        for (int i = 0; i < s.size(); i++) {
            switch (state){
            case 0:
                if (s[i] == '+' || s[i] == '-' || isDigit(s[i])) {
                    state = 1;
                } else if (s[i] == '.')
                    state = 5;
                else 
                    return false;
                break;
            case 1:
                if (isDigit(s[i])) 
                    continue;
                else if (s[i] == '.') {
                    state = 2;
                } else if (s[i] == 'e' || s[i] == 'E') {
                    state = 6;
                } else
                    return false;
                break;
            case 2:
                if (isDigit(s[i]))
                    continue;
                else if (s[i] == 'e' || s[i] == 'E')
                    state = 6;
                else
                    return false;
                break;
            case 3:
                if (isDigit(s[i]))
                    state = 3;
                else 
                    return false;
                break;
            case 4:
                if (isDigit(s[i]))
                    continue;
                else 
                    return false;
                break;
            case 5:
                if (isDigit(s[i]))
                    state = 2;
                else
                    return false;
                break;
            case 6:
                if (s[i] == '+' || s[i] == '-')
                    state = 7;
                else if (isDigit(s[i]))
                    state = 3;
                else return false; 
                break;
            case 7:
                if (isDigit(s[i]))
                    state = 3;
                else return false;
            }
        }
        if (state == 5 || state == 6 || state == 7) return false;
        return true;
    }
};