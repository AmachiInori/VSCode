#include "comencode.h"
#include "comdecode.h"

int main() { 
    encode test("C://Users//Zhao Yufeng//Documents//VSCode//C++//compressRe//test.txt", "C://Users//Zhao Yufeng//Documents//VSCode//C++//compressRe//res.txt");
    test.doEncode();
    decode test2("C://Users//Zhao Yufeng//Documents//VSCode//C++//compressRe//res.txt.cps");
    test2.doDecode();
    return 0;
}