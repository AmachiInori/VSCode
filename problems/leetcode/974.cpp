#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
        unordered_map<int, int> hash;
        int temp(0), res(0);
        hash[0]++;
        for (int i = 0; i < A.size(); i++) {
            temp += A[i];
            temp %= K;
            if (temp < 0) temp += K;
            if (hash.find(temp) != hash.end()) res += hash[temp];
            hash[temp]++;
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<int> test = {4,5,0,-2,-3,1};
    cout << s.subarraysDivByK(test, 5);
    return 0;
}