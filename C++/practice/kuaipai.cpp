# include <algorithm>
# include <ctime>
# include <iostream>
# include <random>
# include <vector>

template <typename T>
inline void fsort(T arr[], const int len) {
    if (len <= 1)
        return;
    else {
        T pivot = *arr; // 不是所有的T都有缺省构造函数，但所有的T都有copy Cto
        std::srand(std::time(nullptr));
        int tmp = /* ((len - 2) > 0 ? (len - 2) : (len - 1)) */ len; // 就用len 没什么大不了的
        int empty_index = rand() % tmp;
        std::swap(pivot, arr[empty_index]); // 不建议直接交换，可能发生效率和稳定性问题
        int i = 0, j = len - 1;
        bool flag = true;
        while (i <= j) {
            if (flag) {
                if (j == empty_index) {
                    j--;
                    flag ^= true; // 避免"越过枢纽位置反向交换“
                    continue;
                } else {
                    if (arr[j] < pivot) {
                        flag ^= true;
                        std::swap(arr[j], arr[empty_index]);
                        empty_index = j;
                    }
                    j--;
                }
            } else {
                if (i == empty_index) {
                    i++;
                    flag ^= true; // 避免"越过枢纽位置反向交换“ 
                    continue;
                } else {
                    if (arr[i] > pivot) {
                        flag ^= true;
                        std::swap(arr[i], arr[empty_index]);
                        empty_index = i;
                    }
                    i++;
                }
            }
        }
        std::swap(arr[empty_index], pivot);
        fsort(arr, empty_index);
        fsort(arr + empty_index + 1, len - empty_index - 1); // **2 -> 1 2会导致无法完全划分**
    }
}

int main() {
    std::vector<int> test = {6,1,2,3,7,6,5,4,3,2,1};
    fsort(&*test.begin(), test.size());
    std::for_each(test.begin(), test.end(), [](auto temp) {
        std::cout << temp;
    });
    return 0;
}