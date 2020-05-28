#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<int> index;
public:
    Solution(vector<int>& nums) {
        index = nums;
    }
    
    int pick(int target) {
        vector<int> temp;
        for (int i = 0; i < index.size(); i++) {
            if (index[i] == target) temp.push_back(i);
        }
        return temp[(rand() % temp.size())];
    }
};