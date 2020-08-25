#include "MPEbase.h"

int main() {
	std::vector<double> testx({ 0, 3, 3.5, 5, 8, 10, 13 });
	std::vector<double> testy({ 1, 2, 3, 4, 5, 6, 7 });
	linearAnalysis sol;
	std::pair<double, double> res = sol.linaerAna(testx, testy);
	std::cout << res.first << "  " << res.second;
	std::cin.get();
	return 0;
}