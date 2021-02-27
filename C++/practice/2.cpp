#include <bits/stdc++.h>
#define times 30
using namespace std;

struct test {
    int a;
    char b;
    short d;
    int c;
};

struct test2 {
    int a;
    char b;
    int c;
    short d;
};

int main() {
    std::cout << sizeof(test) << '\n';
    std::cout << sizeof(test2) << '\n';
    max({1,2,3,4,5});
    return 0;
}