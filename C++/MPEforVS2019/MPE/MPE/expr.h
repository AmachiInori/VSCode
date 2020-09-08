#pragma once
#include "linearAnalysis.h"
#include "functionDraw.h"
#include "smooth.h"
#include "message.h"
#include <fstream>

void dataInput(vector<pair<double, double>> &origin, string FST, string SST) {
	origin.clear();
	cout << "�����·��������ʵ�����ݣ������������������ʽ��\n" << "{{" << FST << "}} {{" << SST << "}}\n����������-1 -1\n";
	cout << "ʾ��������������:\n30 100\n35 120\n37 140\n-1 -1\n";
	cout << "-----------------------------------------------\n";
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
		if (temp != 'Y' && temp != 'y') return dataInput(origin, FST, SST);
		cout << "\nǿ�����У������Ҳ�����\n";
	}

	cout << "-----------------------------------------------\n��������ǣ�\n";
	cout << "    ���       " << FST << "    " << SST << "\n";
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
		cout << "    ���   " << FST << "        " << SST << "\n";
		for (int i = 0; i < origin.size(); i++) {
			cout << setw(8) << right << i << setw(8) << right << origin[i].first << setw(8) << right << origin[i].second << "\n";
		}
		cout << "���޸Ľ�����������confirm����������޸ģ�������reinput\n";
		cin >> commad;
		
		if (commad == "confirm") break;
	}
}

void dataInput(vector<double> &origin, string FST) {
	origin.clear();
	cout << "�����·��������ʵ�����ݣ������������������ʽ��\n{{" << FST  << "}}\n����������-1\n";
	cout << "ʾ��������������:30 100 35 120 37 140 -1\n";
	cout << "-----------------------------------------------\n";

	while (1) {
		double tempData;
		cin >> tempData;
		if (tempData == -1)
			break;
		else {
			origin.push_back(tempData);
		}
	}

	cout << "-----------------------------------------------\n��������ǣ�\n";
	cout << "    ���   " << FST << "\n";
	for (int i = 0; i < origin.size(); i++) {
		cout << setw(8) << right << i << setw(8) << right << origin[i] << "\n";
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
		cin >> origin[point];
		cout << "�ɹ��޸ĵ�" << point << "��Ϊ" << origin[point] << "\n";
		cout << "-----------------------------------------------\n��������ǣ�\n";
		cout << "    ���   " << FST << "\n";
		for (int i = 0; i < origin.size(); i++) {
			cout << setw(8) << right << i << setw(8) << right << origin[i] << "\n";
		}
		cout << "���޸Ľ�����������confirm����������޸ģ�������reinput\n";
		cin >> commad;
		
		if (commad == "confirm") break;
	}
}

int expr3() {
	cin.clear();
	cout << "\n-----------------------------------------------";
	cout << "\n���ӳ��������ڲ�������ʵ��:ʵ��3 ���������������������ʵĲⶨ\n";
	vector<double> mean(4, 0);
	vector<vector<double>> origin(4);
	vector<double> res(0);
	const vector<string> text = {
		"PE @ 190�� 2160g",
		"PE @ 190�� 5000g",
		"PP @ 230�� 2160g",
		"PP @ 230�� 5000g"
	};

	for (int i = 0; i < 4; i++) {
		cout << "\n������" << text[i] << "������(���Բ���5��)\n";
		dataInput(origin[i], "weight");
		int tempMax = DBL_MIN, tempMin = DBL_MIN;
		for_each(origin[i].begin(), origin[i].end(), [&tempMax, &tempMin, &origin, &mean, i](double temp) {
			mean[i] += temp / origin[i].size();
			tempMax = max(tempMax, temp);
			tempMin = min(tempMin, temp);
		});
		if (tempMax - tempMin > 0.1 * mean[i]) {
			cout << "\n��һ�����ݲ��������ֵ����Сֵ֮��С��ƽ��ֵ��10%�Ĺ涨���Ƿ��������룿(Y/N)";
			char tempC;
			cin >> tempC;
			if (tempC == 'Y' || tempC == 'y') i -= 1;
		}
	}

	for_each(mean.begin(), mean.end(), [&res](double temp) {
		res.push_back(temp * 600 / 10);
	});
	cout << "-----------------------------------------------\n";
	cout << "MFR�����:\n";
	cout << "   	״̬       " << "ƽ��W" << "     " << "MFR" << "\n";
	for (int i = 0; i < 4; i++) {
		cout << text[i] << setw(8) << right << mean[i] << setw(8) << right << res[i] << "\n";
	}
	cout << "\n�����������\n";
	cin.get();
	cin.get();
	return 0;
}

int expr2() {
	cout << "\n-----------------------------------------------";
	cout << "\n���ӳ��������ڲ�������ʵ��:ʵ��2  ��������ⶨ��N-�������ϩ�����������Һ�¶�\n";
	vector<pair<double, double>> origin;
	dataInput(origin, "T", "data");
	cout << "-----------------------------------------------\n";
	pair<vector<double>, vector<double>> smoothRes;
	cout << "ʹ������ƽ������������Ϣ\n";
	smooth _smo(origin);
	smoothRes = _smo.runSmooth(25, 9);
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
	funcDraw FD(smoothRes.first, smoothRes.second);
	cout << "�Ƿ���Ҫ������Ƶ�ͼ��?(Y/N)\n";
	cout << "��ע�⣬�뱣֤�ϴ�ͨ�����ӳ��򱣴��ͬ���ļ��ѱ�ת�ƣ����򽫱�����\n";
	string temp;
	cin >> temp;

	if (temp == "Y" || temp == "y")
		FD.save(getDesktopPath() + "\\expr2.png");
	cin.get();
	FD.compressed();
	FD.setXYComment("T/��", "Data");
	FD.drawFunction(0, 0);
	if (temp == "Y" || temp == "y")
		cout << "ͼ�񱣴�����" << getDesktopPath() << "\n";
	cin.get();
	return 0;
}

