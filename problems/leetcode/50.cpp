#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) return 1;
        if (n == -1) return 1 / x;
        else if (n > 0) {
            if (n % 2) {
                double temp = myPow(x, (n - 1) / 2);
                return temp * temp * x;
            }
            else {
                double temp = myPow(x, n / 2);
                return temp * temp;
            }
        } else {
            if (n % 2) {
                double temp = myPow(x, (n + 1) / 2);
                return temp * temp / x;
            }
            else {
                double temp = myPow(x, n / 2);
                return temp * temp;
            }
        }
    }
};