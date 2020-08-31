#include <bits/stdc++.h>
using namespace std;

class calcuTreeNode {
public:
    calcuTreeNode* Left;
    calcuTreeNode* Right;
    int value;

    explicit calcuTreeNode(int v) : value(v) {}
    int returnValue() {
        switch (this->value){
        case -1:
            return Left->returnValue() + Right->returnValue();
            break;
        case -2:
            return Left->returnValue() - Right->returnValue();
            break;
        default:
            return value;
            break;
        }
    }
};

class Solution {
    bool isWholeBrackets(string s) {
        stack<char> brackets;
        if (s.length() < 2) return false;
        for (int i = 0; i < s.length() - 1; i++) {
            if (s[i] == '(')
                brackets.push('(');
            else if (s[i] == ')')
                brackets.pop();
            if (brackets.size() == 0) 
                return false;
        }
        return true;
    }
public:
    calcuTreeNode* calculatePress(string s) {
        if (isWholeBrackets(s)) {
            return calculatePress(string(&s[1], &s[s.length() - 1]));
        }
        bool isNumber = true;
        for_each(s.begin(), s.end(), [&isNumber](char temp) {
            if (temp == '(' || temp == ')' || temp == '+' || temp == '-')
                isNumber = false;
        });
        if (isNumber) {
            int res = 0;
            for_each(s.begin(), s.end(), [&res](char temp) {
                res *= 10;
                res += temp - '0';
            });
            calcuTreeNode* tempPtN = new calcuTreeNode(res);
            return tempPtN;
        }
        stack<char> brackets;
        for (int i = s.length() - 1; i >= 0 ; i--) {
            if (s[i] == ')') brackets.push(')');
            else if (s[i] == '(') brackets.pop();
            if (brackets.empty() && (s[i] == '+' || s[i] == '-' )) {
                calcuTreeNode* temp = new calcuTreeNode(s[i] == '+' ? -1 : -2);
                temp->Left = calculatePress(string(&s[0], &s[i]));
                temp->Right = calculatePress(string(&s[i + 1], s.end().base()));
                return temp;
            } 
        }
        return nullptr;
    }
    int calculate(string s) {
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == ' '){
                s.erase(i, 1);
                i--;
            }
        }
        calcuTreeNode* res = calculatePress(s);
        return res->returnValue();
    }
};

int main(){
    Solution test;
    cout << test.calculate(" 2-(1 + 2) ");
    return 0;
}