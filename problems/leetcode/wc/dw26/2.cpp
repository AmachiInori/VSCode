#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isTrue(int a, int b) {
        int c;
	    c = (a > b) ? b : a;
	    while(a % c != 0 || b % c != 0) c--;
	    if (c != 1) return false;
        else return true;
    }
    vector<string> simplifiedFractions(int n) {
        vector<string> res;
        string temp;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j < i; j++) {
                if (isTrue(i, j)) {
                    res.push_back("");
                    temp = to_string(j);
                    for (int k = 0; k < temp.length(); k++) res.back().push_back(temp[k]);
                    res.back().push_back('/');
                    temp = to_string(i);
                    for (int k = 0; k < temp.length(); k++) res.back().push_back(temp[k]);
                }
            }
        }
        return res;
    }
};