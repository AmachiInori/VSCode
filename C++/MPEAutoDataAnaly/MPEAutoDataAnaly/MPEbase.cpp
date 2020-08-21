#pragma once
#include <vector>
#include <utility>
#include <algorithm>
#include <list>
#include <iostream>
#include <string>


std::pair<double, double> OLSlinaerAna(std::vector<double> x, std::vector<double> y) {
	if (x.size() != y.size()) { 
		std::cout << "two arrays of different sizes";
		return {};
	}
	double xSum = 0, ySum = 0, xSSum = 0;
	std::_For_each(x.begin(), x.end(), [&xSum](double temp) { xSum += temp; });
	std::_For_each(x.begin(), x.end(), [&xSSum](double temp) { xSSum += temp * temp; });
	std::_For_each(y.begin(), y.end(), [&ySum](double temp) { ySum += temp; });
	double xMean = xSum / x.size(), yMean = ySum / y.size(), xSMean = xSSum / x.size();

	double slope = 
}