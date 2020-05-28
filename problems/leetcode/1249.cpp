#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> pat;
        string res;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') pat.push(i);
            else if (s[i] == ')') {
                if (pat.empty()) s[i] = ' ';
                else pat.pop();
            }
        }
        while (!pat.empty()) {
            s[pat.top()] = ' ';
            pat.pop();
        }
        for (int i = 0; i < s.length(); i++) 
            if (s[i] != ' ') res.push_back(s[i]);
        return res;
    }
};