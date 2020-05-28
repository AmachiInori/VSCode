#include <iostream>
#include <vector>
#include <string>

using std::string;
using std::vector;

class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int res = 0;
        int temp1 = 0, temp2 = 0;
        int loca = 0;
        for (int i = 0; i < arr.size() - 1; i++){
            for (int j = arr.size() - 1; j > i; j--){
                loca = j - 1;
                temp1 = arr[i];
                temp2 = arr[j];
                for (int k = i + 1; k < j; k++)
                    temp1 ^= arr[k];
                if (temp1 == temp2) res++;
                while (loca > i) {
                    temp1 ^= arr[loca];
                    temp2 ^= arr[loca];
                    loca--;
                    if (temp1 == temp2) res++;
                }
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> test = {2,3,1,6,7};
    s.countTriplets(test);
    return 0;
}