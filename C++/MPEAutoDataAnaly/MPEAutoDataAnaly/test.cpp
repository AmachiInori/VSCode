#include "linearAnalysis.h"
#include "smooth.h"

int main() {
	vector<pair<double, double>> tv = {
		{0, 0},
		{1, 5},
		{2, 25},
		{3, 20},
		{4, 18},
		{5, 17},
		{6, 14},
		{7, 3},
		{8, -6},
		{9, -3},
		{10, 3},
		{11, 4},
		{12, 9}
	};
	smooth testS(tv);
	auto res = testS.runSmooth();
	funcDraw test(res.first, res.second);
	test.drawFunction(1, 2);
	return 0;
}