#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumOperations(string leaves) {
        int leftY = 0, rightY = leaves.size() - 1;
        int left = leaves.size() / 2 - 1, right = leaves.size() / 2;
        int res = 0;
        while (leaves[leftY] != 'y') leftY++;
        while (leaves[rightY] != 'y') rightY--;
        while (left > leftY) {
            if (leaves[left] == 'r') {
                swap(leaves[left], leaves[leftY]);
                while (leaves[leftY] != 'y') leftY++;
                res++;
            }
            left--;
        }
        while (right < rightY) {
            if (leaves[right] == 'r') {
                swap(leaves[right], leaves[rightY]);
                while (leaves[rightY] != 'y') rightY--;
                res++;
            }
            right++;
        }
        if (!(leaves.front() == 'r' && leaves.back() == 'r')) res++;
        return res;
    }
};

int main() {
    Solution s;
    s.minimumOperations("ryry");
    return 0;
}