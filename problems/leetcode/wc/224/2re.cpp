#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        size_t res = 0;
        unordered_map<int, bool> hash;
        for_each(nums.begin(), nums.end(), [&hash](auto num) {
            hash[num] = true;
        });
        for (size_t i = 0; i < nums.size(); i++) {
            hash[nums[i]] = false;
            for (size_t j = nums.size() - 1; j > i; j--) {
                if (hash[nums[j]] == false) continue;
                hash[nums[j]] = false;
                for (size_t k = 0; k < nums.size(); k++) {
                    if (hash[nums[k]] == false) continue;
                    if (nums[i] * nums[j] % nums[k] != 0) continue;
                    hash[nums[k]] = false;
                    int temp = nums[i] * nums[j] / nums[k];
                    if (hash.find(temp) != hash.end() && hash[temp] == true) res++;
                    hash[nums[k]] = true;
                }
                hash[nums[j]] = true;
            }
            hash[nums[i]] = true;
        }
        return res * 2;
    }
};