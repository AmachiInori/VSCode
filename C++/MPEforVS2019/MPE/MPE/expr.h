#pragma once
#include "linearAnalysis.h"
#include "functionDraw.h"
#include "smooth.h"
#include "message.h"

void expr2() {
	cout << "\n���ӳ��������ڲ�������ʵ��:ʵ��2  ��������ⶨ��N-�������ϩ�����������Һ�¶�\n";
	cout << "�����·��������ʵ�����ݣ������������������ʽ��\ntemperature data������������-1 -1\n";
	cout << "ʾ��������������:\n30 100\n35 120\n37 140\n-1 -1\n";
	cout << "-----------------------------------------------\n";
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

	if (origin.size() < 2) {
		cout << "����. ���������٣���������һ���ᴥ�������쳣\n��ʹ������ҲҪ����������\n����Y���� ������������\n";
		cin.get();
		char temp = cin.get();
		if (temp != 'Y' && temp != 'y') return expr2();
		cout << "\nǿ�����У������Ҳ�����\n";
	}

	cout << "-----------------------------------------------\n��������ǣ�\n";
	cout << "    ���       T       data\n";
	for (int i = 0; i < origin.size(); i++) {
		cout << setw(8) << right << i << setw(8) << right << origin[i].first << setw(8) << right << origin[i].second << "\n";
	}
	cout << "�����޸ģ�������reinput\n";
	cout << "�粻���޸ģ�������confirm\n";

	string commad;
	cin >> commad;
	while (commad == "reinput" && origin.size() >= 1) {
		cout << "�������޸���������� + ���е�����(2��)\n";
		cout << "ʾ��: reinput 2 100 9\n";
		int point;
		cin >> point;
		while (point >= origin.size() || point < 0) {
			cout << "��ŷǷ������������룬�������벻������reinput\n";
			cin.clear();
			cin >> point;
		}
		cin >> origin[point].first >> origin[point].second;
		cout << "�ɹ��޸ĵ�" << point << "��Ϊ" << origin[point].first << " " << origin[point].second << "\n";
		cout << "-----------------------------------------------\n��������ǣ�\n";
		cout << "    ���       T       data\n";
		for (int i = 0; i < origin.size(); i++) {
			cout << setw(8) << right << i << setw(8) << right << origin[i].first << setw(8) << right << origin[i].second << "\n";
		}
		cout << "���޸Ľ�����������confirm����������޸ģ�������reinput\n";
		cin >> commad;
		
		if (commad == "confirm") break;
	}

	cout << "-----------------------------------------------\n";
	pair<vector<double>, vector<double>> smoothRes;
	cout << "ʹ������ƽ������������Ϣ\n";
	smooth _smo(origin);
	smoothRes = _smo.runSmooth();
	int maxPoint = 0;
	double max = DBL_MIN;
	for (int i = 0; i < smoothRes.second.size() - 1; i++) {
		if (abs((smoothRes.second[i + 1] - smoothRes.second[i]) / (smoothRes.first[i + 1] - smoothRes.first[i])) > max) {
			max = abs((smoothRes.second[i + 1] - smoothRes.second[i]) / (smoothRes.first[i + 1] - smoothRes.first[i]));
			maxPoint = i;
		}
	}
	cout << "\n-----------------------------------------------\n";
	cout << "\n�Ʋ��ͻ������λ��" << smoothRes.first[maxPoint] << "\n\n";
	cout << "-----------------------------------------------\n";
	cout << "������ʼ��ͼ\n";

	cin.get();
	cin.get();
	funcDraw(smoothRes.first, smoothRes.second).drawFunction(0, 0);
	cin.get();
}