int expr7() {
	cout << "\n-----------------------------------------------";
	cout << "\n���ӳ��������ڲ�������ʵ��:ʵ��7  ����ź�ת������";
	cout << "\n-----------------------------------------------";
	ifstream infile;
	ifstream infile2;
	infile.open(getDesktopPath() + "\\0.txt");
	infile2.open(getDesktopPath() + "\\1.txt");
	while (!infile || !infile2) {
		cout << "\nδ��⵽������ʵ�������ĵ�";
		cout << "\n���ڼ����򿪵��ļ����¼������ʵ�������ĵ���������Ϊ0.txt��1.txt\n";
		cout << "\n����������ļ���";
		string DESTCOM = "start \"\" \"" + getDesktopPath() + "\"";
		system(DESTCOM.data());
		cout << "\n����Ѿ��źã��������������";
		cin.get();
		infile.open(getDesktopPath() + "\\0.txt");
		infile2.open(getDesktopPath() + "\\1.txt");
	}
	
	cout << "\nԭʼ���ݶ�ȡ�ɹ�";
	vector<vector<pair<double, double>>> oriX(2);
	while (1) { //ȥ��ͷ��Ϣ
		string temp;
		getline(infile, temp);
		if (temp == "Potential/V, Current/A") {
			getline(infile, temp);
			break;
		}
	}
	while (!infile.eof()) {
		string temp;
		getline(infile, temp);
		for (int i = 0; i < temp.size(); i++) {
			if (temp[i] == ',') {
				temp.erase(i, 1);
			}
		}
		stringstream SS(temp);
		double tempDBLX, tempDBLY;
		SS >> tempDBLX >> tempDBLY;
		oriX[1].push_back({tempDBLX, tempDBLY});
	}
	infile.clear();
	infile.close();
	while (1) {
		string temp;
		getline(infile2, temp);
		if (temp == "Potential/V, Current/A") {
			getline(infile2, temp);
			break;
		}
	}
	while (!infile2.eof()) {
		string temp;
		getline(infile2, temp);
		for (int i = 0; i < temp.size(); i++) {
			if (temp[i] == ',') {
				temp.erase(i, 1);
			}
		}
		stringstream SS(temp);
		double tempDBLX, tempDBLY;
		SS >> tempDBLX >> tempDBLY;
		oriX[0].push_back({tempDBLX, tempDBLY});
	}
	smooth _smo0(oriX[0], 1), _smo1(oriX[1], 1);
	vector<pair<vector<double>, vector<double>>> smoRes = {_smo0.runLPSmooth(0.9), _smo1.runLPSmooth(0.9)};
	vector<vector<double>> resX;
	vector<vector<double>> resY;
	resX.push_back(smoRes[0].first);
	resX.push_back(smoRes[1].first);
	resY.push_back(smoRes[0].second);
	resY.push_back(smoRes[1].second);

	pair<double, double> maxI, U;
	for (int i = 0; i < resX[0].size(); i++) {
		if (abs(resY[0][i]) < 0.001) {
			U.first = resX[0][i];
			break;
		}
	}
	for (int i = 0; i < resX[1].size(); i++) {
		if (abs(resY[1][i]) < 0.001) {
			U.second = resX[1][i];
			break;
		}
	}
	for (int i = 0; i < resX[0].size(); i++) {
		if (abs(resX[0][i]) < 0.001) {
			maxI.first = resY[0][i];
			if (maxI.first < 0.001) maxI.first = 0;
			break;
		}
	}
	for (int i = 0; i < resX[1].size(); i++) {
		if (abs(resX[1][i]) < 0.001) {
			maxI.second = resY[1][i];
			if (maxI.second < 0.001) maxI.second = 0;
			break;
		}
	}
	cout << "\n��������0���Ʋ�ı��͹������" << setprecision(3) << maxI.first << "A\n";
	cout << "��������1���Ʋ�ı��͹������" << setprecision(3) << maxI.second << "A\n";
	cout << "��������0���Ʋ�Ŀ�·��ѹ��" << setprecision(3) << -U.first << "V\n";
	cout << "��������1���Ʋ�Ŀ�·��ѹ��" << setprecision(3) << -U.second << "V\n";
	cout << "��������0������Ĺ�繦����" << setprecision(3) << -U.first * maxI.first << "W\n";
	cout << "��������1������Ĺ�繦����" << setprecision(3) << -U.second * maxI.second << "W\n";
	funcDraw fc(resX, resY);
	cout << "\n�Ƿ���Ҫ������Ƶ�ͼ��?(Y/N)\n";
	cout << "��ע�⣬�뱣֤�ϴ�ͨ�����ӳ��򱣴��ͬ���ļ��ѱ�ת�ƣ����򽫱�����\n";
	string temp;
	cin >> temp;
	if (temp == "Y" || temp == "y")
		fc.save(getDesktopPath() + "\\expr7.png");
	cin.clear();
	fc.setXYComment("U/V", "I/A");
	fc.drawFunction(1,1);
	if (temp == "Y" || temp == "y")
		cout << "ͼ�񱣴�����" << getDesktopPath() << "\n";
	cin.get();
	cin.get();
	return 0;
}

int exprC1() {
	return 0;
}