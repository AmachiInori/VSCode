#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void runner(vector<vector<int>>& A, int x, int y) {
        if (!(x < A.size() && x >= 0 && y < A[0].size() && y >= 0)) return;
        if (!A[x][y]) return;
        A[x][y] = 0;
        runner(A, x + 1, y);
        runner(A, x, y + 1);
        runner(A, x - 1, y);
        runner(A, x, y - 1);
    }
    int numEnclaves(vector<vector<int>>& A) {
        int res(0);
        for (int i = 0; i < A.size(); i++) {
            runner(A, i, 0);
            runner(A, i, A[0].size() - 1);
        }
        for (int i = 0; i < A[0].size(); i++) {
            runner(A, 0, i);
            runner(A, A.size() - 1, i);
        }
        for (int i = 0; i < A.size(); i++){
            for (int j = 0; j < A[i].size(); j++){
                if (A[i][j]) res++;
            }
        }
        return res;
    }
};