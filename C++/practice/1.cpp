#include <bits/stdc++.h>
using namespace std;

void printL(int nums, ...) {
	va_list args;
	va_start(args, nums);
	for (int i = 0; i < nums; i++) {
		cout << va_arg(args, int);
	}
	va_end(args);
	return;
}

int main(){
	printL(5);
	return 0;
}