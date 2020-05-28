#include <vector>

using std::vector;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        int targetPoint;
        if (!nums.size()) return {-1, -1};
        while (1) {
            int mid = (left + right) / 2;
            if (right - left <= 2) {
                if (nums[left] == target) targetPoint = left;
                else if (nums[mid] == target) targetPoint = mid;
                else if (nums[right] == target) targetPoint = right;
                else return {-1, -1};
                break;
            }
            if (nums[mid] > target) right = mid;
            else if (nums[mid] < target) left = mid;
            else {
                targetPoint = mid;
                break;
            }
        }

        int resLeft;
        left = 0, right = targetPoint;
        while (1){
            int mid = (left + right) / 2;
            if (right - left <= 2) {
                if (nums[mid] < target) resLeft = right;
                else if (nums[left] < target) resLeft = mid;
                else if ((left != 0 && nums[left - 1] < target) || (nums[left] == target && left == 0)) resLeft = left;
                break;
            }
            if (nums[mid] == target) right = mid;
            else left = mid;
        }
        
        int resRight;
        left = targetPoint, right = nums.size() - 1;
        while (1){
            int mid = (left + right) / 2;
            if (right - left <= 2) {
                if (nums[mid] > target) resRight = left;
                else if (nums[right] > target) resRight = mid;
                else if ((right != nums.size() - 1 && nums[right + 1] > target) || (nums[right] == target && right == nums.size() - 1)) resRight = right;
                break;
            }
            if (nums[mid] == target) left = mid;
            else right = mid;
        }

        return {resLeft, resRight};
    }
};