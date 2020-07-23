#include "vectorDraw.h"
#include <math.h>

int main() {
	arrDraw a;
	vector<double> test;
	for (int i = 0; i < 250; i++) {
		test.push_back(rand() % 200 - 50);
	}
	a.drawBar(test);
	return 0;
}