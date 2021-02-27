#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        size_t res = 0;
        sort(nums.begin(), nums.end());
        unordered_map<int, vector<int>> hash;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = nums.size() - 1; j > i; j--) {
                int temp = nums[i] * nums[j];
                if (hash.find(temp) != hash.end()) hash[temp][2]++;
                else hash[nums[i] * nums[j]] = { i, j, 1 };
            }
        }
        for (int i = 0; i < nums.size(); i++) {
            for (int j = nums.size() - 1; j > i; j--) {
                int temp = nums[i] * nums[j];
                if (hash.find(temp) != hash.end() && 
                    hash[temp][0] != i &&
                    hash[temp][1] != j &&
                    hash[temp][0] != j &&
                    hash[temp][1] != i)
                    res += hash[temp][2];
            }
        }
        return res * 4;
    }
};

int main() {
    Solution test;
    vector<int> testV = {2,3,4,6,8,12};
    test.tupleSameProduct(testV);
    return 0;
}