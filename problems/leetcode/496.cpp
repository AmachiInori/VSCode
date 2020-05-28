#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> hash;
        vector<int> res(nums1.size(), -1);
        for (int i = 0; i < nums2.size(); i++)
            hash[nums2[i]] = i;
        for (int i = 0; i < nums1.size(); i++){
            for (int j = hash[nums1[i]]; j < nums2.size(); j++) {
                if (nums2[j] > nums1[i]) {
                    res[i] = nums2[j];
                    break;
                }
            }
        }
        return res;
    }
};