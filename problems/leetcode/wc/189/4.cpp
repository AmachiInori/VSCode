#include <bits/stdc++.h>
using namespace std;

class Solution {
    struct Point{
        double x, y;
        Point(){}
        Point(double tx,double ty){x=tx;y=ty;}
    };
    Point p[101];
public:
    double dist(Point p1,Point p2){
        return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
    }
    Point getCircleCenter(Point p1, Point p2, int r){
        Point mid = Point((p1.x + p2.x) / 2,(p1.y + p2.y) / 2);
        double angle = atan2(p1.x - p2.x, p2.y - p1.y);
    	double d = sqrt(r * r - pow(dist(p1, mid), 2));
    	return Point(mid.x + d * cos(angle), mid.y + d * sin(angle));
    }
    int numPoints(vector<vector<int>>& points, int r) {
        for (int i = 0; i < points.size(); i++){
            p[i].x = points[i][0];
            p[i].y = points[i][1];
        }
        int max = 1;
        for (int i = 0; i < points.size(); i++){
            for (int j = i + 1; j < points.size(); j++){
                if (dist(p[i], p[j]) - 2.0 * (double)r > 0.000001) continue;
                Point mid = getCircleCenter(p[i], p[j], r);
                int temp = 0;
                for (int k = 0; k < points.size(); k++){
                    if (dist(p[k], mid) - 1.0 * (double)r <= 0.000001) temp++;
                }
                max = max > temp ? max : temp;
            }
        }
        return max;
    }
};

int main(){
    Solution s;
    vector<vector<int>> test = {{-2, 0}, {2, 0}, {0, 2}, {0, -2}};
    cout << s.numPoints(test, 2);
    return 0;
}