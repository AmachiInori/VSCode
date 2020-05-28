#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeOuterParentheses(string S) {
        stack<char> par;
        string res;
        int lastLoca = 0;
        for (int i = 0; i < S.length(); i++){
            if (S[i] == '(') par.push('(');
            else if (S[i] == ')') par.pop();
            if (par.empty()) {
                S[lastLoca] = ' ';
                S[i] = ' ';
                lastLoca = i + 1;
            }
        }
        for (int i = 0; i < S.length(); i++)
            if (S[i] != ' ') res.push_back(S[i]);
        
        return res;
    }
};