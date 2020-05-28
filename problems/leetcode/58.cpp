#include <bits/stdc++.h>
using namespace std;

string split_String(string str){
	istringstream ss(str);
	string s;
    string res;
	while(ss >> s) res = s;
    return res;
}

class Solution {
public:
    int lengthOfLastWord(string s) {
        return split_String(s).length();
    }
};