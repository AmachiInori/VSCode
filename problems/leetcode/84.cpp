#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> up, down;
        vector<pair<int, int>> index(heights.size(), (pair<int, int>){-1, heights.size()});
        for (int i(0), j(heights.size() - 1); i < heights.size(); i++, j--) {
            if (up.empty() || heights[up.top()] < heights[i]) up.push(i);
            else {
                while (!up.empty() && heights[up.top()] > heights[i]) {
                    index[up.top()].second = i;
                    up.pop();
                }
                up.push(i);
            }
            if (down.empty() || heights[down.top()] < heights[j]) down.push(j);
            else {
                while (!down.empty() && heights[down.top()] > heights[j]) {
                    index[down.top()].first = j;
                    down.pop();
                }
                down.push(j);
            }
        }
        int max(0);
        for (int i(0); i < heights.size(); i++)
            max = std::max(max, heights[i] * (index[i].second - index[i].first - 1));
        return max;
    }
};