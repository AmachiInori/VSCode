#include <bits/stdc++.h>
using namespace std;

int abc(int a, int b, int c) {
    if (a < 0 && b < 0 && c < 0) throw 1;
    if (a == 0 && b == 0 && c == 0) throw 2;
    return a + b + c;
}

int main() {
    try {cout << abc(-1, -2, -3);}
    catch(int c) {
        if (c == 1) cout << 1;
        if (c == 2) cout << 2;
        return 1;
    }
    return 0;
}