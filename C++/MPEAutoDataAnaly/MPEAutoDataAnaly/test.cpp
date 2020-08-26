#include "linearAnalysis.h"
#include "smooth.h"

int main() {
	vector<pair<double, double>> tv = {
		{1, -5},
		{2, 5},
		{3, -5},
		{4, 5},
		{5, -5},
		{6, 5}
	};
	smooth testS(tv);
	auto res = testS.runSmooth();
	funcDraw test(res.first, res.second);
	test.drawFunction(1, 2);
	return 0;
}