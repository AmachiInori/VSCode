#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<string> res;
    string temp;
public:
    bool isValid(string s) {
        stack<char> theStack;
        for (int i = 0; i< s.size(); i++) {
            if (s[i] == '(') theStack.push('(');
            if (s[i] == ')') {
                if (theStack.empty()) return false;
                else theStack.pop();
            }
        }
        if (theStack.empty()) return true;
        else return false;
    }
    void runner(int n, int last) {
        if (!n) {
            if (isValid(temp)) res.push_back(temp);
            return;
        }
        for (int i = last; i < temp.length(); i++) {
            temp[i] = '(';
            runner(n - 1, i + 1);
            temp[i] = ')';
        }
    }
    vector<string> generateParenthesis(int n) {
        temp = string(2 * n, ')');
        runner(n, 0);
        return res;
    }
};