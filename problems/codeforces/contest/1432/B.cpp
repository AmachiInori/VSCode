/*
 * @Author: your name
 * @Date: 2020-04-27 00:29:58
 * @LastEditTime: 2020-04-27 00:29:59
 * @LastEditors: your name
 * @Description: In User Settings Edit
 * @FilePath: \VSCode\problems\codeforces\contest\1432\B.cpp
 */
#include <iostream>
#include <math.h>
#include <string>

using namespace std;

int main(){
    int times;
    cin >> times;
    for (int i = 0; i < times; i++){
        string s;
        cin >> s;
        int zero = 0, one = 1;
        for (int j = 0; j < s.length(); j++){
            if (s[0] == '0') {
                zero = 1;
            }else one = 0;
            if (s[i] == '0' && one == 1) {
                for (int i = 0; i < s.length(); i++){
                    cout << "10";
                }
                cout << endl;
                zero++;
            }
            if (s[i] == '1' && zero == 1)
            {
                for (int i = 0; i < s.length(); i++)
                {
                    cout << "01";
                    one++;
                }
                cout << endl;
            }
        }
        if (zero == 0 && one == 1) {
            for (int i = 0; i < s.length(); i++)
            {
                cout << "1";
                one++;
            }
        }
        if (zero == 1 && one == 0)
        {
            for (int i = 0; i < s.length(); i++)
            {
                cout << "0";
                one++;
            }
        }
    }
    return 0;
}