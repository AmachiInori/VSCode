#include <iostream>
#include <vector>
#include <string>

using std::string;
using std::vector;

class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<bool> isEdgeUsed(edges.size(), false);
        vector<int> temp(hasApple.size(), -1);
        for (int i = 0; i < edges.size(); i++)
            temp[edges[i][1]] = i;
        

        for (int i = 0; i < hasApple.size(); i++){
            if (hasApple[i]) {
                int nowNumber = i;
                while(nowNumber != 0) {
                    isEdgeUsed[temp[nowNumber]] = true;
                    nowNumber = edges[temp[nowNumber]][0];
                }
            }
        }
        
        int res = 0;
        for (int i = 0; i < isEdgeUsed.size(); i++)
            if (isEdgeUsed[i]) res++;
        return res * 2;
    }
};