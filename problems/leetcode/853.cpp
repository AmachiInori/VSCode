#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        int left = 0, right = A.size() - 1;
        int mid;
        while(1) {
            mid = (left + right) / 2;
            if (A[mid] > A[mid + 1] && A[mid] < A[mid - 1]) right = mid;
            else if (A[mid] < A[mid + 1] && A[mid] > A[mid - 1]) left = mid;
            else return mid;
        }
        return mid;
    }
};