#include <bits/stdc++.h>
using namespace std;

class timeClass {
public:
    int day;
    int h;
    int m;
    int s;

    timeClass(int d, int _h, int _m, int _s) : day(d), h(_h), m(_m), s(_s) {
        while (s >= 60) 
            m += 1, s -= 60;
        while (m >= 60) 
            h += 1, m -= 60;
        while (h >= 24) 
            day += 1, h -= 24;
        while (s < 0)
            m -= 1, s += 60;
        while (m < 0)
            h -= 1, m += 60;
        while (h < 0)
            day -= 1, h += 24;
    }
    void normal() {
        while (s >= 60) 
            m += 1, s -= 60;
        while (m >= 60) 
            h += 1, m -= 60;
        while (h >= 24) 
            day += 1, h -= 24;
        while (s < 0)
            m -= 1, s += 60;
        while (m < 0)
            h -= 1, m += 60;
        while (h < 0)
            day -= 1, h += 24;
    }
    timeClass(const timeClass &a) {
        day = a.day;
        h = a.h;
        m = a.m;
        s = a.s;
    }
    timeClass() {
        timeClass(0,0,0,0);
    }
    int64_t calcuNumber() {
        return s + m * 60 + h * 3600 + day * 24 * 3600;
    }
    timeClass operator+(int32_t a) {
        timeClass res(this->day, this->h, this->m, this->s + a);
        res.normal();
        return res;
    }
    int64_t operator-(timeClass a) {
        timeClass tempTime = timeClass(this->day - a.day, this->h - a.h, this->m - a.m, this->s - a.s);
        tempTime.normal();
        return tempTime.calcuNumber();
    }
};

class majorProcess {
private:
    ifstream infile;
    ofstream outfile;
    timeClass _tar;
    timeClass _tarEnd;
    timeClass _start;
    timeClass _end;
    vector<int64_t> timeLength;
    string ifl;
public:
    majorProcess(const timeClass &targetTime, const timeClass &targetEnd, string _infile, string _outfile) 
    : ifl(_infile), _tar(targetTime), _tarEnd(targetEnd) {
        timeLength = {0};
        infile.open(_infile);
        outfile.open(_outfile);
    }
    void majP();
};

