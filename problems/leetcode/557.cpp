#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
        istringstream SS(s);
        while (!SS.eof()) {
            string temp;
            SS >> temp;
            words.push_back(temp);
        }
        for_each(words.begin(), words.end(), [&](string &temp)->void {
            for (int i = 0; i < temp.length() / 2; i++) {
                swap(temp[i], temp[temp.length() - 1 - i]);
            }
        });
        ostringstream OS;
        for (int i = 0; i < words.size() - 1; i++) {
            OS << words[i] << ' ';
        }
        OS << words.back();
        return OS.str();
    }
};