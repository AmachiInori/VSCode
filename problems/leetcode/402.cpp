#include <bits/stdc++.h>
using namespace std;

class pairLess {
    typedef pair<char, size_t> pir;
public:
    bool operator()(pir& a, pir& b) {
        return a.first < b.first;
    }
};

class Solution {
    size_t getZeroPoint(string num) {
        for (size_t i = 0; i < num.size(); i++) {
            if (num[i] == '0') return i;
        }
        return num.size();
    }
public:
    typedef pair<char, size_t> pir;
    string removeKdigits(string num, int k) {
        size_t zeroPoint = getZeroPoint(num);
        while (zeroPoint <= k) {
            k -= zeroPoint;
            for (; num[zeroPoint] == '0'; zeroPoint++);
            string temp = string(num.begin() + zeroPoint, num.end());
            num = temp;
        }
        priority_queue<pir, vector<pir>, pairLess> pqu;
        for (size_t i = 0; i < num.size(); i++) {
            pqu.push({num[i], i});
        } 
        while (k && !pqu.empty()) {
            size_t loca = pqu.top().second;
            num.erase(num.begin() + loca);
            pqu.pop();
            k--;
        }
        return num.empty() ? "0" : num;
    }
};

int main() {
    Solution test;
    cout << test.removeKdigits("10", 2);
    return 0;
}