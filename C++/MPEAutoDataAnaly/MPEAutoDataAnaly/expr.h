#pragma once
#include "linearAnalysis.h"
#include "functionDraw.h"
#include "smooth.h"
#include "message.h"

void expr2() {
	cout << "请在下方输入你的实验数据，输入无需排序。输入格式：\ntemperature data，结束请输入-1 -1\n";
	cout << "示例的输入序列是:\n30 100\n35 120\n37 140\n-1 -1\n";
	cout << "----------------------------\n";
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

	cout << "----------------------------\n你的输入是：\n";
	cout << "序号   temperature   data";
	for (int i = 0; i < origin.size(); i++) {
		cout << i << "   " << origin[i].first << "   " << origin[i].second << "\n";
	}
	cout << "如需修改，请输入reinput + 修改行数的序号 + 该行的数据(2个)\n";
	cout << "示例: reinput 2 100 9\n";
	cout << "如不需修改或修改结束，请输入confirm";

	string commad;
	cin >> commad;
	while (commad == "reinput") {
		int point;
		cin >> point;
		while (point >= origin.size() || point < 0) {
			cout << "序号非法，请重新输入";
			cin.clear();
			cin >> point;
		}
		cin >> origin[point].first >> origin[point].second;
		cin >> commad;
		if (commad == "confirm") break;
	}

	pair<vector<double>, vector<double>> smoothRes;
	smooth _smo(origin);
	smoothRes = _smo.runSmooth();
	int maxPoint;
	double max = DBL_MIN;
	for (int i = 0; i < smoothRes.second.size() - 1; i++) {
		if (abs((smoothRes.second[i + 1] - smoothRes.second[i]) / (smoothRes.first[i + 1] - smoothRes.first[i])) > max) {
			max = abs((smoothRes.second[i + 1] - smoothRes.second[i]) / (smoothRes.first[i + 1] - smoothRes.first[i]));
			maxPoint = i;
		}
	}
	cout << "推测的拐点可能位于" << smoothRes.first[maxPoint] << "\n";
}