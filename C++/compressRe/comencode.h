#ifndef _COMENCODE_H
#define _COMENCODE_H

#include <unordered_map>
#include <string>
#include <iostream>
#include <fstream>
#include <queue>
#include <cmath>
#include "treenode.h"
#include "filemerge.h"

using namespace std;

class encode {
private:
    string originFilename;
    string targetFilename;
    unordered_map<uint8_t, int> freqTable;
    unordered_map<uint8_t, vector<bool>> huffmanCode;

    treeNode* buildTree() {
        uint8_t temp;
        ifstream ifs(originFilename, ios::binary);
        treeNodePriorityQueue minQueue(256);
        if (!ifs.is_open()) throw("Origin file reading failed : " + originFilename);
        while(!ifs.eof() && ifs.read((char*)&temp, sizeof(uint8_t))) 
            freqTable[temp]++;
        ifs.close();
        ofstream dictOfs(targetFilename + ".dict", ios::binary);
        if (!dictOfs.is_open()) throw("Dictionary file writing failed : " + targetFilename + ".dict");
        for (auto &i : freqTable) {
            dictOfs << i.first << '\0' << i.second << '\0';
            treeNode* str = new treeNode((pair<uint8_t, int>){i.first, i.second});
            minQueue.push(str);
            cout << minQueue.top()->getWord();
        }
        dictOfs.close();
        
        while (minQueue.size() > 1) {
            treeNode* L = minQueue.top();
            cout << L->getWord();
            minQueue.pop();
            treeNode* R = minQueue.top();
            cout << R->getWord();
            minQueue.pop();
            treeNode* fathor = new treeNode({0, (L -> totalFreq() + R -> totalFreq())}, L, R);
            minQueue.push(fathor);
        }
        return minQueue.top();
    }
    void getHuffmanCode(treeNode* str, vector<bool> temp) {
        if (str -> isLeaf()) {
            if (temp.empty()) temp.push_back(false);
            huffmanCode[str -> getWord()] = temp;
            return;
        }
        if (str -> getLeft()) {
            temp.push_back(false);
            getHuffmanCode(str -> getLeft(), temp);
            temp.pop_back();
        }
        if (str -> getRight()) {
            temp.push_back(true);
            getHuffmanCode(str -> getRight(), temp);
            temp.pop_back();
        }
    }
    int output() {
        uint8_t temp = 0;
        uint8_t readTemp;
        vector<bool> tempS;
        ifstream ifs(originFilename, ios::binary);
        if (!ifs.is_open()) throw("Origin file reading failed : " + originFilename);
        ofstream Ofs(targetFilename, ios::binary);
        if (!Ofs.is_open()) throw("Target file writing failed : " + targetFilename);
        while(!ifs.eof() && ifs.read((char*)&readTemp, sizeof(uint8_t))) {
            for (auto const &i : huffmanCode[readTemp]) {
                if (i) tempS.push_back(1);
                else tempS.push_back(0);
            }
        }
        ifs.close();
        int counter = 0;
        for (int i = 0; i < tempS.size(); i++) {
            temp += tempS[i] * (int)pow(2, 7 - counter);
            cout << tempS[i];
            counter++;
            if (counter == 8 || i == tempS.size() - 1){
                Ofs << temp;
                counter = 0;
                temp = 0;
            }
        }
        Ofs.close();
        return 0;
    }


public:
    encode(string origin, string target) : originFilename(origin), targetFilename(target){}
    void doEncode() {
        string dictName = targetFilename + ".dict";
        vector<bool> temp;
        getHuffmanCode(buildTree(), temp);
        output();
        fileMerge(dictName, targetFilename);
        remove(targetFilename.data());
        remove(dictName.data());
        cout << "Encode Done" << endl;
    }
};

#endif