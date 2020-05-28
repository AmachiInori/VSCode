#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxVowels(string s, int k) {
        if (s.empty()) return 0;
        int max = 0, temp = 0;
        for (int i = 0; i < k; i++){
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') temp++;
        }
        max = temp;
        for (int i = 0; i < s.length() - k; i++) {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') temp--;
            if (s[i + k] == 'a' || s[i + k] == 'e' || s[i + k] == 'i' || s[i + k] == 'o' || s[i + k] == 'u') temp++;
            max = std::max(max, temp);
        }
        return max;
    }
};