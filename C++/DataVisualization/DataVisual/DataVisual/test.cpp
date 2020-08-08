//#include <graphics.h>
//#include <math.h>
//#include <vector>
//#include <string>
//#include <sstream>
//#include <iostream>
//#include <iomanip>
//#include <thread>
//
//using namespace std;
//
//vector<double> parallelRunner(double(*func)(double), double start, double step, int nums) {
//	vector<double> res(nums, double(0));
//	vector<thread> thr(0);
//	for (int i = 0; i < nums; i++) {
//		double in = start + i * step;
//		thread* temp = new thread(func, &in, &res[i]);
//		thr.push_back(*temp);
//	}
//	for (int i = 0; i < nums; i++) {
//		thr[i].join();
//	}
//	return res;
//}
//
//double funct(double x) { return x;  }
//
//int main() {
//	vector<double> resa = parallelRunner(funct, 0, 0.5, 4);
//	for (int i = 0; i < 4; i++) {
//		cout << resa[i] << endl;
//	}
//	return 0;
//}