#pragma once
#include "linearAnalysis.h"
#include "functionDraw.h"
#include "smooth.h"
#include "message.h"

void expr2() {
	cout << "�����·��������ʵ�����ݣ������������������ʽ��\ntemperature data������������-1 -1\n";
	cout << "ʾ��������������:\n30 100\n35 120\n37 140\n-1 -1\n";
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

	cout << "----------------------------\n��������ǣ�\n";
	cout << "���   temperature   data";
	for (int i = 0; i < origin.size(); i++) {
		cout << i << "   " << origin[i].first << "   " << origin[i].second << "\n";
	}
	cout << "�����޸ģ�������reinput + �޸���������� + ���е�����(2��)\n";
	cout << "ʾ��: reinput 2 100 9\n";
	cout << "�粻���޸Ļ��޸Ľ�����������confirm";

	string commad;
	cin >> commad;
	while (commad == "reinput") {
		int point;
		cin >> point;
		while (point >= origin.size() || point < 0) {
			cout << "��ŷǷ�������������";
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
	cout << "�Ʋ�Ĺյ����λ��" << smoothRes.first[maxPoint] << "\n";
}