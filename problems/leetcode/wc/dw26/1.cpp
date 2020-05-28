#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxPower(string s) {
        int max = 0, temp = 0;
        for (int i = 0; i < s.length(); i++){
            temp = 0;
            for (int j = i; j < s.length(); j++){
                if (s[i] == s[j]){
                    temp++;
                    max = max > temp ? max : temp;
                }else break;
            }
        }
        return max;
    }
};