#include <bits/stdc++.h>
using namespace std;

class Solution {
    string remain;
    string res;
    vector<int> jiecheng = {1, 1};
    void estString(int n, int k) {
        if (n == 0) return;
        int loca = (k - 1) / jiecheng[n - 1];
        res.push_back(remain[loca]);
        remain.erase(loca, 1);
        estString(n - 1, (k - 1) % jiecheng[n - 1] + 1);
    }
public:
    string getPermutation(int n, int k) {
        for (int i = 1; i <= n; i++) {
            remain.push_back(i + '0');
        }
        for (int i = 2; i <= n; i++) {
            jiecheng.push_back(jiecheng.back() * i);
        }
        estString(n, k);
        return res;
    }
};

int main() {
    Solution s;
    cout << s.getPermutation(3,3);
    return 0;
}