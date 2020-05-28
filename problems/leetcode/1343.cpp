#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int temp = 0, res = 0;
        for (int i = 0; i < k; i++){
            temp += arr[i];
        }
        if (temp >= threshold * k) res++;
        for (int i = 0; i < arr.size() - k; i++) {
            temp -= arr[i];
            temp += arr[i + k];
            if (temp >= threshold * k) res++;
        }
        return res;
    }
};