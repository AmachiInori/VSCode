#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for_each(nums.begin(), nums.end(), [&freq](int temp) {
            if (freq.find(temp) == freq.end()) {
                freq[temp] = 0;
            } else {
                freq[temp]++;
            }
        });
        priority_queue<pair<int, int>> heap;
        for_each(freq.begin(), freq.end(), [&heap](pair<int, int> temp) {
            pair<int, int> _temp = {temp.second, temp.first};
            heap.push(_temp);
        });
        vector<int> res;
        while (!heap.empty() && res.size() < k) {
            res.push_back(heap.top().second);
            heap.pop();
        }
        return res;
    }
};