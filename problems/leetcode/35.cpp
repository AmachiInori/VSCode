#include <vector>

using std::vector;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (right - left >= 1) {
            int mid = (left + right) / 2;
            if (right - left <= 2) {
                if (nums[left] >= target) return left;
                else if (nums[mid] >= target) return mid;
                else if (nums[right] >= target) return right;
                else return right + 1;
            }
            if (nums[mid] > target) right = mid;
            else if (nums[mid] < target) left = mid;
            else return mid;
        }
        if (nums[0] >= target) return 0;
        else return 1;
    }
};