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
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> hash;
        int count = 0;
        int max = 0;
        hash[0] = -1;
        for (int i = 0; i < nums.size(); i++){
            if (nums[i] == 1) count++;
            else count--;
            if (hash.find(count) == hash.end()) hash[count] = i;
            else max = (max > i - hash[count]) ? max : (i - hash[count]);
        }
        return max;
    }
};