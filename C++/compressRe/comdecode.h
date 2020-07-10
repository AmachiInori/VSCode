#ifndef _COMDECODE_H
#define _COMDECODE_H

#include <unordered_map>
#include <string>
#include <iostream>
#include <fstream>
#include <queue>
#include "treenode.h"
#include "filemerge.h"

using namespace std;

class decode {
private:
    string oriFileName;
    string dictName;
    string originName;
    string targetName;
    treeNode* codeTreeRoot;
    int totalLength = 0;
    
    void buildTree() {
        treeNodePriorityQueue minQueue(256);
        uint8_t temp;
        int tempFreq;
        ifstream dict(dictName, ios::binary);
        while (!dict.eof()) {
            dict >> temp;
            dict.get();
            dict >> tempFreq;
            if(dict.get() == EOF) break;
            totalLength += tempFreq;
            treeNode* str = new treeNode({temp, tempFreq});
            minQueue.push(str);
        }
        
        while (minQueue.size() > 1) {
            treeNode* L = minQueue.top();
            minQueue.pop();
            treeNode* R = minQueue.top();
            minQueue.pop();
            treeNode* fathor = new treeNode({0, (L -> totalFreq() + R -> totalFreq())}, L, R);
            minQueue.push(fathor);
        }
        codeTreeRoot = minQueue.top();
        dict.close();
    }
    string uint8_to_string(uint8_t n) {
        string res(8, 0);
        for (int i = 8; i > 0; i--) {
            res[8 - i] = (int)n / (int)pow(2, i - 1) + '0';
            n %= (int)pow(2, i - 1);
        }
        return res;
    }
    void print() {
        ifstream ori(originName, ios::binary);
        ofstream tar(targetName, ios::binary);
        int length = 0;
        uint8_t temp;
        treeNode* str = codeTreeRoot;
        string tempS = "";
        while (!ori.eof()) {
            ori.read((char*)&temp, sizeof(uint8_t));
            tempS += uint8_to_string(temp);
        }
        cout << tempS;
        for (int i = 0; i < tempS.size() && length < totalLength; i++) {
            if (str == NULL) throw("wrong file");
            if (str -> isLeaf()) {
                tar << str -> getWord();
                length++;
                continue;
                }
            if (tempS[i] == '0') str = str -> getLeft();
            else str = str -> getRight();
            if (str -> isLeaf()) {
                tar << str -> getWord();
                str = codeTreeRoot;
                length++;
            }
        }
        tar.close();
    }
public:
    decode(string fileName) : oriFileName(fileName) {}
    void doDecode() {
        vector<string> name = fileDiv(oriFileName);
        dictName = name[0];
        originName = name[1];
        targetName = string(&oriFileName[0], &oriFileName[oriFileName.size() - 3]) + "de.txt";
        buildTree();
        print();
        remove(originName.data());
        remove(dictName.data());
        cout << "Decode Done" << endl;
    }
};

#endif