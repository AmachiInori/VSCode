#ifndef _FILEMERGE_H_
#define _FILEMERGE_H_

#include <iostream>
#include <fstream>
#include <string>
#include <cstdint>
#include <vector>

using namespace std;

string fileMerge (string dictName, string encodedName) {
    string targetName = encodedName + ".cps";
    ifstream dict(dictName, ios::binary);
    ifstream enc(encodedName, ios::binary);
    ofstream tar(targetName, ios::binary);

    uint16_t dictSize = 0;
    uint8_t temp;
    int tempInt;
    while (!dict.eof()) {
        dict >> temp;
        dict.get();
        dict >> tempInt;
        dict.get();
        if(!dict.eof()) dictSize++;
    }
    dict.close();
    dict.open(dictName, ios::binary);
    tar << dictSize;
    while (!dict.eof()) {
        dict >> temp;
        if(!dict.eof()) tar << temp;
    }
    while (!enc.eof()) {
        enc >> temp;
        if(!enc.eof()) tar << temp;
    }
    dict.close();
    enc.close();
    tar.close();
    return targetName;
}

vector<string> fileDiv (string fileName) {
    ifstream ifs(fileName, ios::binary);
    ofstream dictOfs(fileName + ".dict", ios::binary);
    ofstream encodeOfs(fileName + ".ecd", ios::binary);
    uint16_t dictSize;
    uint8_t temp;
    int tempInt;
    ifs >> dictSize;
    for (int i = 0; i < dictSize; i++) {
        ifs >> temp;
        dictOfs << temp;
        ifs >> temp;
        dictOfs << temp;
        ifs >> tempInt;
        dictOfs << tempInt;
        ifs >> temp;
        dictOfs << temp;
    }
    while (!ifs.eof()) {
        ifs >> temp;
        if(!ifs.eof())encodeOfs << temp;
    }
    return (vector<string>){fileName + ".dict", fileName + ".ecd"};
}

#endif