#pragma once
#include "functionDraw.h"

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
	if (m > 2) throw(_INVALID_MODE);
	if (end < start) swap(end, start);
	if (precision >(right - left)) throw(_TOO_BIG_PRE);
	if (precision < 1) throw(_INVALID_PRE);
	if (_type == polar && ((start < -31.3 || end > 31.3))) throw(_INDE_OVERFLOW);

	infDeal = (end - start) / 500;
	pair<double, double> MaxMinX = this->preProcessX(start, end);
	pair<double, double> MaxMinY = this->preProcessY(start, end);
	const double step = (double)(MaxMinX.first - MaxMinX.second) * (double)precision / (double)(right - left);

	double tempUnit;
	if (MaxMinX.second > 0) tempUnit = (right - left) / MaxMinX.first;
	else if (MaxMinX.first < 0) tempUnit = (right - left) / -MaxMinX.second;
	else tempUnit = (right - left) / (MaxMinX.first - MaxMinX.second);
	const double unitX = tempUnit;

	if (MaxMinY.second > 0) tempUnit = (down - up) / MaxMinY.first;
	else if (MaxMinY.first < 0) tempUnit = (down - up) / -MaxMinY.second;
	else tempUnit = (down - up) / (MaxMinY.first - MaxMinY.second);
	const double unitY = tempUnit;

	double tempZeroPoint;
	if (MaxMinX.second > 0) tempZeroPoint = left;
	else if (MaxMinX.first < 0) tempZeroPoint = right;
	else  tempZeroPoint = -MaxMinX.second * unitX + left;
	const double zeroPointX = tempZeroPoint;

	if (MaxMinY.first < 0) tempZeroPoint = up;
	else if (MaxMinY.second > 0) tempZeroPoint = down;
	else tempZeroPoint = down - (0 - MaxMinY.second) * unitY;
	const double zeroPointY = tempZeroPoint;

	this->drawUCS(zeroPointX, zeroPointY);
	this->printComment(start, end);

	pair<double, double> lastPair;
	for (double i = start; i - end < doubleErr; i += step) {
		double tempFunctionValue = functionRunnerY(i);
		int dealTime = 0;
		while (tempFunctionValue == BADNUMBER || fabs(tempFunctionValue) > infLimit) {
			double newPoint = i - infDeal;
			infDeal *= -2;
			tempFunctionValue = functionRunnerY(newPoint);
			dealTime++;
			if (dealTime >= maxDealTime) throw(_OVERFLOW);
		}

		double tempXValue = functionRunnerX(i);
		dealTime = 0;
		while (tempXValue == BADNUMBER || fabs(tempXValue) > infLimit) {
			double newPoint = i - infDeal;
			infDeal *= -2;
			tempXValue = functionRunnerX(newPoint);
			dealTime++;
			if (dealTime >= maxDealTime) throw(_OVERFLOW);
		}

		double xLoca = zeroPointX + tempXValue * unitX;
		double yLoca = zeroPointY - tempFunctionValue * unitY;
		if (i == start) {
			putpixel(xLoca, yLoca, WHITE);
			lastPair = { xLoca, yLoca };
		}
		else {
			putpixel(xLoca, yLoca, WHITE);
			if (m == lineMode) line(xLoca, yLoca, lastPair.first, lastPair.second);
			lastPair = { xLoca, yLoca };
		}
	}
	std::cin.get();
	closegraph();
}

pair<double, double> funcDraw::preProcessX(double start, double end) {
	double max = INT_MIN, min = INT_MAX;
	const double step = (end - start) / 20;
	for (double i = start; i < end; i += step) {
		double temp = functionRunnerX(i);
		int dealTime = 0;
		while (temp == BADNUMBER || fabs(temp) > infLimit) {
			double newPoint = i - infDeal;
			infDeal *= -2;
			temp = functionRunnerY(newPoint);
			dealTime++;
			if (dealTime >= maxDealTime) {
				pointErr err = { _OVERFLOW, i };
				throw(err);
			}
		}
		if (temp > max) max = temp;
		if (temp < min) min = temp;
	}
	return{ max + abs(max * zoomX), min - abs(min * zoomX) };
}

