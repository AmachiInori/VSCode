#pragma once
#include <graphics.h>
#include <math.h>
#include <vector>
#include <string>
#include <sstream>
#include <iostream>

using namespace std;

double defaultFunctionX(double x) { return x; }

namespace error {
	typedef int error;
	const static error _INVALID_MODE	= 1;
	const static error _TOO_BIG_PRE		= 2;
	const static error _OVERFLOW_		= 3;
	const static error _INVALID_PRE		= 4;
	const static error _INDE_OVERFLOW	= 5;
};

class funcDraw {
private:
	typedef unsigned short mode;
	typedef unsigned short preci;
	typedef pair<double, double> _minmaxs;
	typedef pair<unsigned int, double> pointErr;
	typedef int error;
	enum functionType { normal, polar, parametric };

	const static long maxDealTime = 255;
	static constexpr long infLimit = INT_MAX / 2;
	static constexpr long BADNUMBER = INT_MIN;
	static constexpr double doubleErr = 0.000001;

	double infDeal = 0.1;
	double zoomX = 0.3;
	double zoomY = 0.3;
	double XMax = 0, XMin = 0, YMax = 0, YMin = 0;

	const static mode lineMode = 0;
	const static mode pointMode = 1;
	functionType _type = normal;
	bool isGrid = false; //未实装
	bool isLowGraph = false;
	bool differentiable = true;

	unsigned int windowHeight = 720;
	unsigned int windowLength = 960;
	unsigned int left;
	unsigned int up;
	unsigned int right;
	unsigned int down;

	double(*_functionX)(double);
	double(*_functionY)(double);

	double functionRunnerX(double x);
	double functionRunnerY(double x);
	_minmaxs preProcessX(const double start, const double end);
	_minmaxs preProcessY(const double start, const double end);

	void printComment(const double sta, const double end);
	void drawUCS(const double ZPX, const double ZPY, const double unitX, const double unitY);

	int _drawFunction(double start, double end, mode m, preci precision);

public:
	explicit funcDraw(double(*function)(double), unsigned int length = 960, unsigned int height = 720);
	explicit funcDraw(double(*Xfunction)(double), double(*Yfunction)(double), unsigned int length = 960, unsigned int height = 720);

	int drawFunction(double start, double end, mode m = lineMode, preci precision = 1);
	int drawPolarFunction(double start = 0, double end = 6.29, mode m = lineMode, preci precision = 1);
};

funcDraw::funcDraw(double(*function)(double), unsigned int length, unsigned int height)
	: windowHeight(height), windowLength(length), _functionY(function), _functionX(defaultFunctionX) {
	left = windowLength / 10;
	right = left * 9;
	up = windowHeight / 10;
	down = up * 9;
}

funcDraw::funcDraw(double(*Xfunction)(double), double(*Yfunction)(double), unsigned int length, unsigned int height)
	: windowHeight(height), windowLength(length), _functionY(Yfunction), _functionX(Xfunction) {
	left = windowLength / 10;
	right = left * 9;
	up = windowHeight / 10;
	down = up * 9;
}

