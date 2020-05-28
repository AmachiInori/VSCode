#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses, 0);
        vector<int> res;
        for (int i = 0; i < numCourses; i++)
            for (int j = 0; j < prerequisites.size(); j++)
                if (prerequisites[j][0] == i) indegree[i]++;

        for (int count = 0; count < numCourses; count++) {
            int nowVertex = -1;
            for (int i = 0; i < numCourses; i++)
                if (indegree[i] == 0) nowVertex = i;
            if (nowVertex == -1) return {};
            res.push_back(nowVertex);
            for (int i = 0; i < prerequisites.size(); i++)
                if (prerequisites[i][1] == nowVertex) indegree[prerequisites[i][0]]--;
            indegree[nowVertex]--;
        }
        return res;
    }
};