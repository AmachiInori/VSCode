/*
 * @Author: your name
 * @Date: 2020-04-26 10:40:26
 * @LastEditTime: 2020-04-26 11:07:24
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \VSCode\problems\leetcode\wc\186\5393.cpp
 */
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    int maxScore(vector<int> &cardPoints, int k) {
        int sum = 0;
        for (int i = 0; i < cardPoints.size(); i++){
            sum += cardPoints[i];
        }
        if (k == cardPoints.size()) return sum;
        int min = INT_MAX;
        int count = 0;
        for (int left = 0, right = cardPoints.size() - k - 1; right < cardPoints.size(); left++, right++){
            if (left == 0) {
                for (int j = left; j <= right; j++){
                    count += cardPoints[j];
                }
            }else {
                count -= cardPoints[left - 1];
                count += cardPoints[right];
            }
            
            if (count < min) min = count;
        }
        return sum - min;
    }
};

/*
int firstLoca = 0, lastLoca = cardPoints.size() - 1;
        int count = 0;
        for (int i = 0; i < k; i++){
            if (cardPoints[firstLoca] >= cardPoints[lastLoca]) {
                firstLoca++;
                count += cardPoints[firstLoca];
            }else {
                lastLoca++;
                count += cardPoints[lastLoca];
            }
        }
        return count;
        */