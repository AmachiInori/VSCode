#include <bits/stdc++.h>
using namespace std;

class Solution {
    int inner(string inner) {
        if (inner.size() == 0) return 0;
        int res;
        int rNumber = 0, yNumber = 0;
        for_each(inner.begin(), inner.end(), [&](char temp) {
            if (temp == 'r') rNumber++;
            else yNumber++;
        });
        res = rNumber;
        int left = inner.length() / 2, right = inner.length() / 2;
        while (left >= 0 && inner[left] == 'y') left--;
        while (right < inner.size() && inner[right] == 'y') right++;
        res = min(res, max(yNumber - right + left + 1, 0));
        return res;
    }
public:
    int minimumOperations(string leaves) {
        int res = 0;
        if (!(leaves.front() == 'r')) {
            res++;
            leaves.front() = 'r';
        }
        if (!(leaves.back() == 'r')) {
            res++;
            leaves.back() = 'r';
        }
        bool hasY = false;
        for (auto &i : leaves) {
            if (i == 'y') {
                hasY = true;
                break;
            }
        }
        if (!hasY) return res + 1;
        int left = 0, right = leaves.size() - 1;
        while (leaves[left] == 'r') left++;
        while (leaves[right] == 'r') right--;
        res += inner(string(&leaves[left], &leaves[right + 1]));
        return res;
    }
};

int main() {
    Solution s;
    cout << s.minimumOperations("rrryyryryrr");
    return 0;
}