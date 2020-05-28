#include <bits/stdc++.h>
using namespace std;

class Solution {
    unordered_map<char, int> hash;
    unordered_map<char, int> Thash;
    vector<int> index;
    string res;
public:
    void runner(string s, string t, int left, int right) {
        if (hash[s[index[left]]] == Thash[s[index[left]]] && hash[s[index[right]]] == Thash[s[index[right]]]) {
            if (res.length() > index[right] - index[left] + 1) res = string(&s[index[left]], &s[index[right] + 1]);
            return;
        }
        if (hash[s[index[left]]] > Thash[s[index[left]]]) {
            hash[s[index[left]]]--;
            runner(s, t, left + 1, right);
            hash[s[index[left]]]++;
        }
        if (hash[s[index[right]]] > Thash[s[index[right]]]) {
            hash[s[index[right]]]--;
            runner(s, t, left, right - 1);
            hash[s[index[right]]]++;
        }
        return;
    }
    string minWindow(string s, string t) {
        for (auto &c : t) hash[c] = 0, Thash[c]++;
        for (int i = 0; i < s.length(); i++) {
            if (hash.find(s[i]) != hash.end()) {
                index.push_back(i);
                hash[s[i]]++;
            }
        }
        for (unordered_map<char, int>::iterator it = hash.begin(); it != hash.end(); it++) {
            if (it -> second < Thash[it -> first]) return "";
        }
        res = s;
        runner(s, t, 0, index.size() - 1);
        return res;
    }
};

int main() {
    Solution s;
    cout << s.minWindow("ask_not_what_your_country_can_do_for_you_ask_what_you_can_do_for_your_country", "ask_country");
    return 0;
}