void majorProcess::majP() {
    string temp;
    int line = 0;
    int count = 0;
    while (!infile.eof()) {
        line++;
        getline(infile, temp);
        if (line == 7) {//"?????:\t20 ?10 ?07 ?17??51??49"
            int d, h, m, s;
            for (auto &i : temp) {
                cout << i;
            }
            stringstream ss1(string(&temp[20], &temp[22]));
            ss1 >> d;
            stringstream ss2(string(&temp[25], &temp[27]));
            ss2 >> h;
            stringstream ss3(string(&temp[29], &temp[31]));
            ss3 >> m;
            stringstream ss4(string(&temp[33], &temp[35]));
            ss4 >> s;
            _start.day = d, _start.h = h, _start.m = m, _start.s = s;
        } 
        if (line == 9) {//"?????:\t20 ?10 ?07 ?17??51??49"
            int d, h, m, s;
            for (auto &i : temp) {
                cout << i;
            }
            stringstream ss1(string(&temp[20], &temp[22]));
            ss1 >> d;
            stringstream ss2(string(&temp[25], &temp[27]));
            ss2 >> h;
            stringstream ss3(string(&temp[29], &temp[31]));
            ss3 >> m;
            stringstream ss4(string(&temp[33], &temp[35]));
            ss4 >> s;
            _end.day = d, _end.h = h, _end.m = m, _end.s = s;
        } 
        if (temp[0] == '*') count++;
        if (count == 5) {
            break;
        }
    }
    for (int i = 0; i < 3; i++) {
        getline(infile, temp);
        if (temp.length() <= 0 || temp == "\n") getline(infile, temp);
    }
    while (temp.length() > 0) {
        int d, h, m, s;
        int spaceLoca = 0;
        for (int i = 0; i < temp.size(); i++) {
            if (temp[i] == ' ') {
                spaceLoca = i;
                break;
            }
        }
        stringstream ss1(string(&temp[spaceLoca + 11], &temp[spaceLoca + 13]));
        ss1 >> d;
        stringstream ss2(string(&temp[spaceLoca + 16], &temp[spaceLoca + 18]));
        ss2 >> h;
        stringstream ss3(string(&temp[spaceLoca + 19], &temp[spaceLoca + 21]));
        ss3 >> m;
        stringstream ss4(string(&temp[spaceLoca + 22], &temp[spaceLoca + 24]));
        ss4 >> s;
        timeLength.push_back(timeClass(d, h, m, s) - _start);
        getline(infile, temp);
        if (temp.length() <= 0 || temp == "\n") getline(infile, temp);
    }
    int zoom = (_end - _start);
    int zoom2 = (_tarEnd - _tar);
    long double zoomt = (long double)zoom / (long double)zoom2;
    for_each(timeLength.begin(), timeLength.end(), [zoomt](int64_t &temp){
        temp = (long double)temp / zoomt;
    });
    for (int i = 0; i < timeLength.size(); i++) {
		double res = 0;
		for (size_t j = i > 5 ? i - 5 : 0; j <= min((unsigned long long)i + 5, timeLength.size() - 1); j++) {
			res += timeLength[j];
		}
		timeLength[i] = res / (double)min((unsigned long long)(5 * 2 + 1), min((unsigned long long)i + 5 + 1, timeLength.size() - i + 5));
	}
    
    infile.close();
    ifstream infile2;
    infile2.open(ifl);
    line = 0;
    count = 0;
    size_t loca = 0;
    while (!infile2.eof()) {
        line++;
        if (count != 6) getline(infile2, temp);
        if (line == 7) {
            temp[20] = _tar.day / 10 + '0';
            temp[21] = _tar.day % 10 + '0';
            temp[25] = _tar.h / 10 + '0';
            temp[26] = _tar.h % 10 + '0';
            temp[29] = _tar.m / 10 + '0';
            temp[30] = _tar.m % 10 + '0';
            temp[33] = _tar.s / 10 + '0';
            temp[34] = _tar.s % 10 + '0';
        }
        if (line == 9) {
            temp[20] = _tarEnd.day / 10 + '0';
            temp[21] = _tarEnd.day % 10 + '0';
            temp[25] = _tarEnd.h / 10 + '0';
            temp[26] = _tarEnd.h % 10 + '0';
            temp[29] = _tarEnd.m / 10 + '0';
            temp[30] = _tarEnd.m % 10 + '0';
            temp[33] = _tarEnd.s / 10 + '0';
            temp[34] = _tarEnd.s % 10 + '0';
        }
        if (line == 23) {
            temp[205] = _tar.day / 10 + '0';
            temp[206] = _tar.day % 10 + '0';
            temp[210] = _tar.h / 10 + '0';
            temp[211] = _tar.h % 10 + '0';
            temp[214] = _tar.m / 10 + '0';
            temp[215] = _tar.m % 10 + '0';
            temp[218] = _tar.s / 10 + '0';
            temp[219] = _tar.s % 10 + '0';

            temp[238] = _tarEnd.day / 10 + '0';
            temp[239] = _tarEnd.day % 10 + '0';
            temp[243] = _tarEnd.h / 10 + '0';
            temp[244] = _tarEnd.h % 10 + '0';
            temp[247] = _tarEnd.m / 10 + '0';
            temp[248] = _tarEnd.m % 10 + '0';
            temp[251] = _tarEnd.s / 10 + '0';
            temp[252] = _tarEnd.s % 10 + '0';
        }
        if (temp[0] == '*') count++;
        if (count == 5) {
            for (int i = 0; i < 3; i++) 
                getline(infile2, temp);
            count++;
        }
        if (count == 6) {
            getline(infile2, temp);
            if (temp == "\n" || temp.empty()) {
                outfile << temp + "\n";
                getline(infile2, temp);
            }
            int spaceLoca = 0;
            for (int i = 0; i < temp.size(); i++) {
                if (temp[i] == ' ') {
                    spaceLoca = i;
                    break;
                }
            }
            timeClass tempT = _tar;
            tempT = _tar + timeLength[loca++];
            temp[spaceLoca + 11] = tempT.day / 10 + '0';
            temp[spaceLoca + 12] = tempT.day % 10 + '0';
            temp[spaceLoca + 16] = tempT.h / 10 + '0';
            temp[spaceLoca + 17] = tempT.h % 10 + '0';
            temp[spaceLoca + 19] = tempT.m / 10 + '0';
            temp[spaceLoca + 20] = tempT.m % 10 + '0';
            temp[spaceLoca + 22] = tempT.s / 10 + '0';
            temp[spaceLoca + 23] = tempT.s % 10 + '0';
        }
        outfile << temp + "\n";
    }
};

int main() {
    setlocale(LC_ALL, "Chinese-simplified");
    timeClass test(8, 8 , 30, 10), testEnd(8 , 14, 0, 2);
    majorProcess pro(test, testEnd, string("C:\\Users\\Zhao Yufeng\\Documents\\123.txt"), string("C:\\Users\\Zhao Yufeng\\Documents\\123out.txt"));
    pro.majP();
    return 0;
}