int funcDraw::_drawFunction(double start, double end, mode m, preci precision) {
	if (m > 2) throw(error::_INVALID_MODE);
	if (end < start) std::swap(end, start);
	if (precision > (right - left)) throw(error::_TOO_BIG_PRE);
	if (precision < 1) throw(error::_INVALID_PRE);
	if (_type == polar && ((start < -31.3 || end > 31.3))) throw(error::_INDE_OVERFLOW);

	infDeal = (end - start) / 500;
	_minmaxs MaxMinX = this->preProcessX(start, end);
	_minmaxs MaxMinY = this->preProcessY(start, end);
	XMax = MaxMinX.first, XMin = MaxMinX.second;
	YMax = MaxMinY.first, YMin = MaxMinY.second;
	const double step = (double)(XMax - XMin) * (double)precision / (double)(right - left);
	if ((XMax - XMin) > 10 * windowLength || (YMax - YMin) > 10 * windowHeight)
		isLowGraph = true;

	double tempUnit;
	if (XMin > 0) tempUnit = (right - left) / XMax;
	else if (XMax < 0) tempUnit = (right - left) / -XMin;
	else tempUnit = (right - left) / (XMax - XMin);
	const double unitX = tempUnit;

	if (YMin > 0) tempUnit = (down - up) / YMax;
	else if (YMax < 0) tempUnit = (down - up) / -YMin;
	else tempUnit = (down - up) / (YMax - YMin);
	const double unitY = tempUnit;

	double tempZeroPoint;
	if (XMin > 0) tempZeroPoint = left;
	else if (XMax < 0) tempZeroPoint = right;
	else  tempZeroPoint = -XMin * unitX + left;
	const double zeroPointX = tempZeroPoint;

	if (YMax < 0) tempZeroPoint = up;
	else if (YMin > 0) tempZeroPoint = down;
	else tempZeroPoint = down - (0 - YMin) * unitY;
	const double zeroPointY = tempZeroPoint;

	this->drawUCS(zeroPointX, zeroPointY, unitX, unitY);

	pair<double, double> lastPair;
	int j = 0;
	double slope, lastSlope;
	for (double i = start; i - end < doubleErr; i += step) {
		double tempFunctionValue = functionRunnerY(i);
		int dealTime = 0;
		while (tempFunctionValue == BADNUMBER || abs(tempFunctionValue) > infLimit) {
			double newPoint = i - infDeal;
			infDeal *= -2;
			tempFunctionValue = functionRunnerY(newPoint);
			dealTime++;
			if (dealTime >= maxDealTime) throw(error::_OVERFLOW_);
		}

		double tempXValue = functionRunnerX(i);
		dealTime = 0;
		while (tempXValue == BADNUMBER || abs(tempXValue) > infLimit) {
			double newPoint = i - infDeal;
			infDeal *= -2;
			tempXValue = functionRunnerX(newPoint);
			dealTime++;
			if (dealTime >= maxDealTime) throw(error::_OVERFLOW_);
		}

		double xLoca = zeroPointX + tempXValue * unitX;
		double yLoca = zeroPointY - tempFunctionValue * unitY;
		if (j == 0) {
			putpixel((int)xLoca, (int)yLoca, WHITE);
			lastPair = { xLoca, yLoca };
		}
		else {
			putpixel((int)xLoca, (int)yLoca, WHITE);
			if (m == lineMode) line((int)xLoca, (int)yLoca, (int)lastPair.first, (int)lastPair.second);
			slope = (yLoca - lastPair.second) / (xLoca - lastPair.first);
			if (j != 1) {
				slope = (yLoca - lastPair.second) / (xLoca - lastPair.first);
				if ((slope / lastSlope >= 3.0 || slope / lastSlope <= 0.3) && abs(slope - lastSlope) > 1.0) {
					differentiable = false;
				}
			}
			lastSlope = slope;
			if (abs(xLoca - lastPair.first) > 0.5 * abs(lastPair.first) && abs(yLoca - lastPair.second) > 0.5 * abs(lastPair.second)) {
				isLowGraph = true;
			}
			lastPair = { xLoca, yLoca };
		}
		j++;
	}
	this->printComment(start, end);
	std::cin.get();
	closegraph();
	return 0;
}

funcDraw::_minmaxs funcDraw::preProcessX(const double start, const double end) {
	double _max = INT_MIN, _min = INT_MAX;
	const double step = (end - start) / 100;
	for (double i = start; i < end; i += step) {
		double temp = functionRunnerX(i);
		int dealTime = 0;
		while (temp == BADNUMBER || abs(temp) > infLimit) {
			double newPoint = i - infDeal;
			infDeal *= -2;
			temp = functionRunnerY(newPoint);
			dealTime++;
			if (dealTime >= maxDealTime) {
				pointErr err = { error::_OVERFLOW_, i };
				throw(err);
			}
		}
		if (temp > _max) _max = temp;
		if (temp < _min) _min = temp;
	}
	return{ _max + abs(_max * zoomX), _min - abs(_min * zoomX) };
}

funcDraw::_minmaxs funcDraw::preProcessY(const double start, const double end) {
	double max = INT_MIN, min = INT_MAX;
	const double step = (end - start) / 100;
	for (double i = start; i < end; i += step) {
		double temp = functionRunnerY(i);
		int dealTime = 0;
		while (temp == BADNUMBER || abs(temp) > infLimit) {
			double newPoint = i - infDeal;
			infDeal *= -2;
			temp = functionRunnerY(newPoint);
			dealTime++;
			if (dealTime >= maxDealTime) {
				pointErr err = { error::_OVERFLOW_, i };
				throw(err);
			}
		}
		if (temp > max) max = temp;
		if (temp < min) min = temp;
	}
	return{ max + abs(max * zoomY), min - abs(min * zoomY) };
}

