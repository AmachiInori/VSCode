class Solution {
public:
    int mySqrt(int x) {
        long i;
        for (i = 0; ; i++){
            if (i * i > x) break;
        }
        return i - 1;
    }
};