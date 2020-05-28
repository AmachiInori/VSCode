#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.length() == 1 || s.length() == 0) return s.length();
        vector<int> index = vector<int>(128, -1);
        vector<int> charIndex = vector<int>(s.length(), 0);

        for (int i = 0; i < s.length(); i++){
            if(index[s[i]] != -1){
                charIndex[i] = index[s[i]];
            }
            index[s[i]] = i;
        }

        int max = 0;
        for (int i = 0; i < s.length(); i++){
            bool isZeroBad = false;
            int start = charIndex[i];
            for (int j = i; j >= charIndex[i]; j--){
                if (charIndex[j] > start) start = charIndex[j];
                if (j != 0 && s[j] == s[0]) isZeroBad = true;
            }
            int temp = i - start;
            if (start == 0 && !isZeroBad) temp++;
            if (temp >= max) max = temp;
        }
        return max;
    }
};

int main(){
    Solution s;
    string a = "jxd";
    std::cout << s.lengthOfLongestSubstring(a);
    system("pause");
    return 0;
}