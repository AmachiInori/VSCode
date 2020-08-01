#pragma once
#ifndef __VECTOR_DRAW_H__
#define __VECTOR_DRAW_H__
#include <graphics.h>
#include <vector>
#include <string>
#include <iostream>
#define INT 0
#define DOUBLE 1

using namespace std;

class arrDraw {
private:
	unsigned int windowHeight = 720;
	unsigned int windowLength = 960;
	unsigned int left = 96;
	unsigned int up = 120;
	unsigned int right = 864;
	unsigned int down = 600;

	void _drawBar(vector<double> arr);
	void _drawBlock(vector<double> arr, int type);
	void _drawLine(vector<double> arr);
public:
	arrDraw() {};
	arrDraw(unsigned int length, unsigned int height);
	void drawBar(vector<int> const &arr);
	void drawBar(vector<double> const &arr);
	void drawBlock(vector<int> const &arr);
	void drawBlock(vector<double> const &arr);
};

arrDraw::arrDraw(unsigned int length, unsigned int height) : windowHeight(height), windowLength(length) {
	left = windowLength / 10;
	right = left * 9;
	up = windowHeight / 6;
	down = up * 5;
}

void arrDraw::_drawBar(vector<double> arr) {
	double arrMax = INT_MIN;
	double arrMin = INT_MAX;
	for (auto &i : arr) {
		if (i > arrMax)
			arrMax = i;
		if (i < arrMin)
			arrMin = i;
	}
	int zeroPoint = (arrMin < 0) ? (int)(arrMax / (arrMax - arrMin) * (down - up) + up) : down;//改算法 全负不支持
	for (auto &i : arr)
		i = i / arrMax * (zeroPoint - up);

	if (windowLength * 8 / 10 < arr.size()) throw ("too much items, use bigger window");
	int stepLength = (windowLength * 8 / 10) / arr.size();
	int spaceLength = ((5 - (int)arr.size() / 80) >= 1) ? (5 - arr.size() / 80) : 1; //改算法 否则不适配高分辨率
	double rate = 1.0;

	initgraph(windowLength, windowHeight);
	setfillcolor(BLACK);

	setfillcolor(WHITE);
	setlinecolor(WHITE);
	setlinestyle(PS_SOLID, 1);
	for (size_t i = 0; i < arr.size(); i++){
		int barLeft = left + stepLength * i + spaceLength;
		int barTop = zeroPoint - arr[i] * rate;
		int barRight = left + stepLength * (i + 1);
		int barDown = zeroPoint;
		fillrectangle(barLeft, barTop, barRight, barDown);
	}
	setlinecolor(BLUE);
	setlinestyle(PS_SOLID, 1);
	line(left, zeroPoint, right, zeroPoint);
	cin.get();
}

void arrDraw::_drawBlock(vector<double> arr, int type) {
	unsigned int blockLength = 60;
	unsigned int blockHeight = 40;
	int lines = 0;
	int nowLeft = left + blockLength * 2;
	int nowRight = left + blockLength * 3;
	int nowUp = up;

	vector<int> intArr;
	initgraph(windowLength, windowHeight);
	setfillcolor(BLACK);
	setlinecolor(WHITE);
	if (type == INT) {
		for (auto &i : arr)
			intArr.push_back((int)i);
	}
	for (size_t i = 0; i < arr.size(); i++){
		fillrectangle(nowLeft, nowUp + blockHeight * lines, nowRight, nowUp + blockHeight * (lines + 1));
		int digitY = nowUp + blockHeight * lines + 15;
		int digitX = nowLeft + 5;
		char* theStr;
		string strTemp = type == INT ? to_string(intArr[i]) : to_string(arr[i]);
		while (strTemp.size() > 6)
			strTemp.pop_back();
		outtextxy(digitX, digitY, (LPCTSTR)strTemp.data());
		if (nowLeft >= right - blockLength) {
			nowLeft = left - blockLength;
			nowRight = left;
			lines++;
		}
		if (nowUp + blockHeight * (lines + 1) >= down) throw("too much items, use bigger window");
		nowLeft += blockLength;
		nowRight += blockLength;
	}
	cin.get();
	closegraph();
}

void arrDraw::_drawLine(vector<double> arr) {

}

void arrDraw::drawBar(vector<int> const &arr) {
	vector<double> newarr;
	for (size_t i = 0; i < arr.size(); i++) {
		newarr.push_back((double)arr[i]);
	}
	_drawBar(newarr);
	return;
}

void arrDraw::drawBar(vector<double> const &arr) {
	vector<double> newarr = arr;
	_drawBar(newarr);
	return;
}

void arrDraw::drawBlock(vector<int> const &arr) {
	vector<double> newarr;
	for (size_t i = 0; i < arr.size(); i++) {
		newarr.push_back((double)arr[i]);
	}
	_drawBlock(newarr, INT);
	return;
}

void arrDraw::drawBlock(vector<double> const &arr) {
	_drawBlock(arr, DOUBLE);
	return;
}

#endif