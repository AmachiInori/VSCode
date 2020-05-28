#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = -1, right = nums.size();
        int mid;
        if (nums.size() == 1) return 0;
        if (nums.size() == 2) return nums[0] > nums[1] ? 0 : 1;
        while(1) {
            mid = (left + right) / 2;
            if (mid == 0) {
                if (nums[0] < nums[1]) left = mid;
                else return mid;
            }else if (mid == nums.size() - 1) {
                if (nums[nums.size() - 1] < nums[nums.size() - 2]) right = mid;
                else return mid;
            }
            else if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1]) return mid;
            else if (nums[mid] > nums[mid - 1] && nums[mid] < nums[mid + 1]) left = mid;
            else if (nums[mid] < nums[mid - 1] && nums[mid] > nums[mid + 1]) right = mid;
            else if (nums[mid] < nums[mid - 1] && nums[mid] < nums[mid + 1]) left = mid;
        }
        return mid;
    }
};

