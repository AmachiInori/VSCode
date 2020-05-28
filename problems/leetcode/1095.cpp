#include <vector>
#include <iostream>

using std::vector;

class MountainArray {
    vector<int> str;
public:
    MountainArray(){
        str = {1,5,2};
    }
    int get(int index) {return str[index];}
    int length() {return str.size();}
};

class Solution {
public:
    vector<int> cache;
    int findNumber(MountainArray &mountainArr, int point) {
        if (cache[point] == -1)
            cache[point] = mountainArr.get(point);
        return cache[point];
    }

    int findInMountainArray(int target, MountainArray &mountainArr) {
        cache = vector<int>(mountainArr.length(), -1);
        int left = 0, right = mountainArr.length() - 1;
        int mid = (left + right) / 2;
        int maxPoint;
        while (right - left > 1) {
            mid = (left + right) / 2;
            if (findNumber(mountainArr, mid) > findNumber(mountainArr, mid - 1) && findNumber(mountainArr, mid) < findNumber(mountainArr, mid + 1))
                left = mid;
            else if (findNumber(mountainArr, mid) < findNumber(mountainArr, mid - 1) && findNumber(mountainArr, mid) > findNumber(mountainArr, mid + 1))
                right = mid;
            else {
                maxPoint = mid;
                break;
            }
        }

        left = 0, right = maxPoint;
        while (right - left >= 1){
            mid = (left + right) / 2;
            if (right - left <= 2) {
                if (findNumber(mountainArr, left) == target) return left;
                else if (findNumber(mountainArr, mid) == target) return mid;
                else if (findNumber(mountainArr, right) == target) return right;
                else break;
            }
            if (findNumber(mountainArr, mid) > target) right = mid;
            else if (findNumber(mountainArr, mid) < target) left = mid;
            else return mid;
        }
        
        left = maxPoint, right = mountainArr.length() - 1;
        while (right - left >= 1){
            mid = (left + right) / 2;
            if (right - left <= 2) {
                if (findNumber(mountainArr, left) == target) return left;
                else if (findNumber(mountainArr, mid) == target) return mid;
                else if (findNumber(mountainArr, right) == target) return right;
                else break;
            }
            if (findNumber(mountainArr, mid) > target) left = mid;
            else if (findNumber(mountainArr, mid) < target) right = mid;
            else return mid;
        }
        return -1;
    }
};

int main(){
    MountainArray a;
    Solution s;
    std::cout << s.findInMountainArray(2, a) << std::endl;
    system("pause");
    return 0;
}