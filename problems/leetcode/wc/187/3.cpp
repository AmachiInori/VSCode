#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        if (nums.size() == 1) return 1;
        int left, right;
        int max, min;
        int maxRes = INT_MIN;
        for (int i = 0; i < nums.size(); i++){
            left = i, right = i;
            max = nums[i], min = nums[i];
            while (left != 0 && nums[left - 1] - min <= limit && max - nums[left - 1] <= limit) {
                left--;
                if (nums[left] < min) min = nums[left];
                else if (nums[left] > max) max = nums[left];
            }
            while (right != nums.size() - 1 && nums[right + 1] - min <= limit && max - nums[right + 1] <= limit) {
                right++;
                if (nums[right] < min) min = nums[right];
                else if (nums[right] > max) max = nums[right];
            }
            if (right - left + 1 > maxRes) maxRes = right - left + 1;
            i = right;
        }
        return maxRes;
    }
};

int main(){
    Solution s;
    vector<int> nums = {8,2,4,7};
    std::cout << s.longestSubarray(nums, 4);
    system("pause");
    return 0;
}