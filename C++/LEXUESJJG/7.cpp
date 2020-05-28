#include <iostream>
#include <iomanip>
#define PI 3.14159
#define CO 3
#define COCO 20
#define COFE 35
using namespace std;

class POOL
{
    float radius;
public:
    POOL(float r);
    float calcuFencing();
    float calcuConcrete();
    ~POOL();
};

POOL::POOL(float r)
{
    radius = r;
}

float POOL::calcuConcrete()
{
    return COCO * PI * (( radius + CO ) * ( radius + CO ) - radius * radius);
}

float POOL::calcuFencing()
{
    return 2 * ( radius + CO ) * PI * COFE;
}

POOL::~POOL()
{
}

int main()
{
    int r;
    cout << "Enter the radius of the pool:";
    cin >> r;
    cout << r << endl;
    POOL thePool(r);
    cout << setiosflags(ios::fixed) << setprecision(2) << "Fencing Cost is " << 
    thePool.calcuFencing() << endl << "Concrete Cost is " << thePool.calcuConcrete() << endl;
    getchar();
    getchar();
    return 0;
}