#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res(nums.size() - k + 1, 0);
        deque<int> que;
        que.push_front(nums[0]);
        for (int i(1); i < k; i++) {
            if (nums[i] > que.front()) {
                que.pop_front();
                que.push_front(nums[i]);
            } else if (nums[i] <= que.front()) {
                while (!que.empty() && que.back() < nums[i]) que.pop_back();
                que.push_back(nums[i]);
            }
        }
        for (int i(0); i < res.size(); i++) {
            res[i] = que.front();
            if (nums[i] == que.front()) que.pop_front();
            while (!que.empty() && (i + k) < nums.size() && nums[i + k] > que.back()) que.pop_back();
            if ((i + k) < nums.size())que.push_back(nums[i + k]);
        }
        return res;
    }
};