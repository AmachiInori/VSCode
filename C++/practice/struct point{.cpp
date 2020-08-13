#include <bits/stdc++.h>
using namespace std;

struct point{
    double x, y;
};

bool Straddle(point Pa, point Pb, point Pc, point Pd) {
    auto crossProduct = [&] (point VectorA, point VectorB) {
        return VectorA.x * VectorB.y - VectorA.y * VectorB.x;
    };
    point VectorAC = { Pc.x - Pa.x, Pc.y - Pa.y };
    point VectorBC = { Pc.x - Pb.x, Pc.y - Pb.y };
    point VectorDC = { Pc.x - Pd.x, Pc.y - Pd.y };
    bool res = (crossProduct(VectorAC, VectorDC) * crossProduct(VectorBC, VectorDC) <= 0);

    point VectorCA = { Pa.x - Pc.x, Pa.y - Pc.y };
    point VectorDA = { Pa.x - Pd.x, Pa.y - Pd.y };
    point VectorBA = { Pa.x - Pb.x, Pa.y - Pb.y };
    res = res && (crossProduct(VectorCA, VectorBA) * crossProduct(VectorDA, VectorBA) <= 0);

    return res;
}

bool RR(point Pa, point Pb, point Pc, point Pd) {
    bool res = max(Pa.x, Pb.x) > min(Pc.x, Pd.x);
    res = res && min(Pa.x, Pb.x) < max(Pc.x, Pd.x);
    res = res && max(Pa.y, Pb.y) > min(Pc.y, Pd.y);
    res = res && min(Pa.y, Pb.y) < max(Pc.y, Pd.y);
    return res;
}

int main() {
    point a = {-1, -1}, b = {1, 1};
    point c = {0, 3}, d = {3, 0};
    cout << (int)(RR(a, b, c, d) && Straddle(a, b, c, d));
    return 0;
}