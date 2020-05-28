#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    int fib(int N) {
        vector<int> temp = vector(N + 2, 0);
        temp[1] = 1;
        for (int i = 2; i <= N; i++){
            temp[i] = temp[i - 1] + temp[i - 2];
        }
        return temp[N];
    }
};