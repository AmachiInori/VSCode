#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    int jump(vector<int>& nums) {
        int count = 0;
        for (int i = 0; i < nums.size() - 1; ){
            int maxLoca = i;
            int max = INT_MIN;
            for (int j = i + 1; j <= i + nums[i] && j < nums.size(); j++){
                int temp = nums[j] + j;
                if (temp >= nums.size()) temp = nums.size() - 1;
                if (temp >= max) {
                    maxLoca = j;
                    max = temp;
                }
            }
            i = maxLoca;
            count++;
        }
        return count;
    }
};

int main(){
    Solution s;
    vector<int> temp = {2,3,1};
    s.jump(temp);
    return 0;
}