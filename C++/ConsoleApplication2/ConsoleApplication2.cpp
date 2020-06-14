#include <iostream>
#include "huffencode.h"
#include "huffdecode.h"

using namespace huffman;

void testHuffTree(const std::string& filename, const std::string& encodeTarget) {
    huffEncode he;
    he.encode(filename.data(), encodeTarget.data());
}

void testHuffDecode(const std::string& filename, const std::string& decodeTarget) {
    huffDecode hd;
    hd.decode(filename.data(), decodeTarget.data());
}

int main()
{
    std::string filename = "C://Users//Zhao Yufeng//Documents//VSCode//C++//ConsoleApplication2//ori.txt"; // 主函数是测试用的，这里输入同文件夹下的文件名就行
    std::string encodeTe = "C://Users//Zhao Yufeng//Documents//VSCode//C++//ConsoleApplication2//enori.txt";
    std::string decodeTe = "C://Users//Zhao Yufeng//Documents//VSCode//C++//ConsoleApplication2//deori.txt";
    testHuffTree(filename, encodeTe);
    testHuffDecode(encodeTe, decodeTe);

    std::cout << "Done" << std::endl;
    return 0;
}
