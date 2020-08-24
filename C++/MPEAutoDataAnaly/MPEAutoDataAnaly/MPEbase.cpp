#pragma once
#include <vector>
#include <utility>
#include <algorithm>
#include <list>
#include <iostream>
#include <string>

namespace LinearError {
	typedef int error;
	const static error _DIFFERENT_SIZE = 1;
};

class linearAnalysis {
	typedef int error;
	std::pair<double, double> _OLSlinaerAna(const std::vector<double> &x, const std::vector<double> &y);
public:
	std::pair<double, double> linaerAna(const std::vector<double> &x, const std::vector<double> &y);
};

std::pair<double, double> linearAnalysis::_OLSlinaerAna(const std::vector<double> &x, const std::vector<double> &y) {
	if (x.size() != y.size()) throw LinearError::_DIFFERENT_SIZE;
	double xSum = 0, ySum = 0, xSSum = 0;
	std::_For_each(x.begin(), x.end(), [&xSum](double temp) { xSum += temp; });
	std::_For_each(x.begin(), x.end(), [&xSSum](double temp) { xSSum += temp * temp; });
	std::_For_each(y.begin(), y.end(), [&ySum](double temp) { ySum += temp; });
	double xMean = xSum / x.size(), yMean = ySum / y.size(), xSMean = xSSum / x.size();

	double slope = 
}

std::pair<double, double> linearAnalysis::linaerAna(const std::vector<double> &x, const std::vector<double> &y) {
	std::pair<double, double> res;
	try {
		res = _OLSlinaerAna(x, y)
	}
	catch (error e) {

	}
}