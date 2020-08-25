#include <bits/stdc++.h>
using namespace std;

typedef pair<double, double> point;

bool inPolygon (point thePoint, const vector<point> &polygon) {
    point max = {DBL_MIN, DBL_MIN}, min = {DBL_MAX, DBL_MAX};
    for_each(polygon.begin(), polygon.end(), [&max, &min](point tempPoint) {
        if (tempPoint.first > max.first) max.first = tempPoint.first;
        if (tempPoint.second > max.second) max.second = tempPoint.second;
        if (tempPoint.first < min.first) min.first = tempPoint.first;
        if (tempPoint.second < min.second) min.second = tempPoint.second;
    });
    if (!(thePoint.first >= min.first && thePoint.first <= max.first && 
        thePoint.second >= min.second && thePoint.second <= max.second)) {
        return false;
    }//¿ìËÙÅÅ³ý
    
    auto isIntersect = [&thePoint](point a, point b) {
        if (thePoint.first <= a.first && thePoint.first <= b.first) {
            return (thePoint.second - a.second) * (thePoint.second - b.second) < 0;
        } else if (thePoint.first > a.first && thePoint.first > b.first) {
            return false;
        } else {
            if ((thePoint.second - a.second) * (thePoint.second - b.second) > 0) {
                return false;
            } else {
                double slope = (a.second - b.second) / (a.first - b.first);
                double intercept = a.second - slope * a.first;
                return thePoint.first <= (thePoint.second - intercept) / slope;
            }
        }
    };

    int counter = 0;
    for (int i = 0; i < polygon.size() - 1; i++) {
        if (isIntersect(polygon[i], polygon[i + 1]))
            counter++;
    }
    if (isIntersect(polygon.back(), polygon.front()))
        counter++;
    return counter % 2 == 1;
}

int main() {
    vector<point> test = {
        {1, 1},
        {0, 2},
        {2, 4},
        {5, 1}
    };
    cout << (int)inPolygon({0.5, 0.5}, test);
    return 0;
}