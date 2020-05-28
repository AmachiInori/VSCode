/*
 * @Author: your name
 * @Date: 2020-04-27 16:39:06
 * @LastEditTime: 2020-04-27 17:30:31
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \VSCode\problems\leetcode\Untitled-1.cpp
 */
#include <iostream>
#include <vector>

using std::vector;

class Solution{
public:
    int search(vector<int> &nums, int target) {
        if (nums.size() == 0) return -1;
        return binarySearch(nums, 0, nums.size() - 1, target);
    }
    int binarySearch(vector<int> &nums, int left, int right, int key) {
        int mid = (left + right) / 2;
        int res;
        if (right - left <= 2) {
            if (key == nums[left]) return left;
            else if (key == nums[mid]) return mid;
            else if (key == nums[right]) return right;
            else return -1;
        }
        
        if (key >= nums[left] && key <= nums[mid]) res = binarySearch(nums, left, mid, key);
        else if (key <= nums[right] && key >= nums[mid]) res = binarySearch(nums, mid, right, key);
        else if (key >= nums[left] && key >= nums[right]) {
            if (nums[mid] >= nums[right] && nums[mid] >= nums[left]) res = binarySearch(nums, mid, right, key);
            else res = binarySearch(nums, left, mid, key);
        }else if (key <= nums[left] && key <= nums[right]) {
            if (nums[mid] >= nums[right] && nums[mid] >= nums[left]) res = binarySearch(nums, mid, right, key);
            else res = binarySearch(nums, left, mid, key); 
        }else if (key > nums[right] && key < nums[left]) res = -1;
        return res;
    }
};

int main(){
    Solution s;
    vector<int> exa{6,7,1,2,3,4,5};
    int i = 6;
    std::cout << s.search(exa, i) << std::endl;
    system("pause");
    return 0;
}