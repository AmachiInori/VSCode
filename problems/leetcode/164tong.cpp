#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if (nums.size() < 2) return 0;
        int min = INT_MAX, max = INT_MIN;
        for (auto &i : nums) {
            if (i < min) min = i;
            if (i > max) max = i;
        }
        int number = (max - min + 1) / nums.size() + 1;
        vector<pair<int, int>> index((max - min) / number + 1, {INT_MAX, INT_MIN});
        for (auto &i : nums) {
            if (index[(i - min) / number].first > i) index[(i - min) / number].first = i;
            if (index[(i - min) / number].second < i) index[(i - min) / number].second = i;
        }
        for (int i = 1; i < index.size(); i++){
            if (index[i] == (pair<int, int>){INT_MAX, INT_MIN}) index[i] = index[i - 1];
        }
        int maxR = 0;
        for (int i = 0; i < index.size() - 1; i++){
            if (index[i + 1].first - index[i].second > maxR) maxR = index[i + 1].first - index[i].second;
        }
        return maxR;
    }
};

int main() {
    Solution s;
    vector<int> test = {1,1,1,1};
    cout << s.maximumGap(test);
    return 0;
}