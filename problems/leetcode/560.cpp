#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <string>
#include <cmath>
#include <hash_map>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> hash;
        hash[0] = 1;
        int sum = 0, count = 0;
        for (auto &i : nums) {
            sum += i;
            if (hash.find(sum - k) != hash.end()) count += hash[sum - k];
            hash[sum]++;
        }
        return count;
    }
};