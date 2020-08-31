#pragma once
#include "linearAnalysis.h"
#include "functionDraw.h"
#include "smooth.h"
#include "message.h"

void expr2() {
	cout << "";
	vector <pair<double, double>> origin;
	while (1) {
		double tempTR, tempData;
		cin >> tempTR >> tempData;
		if (tempTR == -1 && tempData == -1)
			break;
		else {
			origin.push_back({tempTR, tempData});
		}
	}
	/* 处理坏数据 */

	pair<vector<double>, vector<double>> smoothRes;
	smooth _smo(origin);
	smoothRes = _smo.runSmooth();
	int maxPoint;
	double max = DBL_MIN;
	for (int i = 0; i < smoothRes.second.size(); i++) {
		
	}
}