pair<double, double> funcDraw::preProcessY(double start, double end) {
	double max = INT_MIN, min = INT_MAX;
	const double step = (end - start) / 20;
	for (double i = start; i < end; i += step) {
		double temp = functionRunnerY(i);
		int dealTime = 0;
		while (temp == BADNUMBER || fabs(temp) > infLimit) {
			double newPoint = i - infDeal;
			infDeal *= -2;
			temp = functionRunnerY(newPoint);
			dealTime++;
			if (dealTime >= maxDealTime) {
				pointErr err = { _OVERFLOW, i };
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
		catch (const std::exception) {
			return BADNUMBER;
		}
		return res;
	}
	else {
		try {
			res = this->_functionX(x);
		}
		catch (const std::exception) {
			return BADNUMBER;
		}
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
		catch (const std::exception) {
			return BADNUMBER;
		}
		return res;
	}
	else {
		try {
			res = this->_functionY(x);
		}
		catch (const std::exception) {
			return BADNUMBER;
		}
		return res;
	}
}

int funcDraw::drawFunction(double start, double end, mode m, preci precision) {
	int exitNumber = 1;
	try {
		cout << "try drawing function. \n \n";
		exitNumber = this->_drawFunction(start, end, m, precision);
	}
	catch (error &e) {
		cout << "funcion drawing process crashed with expection:\n";
		if (e == _INVALID_MODE) {
			cout << "invalid mode:" << m;
			cout << "\n\ntry drawing with default mode \"lineMode\"?";
			std::cin.get();
			this->drawFunction(start, end, 0, 1);
			return 1;
		}
		if (e == _TOO_BIG_PRE) cout << "too big precision: " << precision;
		if (e == _INVALID_PRE) cout << "invalid precision: " << precision;
		if (e == _TOO_BIG_PRE || e == _INVALID_PRE) {
			cout << "\n\ntry drawing with default precision 1?";
			std::cin.get();
			this->drawFunction(start, end, m, 1);
			return 1;
		}
		if (e == _OVERFLOW) cout << "overflow";
		if (e == _INDE_OVERFLOW) cout << "independent variable overflow \npolar coordinates only support in (-31.4, 31.4)";
		std::cin.get();
	}
	catch (pointErr &e) {
		if (e.first == _OVERFLOW) cout << "overflow near x = " << e.second;
	}
	catch (const std::exception) {
		cout << "unknown error";
	}
	cout << "\nprocess finished with return value " << exitNumber << ".";
	std::cin.get();
	return exitNumber;
}

void funcDraw::printComment(double sta, double end) {
	settextstyle(25, 0, _T("Consolas"));
	stringstream SS;
	SS << "function: ";
	if (_type == normal) SS << "normal y-x x:";
	else if (_type == polar) SS << "polar r-¦È ¦È:";
	else if (_type == parametric) SS << "parametric y(t)-x(t) t:";
	SS << "[" << sta << ", " << end << "]";

	outtextxy(0, 0, SS.str().data());
}

void funcDraw::drawUCS(double ZPX, double ZPY) {
	initgraph(windowLength, windowHeight);

	line(left, ZPY, right, ZPY);
	line(ZPX, up, ZPX, down);
	line(right, ZPY, right - 10, ZPY + 5);
	line(right, ZPY, right - 10, ZPY - 5);
	line(ZPX + 5, up + 10, ZPX, up);
	line(ZPX - 5, up + 10, ZPX, up);

	settextstyle(25, 0, _T("Consolas"));
	outtextxy(ZPX + 10, ZPY + 10, "0");
	outtextxy(right, ZPY, "x");
	outtextxy(ZPX + 10, up, "y");
}

void funcDraw::drawPolarFunction(double start, double end, mode m, preci precision) {
	_type = polar;
	this->drawFunction(start, end, m, precision);
}