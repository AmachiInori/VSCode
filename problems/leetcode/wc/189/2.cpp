#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void split_String(vector<string> &ves,string str){
	    istringstream ss(str);
	    string s;
	    while(ss >> s)
		    ves.push_back(s);
    }

    string arrangeWords(string text) {
        text[0] += 32;
        vector<vector<string>> dict;
        dict.resize(100010);
        vector<string> temp;
        split_String(temp, text);
        for (auto i : temp) {
            dict[i.length()].push_back(i);
        }
        string res;
        for (int i = 0; i < dict.size(); i++) {
            for (int j = 0; j < dict[i].size(); j++) {
                for (int k = 0; k < dict[i][j].length(); k++){
                    res.push_back(dict[i][j][k]);
                }
                res.push_back(' ');
            }
        }
        res.pop_back();
        res[0] -= 32;
        return res;
    }
};