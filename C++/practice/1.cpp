#include <bits/stdc++.h>
using namespace std;

int main() {
    int testInt;
    int* intPointer = &testInt;
    cout << intPointer + 1 << "----" << &intPointer[1] << endl;
}