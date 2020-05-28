#include <bits/stdc++.h>
using namespace std;

class Solution {
    unordered_map<char, int> hash;
    unordered_map<char, int> Thash;
    vector<int> index;
    string res = "";
public:
    string minWindow(string s, string t) {
        for (auto &c : t) hash[c] = 0, Thash[c]++;
        for (int i = 0; i < s.length(); i++)
            if (hash.find(s[i]) != hash.end()) index.push_back(i);
        int right = 0, left = 0;
        if (index.empty()) return "";
        hash[s[index[0]]] = 1;
        while (right < index.size() && left <= right) {
            bool isFull = true;
            for (auto &it : hash){
                if (it.second < Thash[it.first]) {
                    isFull = false;
                    break;
                }
            }
            if (isFull) {
                if ((res.size() > index[right] - index[left] + 1) || res == "") 
                    res = string(&s[index[left]], &s[index[right] + 1]);
                hash[s[index[left]]]--;
                left++;
            } else {
                right++;
                if (right < index.size()) hash[s[index[right]]]++;
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    cout << s.minWindow("A", "B");
    return 0;
}