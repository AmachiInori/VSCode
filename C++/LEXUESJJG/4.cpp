#include <iostream>
#define PI 3.14
using namespace std;

class CYLINDER
{
    float radius;
    float hight;
public:
    void input(float r, float h);
    float calcuVolume();
};

void CYLINDER::input(float r, float h)
{
    radius = r;
    hight = h;
    return;
}

float CYLINDER::calcuVolume()
{
    float volume = radius * radius * hight * PI;
    return volume;
}

int main()
{
    float r, h;
    CYLINDER theCy;
    cin >> r >> h;
    theCy.input(r, h);
    cout << "v="<< theCy.calcuVolume() << endl;
    getchar();
    getchar();
    return 0;
}