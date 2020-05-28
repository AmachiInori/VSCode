#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        stack<pair<int, int>> nums;
        vector<int> res(T.size(), 0);
        for (int i = 0; i < T.size(); i++){
            if (nums.empty() || T[i] <= nums.top().first) nums.push({T[i], i});
            else {
                while (!nums.empty() && nums.top().first < T[i]) {
                    res[nums.top().second] = i - nums.top().second;
                    nums.pop();
                }
                nums.push({T[i], i});
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> test = {73, 74, 75, 76, 77, 78};
    s.dailyTemperatures(test);
    return 0;
}