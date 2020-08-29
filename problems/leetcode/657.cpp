#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool judgeCircle(string moves) {
        stack<char> upDown;
        stack<char> rightLeft;
        for_each(moves.begin(), moves.end(), [&upDown, &rightLeft](char temp){
            if (temp == 'R' || temp == 'L') {
                if (rightLeft.size() == 0 || temp == rightLeft.top()) {
                    rightLeft.push(temp);
                } else {
                    rightLeft.pop();
                }
            } else {
                if (upDown.size() == 0 || temp == upDown.top()) {
                    upDown.push(temp);
                } else {
                    upDown.pop();
                }
            }
        });
        return upDown.empty() && rightLeft.empty();
    }
};