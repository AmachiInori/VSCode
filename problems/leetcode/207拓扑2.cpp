#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int length = 0;
        vector<int> indegree(numCourses, int(0));
        for (int i = 0; i < numCourses; i++)
            for (auto &j : prerequisites)
                if (j[0] == i)
                    indegree[i]++;
        while (length != numCourses) {
            int newVertex = -1;
            for (int i = 0; i < numCourses; i++)
                if (indegree[i] == 0)
                    newVertex = i;
            if (newVertex == -1)
                return false;
            indegree[newVertex] = -1;
            length++;
            for (int i = 0; i < prerequisites.size(); i++)
                if (prerequisites[i][1] == newVertex)
                    indegree[prerequisites[i][0]]--;
        }
        return true;
    }
};