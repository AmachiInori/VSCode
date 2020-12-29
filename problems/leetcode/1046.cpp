#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int, vector<int>, less<int>> heap;
        for_each(stones.begin(), stones.end(), [&heap](int& temp) {
            heap.push(temp);
        });
        while (heap.size() > 1) {
            int bigger = heap.top();
            heap.pop();
            int smaller = heap.top();
            heap.pop();
            if (bigger != smaller) {
                heap.push(bigger - smaller);
            }
        }
        return heap.empty() ? 0 : heap.top();
    }
};