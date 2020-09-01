#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        vector<vector<int>> res(people.size(), vector<int>(2, int(-1)));
        for (int i = 0; i < people.size(); i++) {
            int minValue = INT_MAX;
            int minPoint;
            for (int j = 0; j < people.size(); j++) {
                if (people[j][0] != -1 && minValue > people[j][0]) {
                    minValue = people[j][0];
                    minPoint = j;
                }
            }
            int point = people[minPoint][1];
            while (res[point][0] != -1) 
                point++;
            res[point] = people[minPoint];
            people[minPoint][0] = -1;
        }
        return res;
    }
};

int main() {

}