double funcDraw::functionRunnerX(double x) {
	double res;
	if (_type == polar) {
		try {
			res = this->_functionY(x);
			res = res * cos(x);
		}
		catch (const std::exception) { return BADNUMBER; }
		return res;
	}
	else {
		try { res = this->_functionX(x); }
		catch (const std::exception) { return BADNUMBER; }
		if (abs(res - x) > doubleErr) _type = parametric;
		return res;
	}
}

double funcDraw::functionRunnerY(double x) {
	double res;
	if (_type == polar) {
		try {
			res = this->_functionY(x);
			res = res * sin(x);
		}
		catch (const std::exception) { return BADNUMBER; }
		return res;
	}
	else {
		try { res = this->_functionY(x); }
		catch (const std::exception) { return BADNUMBER; }
		return res;
	}
}

void funcDraw::drawUCS(const double ZPX, const double ZPY, const double unitX, const double unitY) {
	initgraph(windowLength, windowHeight);

	line(left, (int)ZPY, right, (int)ZPY);
	line((int)ZPX, up, (int)ZPX, down);
	line(right, (int)ZPY, right - 10, (int)ZPY + 5);
	line(right, (int)ZPY, right - 10, (int)ZPY - 5);
	line((int)ZPX + 5, up + 10, (int)ZPX, up);
	line((int)ZPX - 5, up + 10, (int)ZPX, up);

	settextstyle(25, 0, (LPCTSTR)_T("Consolas"));
	outtextxy((int)ZPX + 10, (int)ZPY + 10, (LPCTSTR)"0");
	outtextxy(right, (int)ZPY, (LPCTSTR)"x");
	outtextxy((int)ZPX - 20, up + 5, (LPCTSTR)"y");

	auto getUnit = [=](double _max, double _min) {
		//找坐标轴分度
	};
}

void funcDraw::printComment(const double sta, const double end) {
	settextstyle(25, 0, (LPCTSTR)_T("Consolas"));
	stringstream SS;
	SS << "function: ";
	if (_type == normal) SS << "normal y-x x:";
	else if (_type == polar) SS << "polar r-θ θ:";
	else if (_type == parametric) SS << "parametric y(t)-x(t) t:";
	SS << "[" << sta << ", " << end << "]";
	outtextxy(5, 0, (LPCTSTR)SS.str().data());

	int errLoca = windowHeight;
	if (isLowGraph) {
		stringstream ERL;
		ERL << "warning: low image quality. Use smaller range.";
		outtextxy(5, errLoca -= 25, (LPCTSTR)ERL.str().data());
	}
	if (!differentiable) {
		stringstream ERND;
		ERND << "warning: non-differentiable point(s) in the image";
		outtextxy(5, errLoca -= 25, (LPCTSTR)ERND.str().data());
	}
	
}

int funcDraw::drawPolarFunction(double start, double end, mode m, preci precision) {
	_type = polar;
	return this->drawFunction(start, end, m, precision);
}

int funcDraw::drawFunction(double start, double end, mode m, preci precision) {
	int exitNumber = 1;
	try{
		cout << "-------------------------------\n";
		cout << "try drawing function. \n \n";
		exitNumber = this->_drawFunction(start, end, m, precision);
	}
	catch (error &e){
		cout << "funcion drawing process crashed with expection:\n";
		if (e == error::_INVALID_MODE) {
			cout << "invalid mode:" << m;
			cout << "\ntry drawing with default mode \"lineMode\"?\n";
			std::cin.get();
			this->drawFunction(start, end, 0, precision);
			return 1;
		}
		if (e == error::_TOO_BIG_PRE) cout << "too big precision: " << precision;
		if (e == error::_INVALID_PRE) cout << "invalid precision: " << precision;
		if (e == error::_TOO_BIG_PRE || e == error::_INVALID_PRE) {
			cout << "\ntry drawing with default precision 1?\n";
			std::cin.get();
			this->drawFunction(start, end, m, 1);
			return 1;
		}
		if (e == error::_OVERFLOW_) cout << "overflow";
		if (e == error::_INDE_OVERFLOW) cout << "independent variable overflow \npolar coordinates only support in (-31.4, 31.4)";
		std::cin.get();
	}
	catch (pointErr &e) {
		if (e.first == error::_OVERFLOW_) cout << "overflow near x = " << e.second;
	}
	catch (const std::exception) { cout << "unknown error"; }
	cout << "\nprocess finished with return value " << exitNumber << ".";
	cout << "\npress any key to exit.";
	std::cin.get();
	return exitNumber;
}