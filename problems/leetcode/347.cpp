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
        })
        priority_queue<int> heap;
        for_each(nums.begin(), nums.end(), [&heap](pair<int, int> temp) {
            heap.
        });
    }
};