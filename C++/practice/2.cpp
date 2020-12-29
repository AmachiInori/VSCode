#include <bits/stdc++.h>
#define times 30
#define max 10
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
    return 0;
}