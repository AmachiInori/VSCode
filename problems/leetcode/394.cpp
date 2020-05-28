#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isNum(char ch) {return (ch >= '0' && ch <= '9');}
    string decodeString(string s) {
        stack<int> numStack;
        stack<string> stringS;
        stringS.push("");
        int start;
        for (start = 0; (start < s.length() && !isNum(s[start])); start++)
            stringS.top().push_back(s[start]);
        string temp, tempS;
        bool isNumber(true);
        for (int i(start); i < s.length(); i++) {
            if (isNumber) {
                if (isNum(s[i])) temp.push_back(s[i]);
                else {
                    numStack.push(stoi(temp));
                    temp.erase();
                    stringS.push("");
                    isNumber = false;
                }
            } else {
                if (isNum(s[i])) {
                    isNumber = true;
                    temp.push_back(s[i]);
                } else if (s[i] == ']') {
                    tempS = stringS.top();
                    stringS.pop();
                    for (int j(0); j < numStack.top(); j++)
                        stringS.top() += tempS;
                    numStack.pop();
                } else {
                    stringS.top().push_back(s[i]);
                }
            }
        }
        return stringS.top();
    }
};