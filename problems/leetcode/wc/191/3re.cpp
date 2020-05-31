#include <bits/stdc++.h>
using namespace std;

class Solution {
    bool anti(vector<int> a, vector<int> b) {
        if (a[1] >= b[1]) return true;
        else return false;
    }
    bool cpr(vector<int>a, vector<int> b) {
        if (a[0] >= b[0]) return true;
        else return false;
    }
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>> anticon = connections;
        sort(connections.begin(), connections.end(), cpr);
        sort(anticon.begin(), anticon.end(), anti);
        
    }
};