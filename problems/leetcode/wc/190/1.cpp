#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void split_String(vector<string> &ves, string str){
	    istringstream ss(str);
	    string s;
	    while(ss >> s)
		    ves.push_back(s);
    }
    int isPrefixOfWord(string sentence, string searchWord) {
        vector<string> words;
        split_String(words, sentence);
        for (int i = 0; i < words.size(); i++) {
            if (words[i].length() < searchWord.size()) continue;
            int isTrue = true;
            for (int j = 0; j < searchWord.length(); j++) {
                if (words[i][j] != searchWord[j]) {
                    isTrue = false;
                    break;
                }
            }
            if (isTrue) return i;
        }
        return -1;
    }
};