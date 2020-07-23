#include <bits/stdc++.h>

template<class elementType>
class array {
protected:
    elementType* ptl; //存放数据的标准数组
    int maxLength; //标准数组申请的长度
    int usedLength = 0; //标准数组中已占用的长度

    void increaseSize();//放大数组大小
    void decreaseSize();//缩小数组大小
public:
    array(int initSize = 10);//标准构造函数
    array(const array<elementType> &theArray);//复制构造函数
    ~array() { delete[] ptl; }//析构函数

    int size() const { return usedLength; }//返回大小
    bool empty() const { return usedLength == 0; }//判空
    bool vaildIndex(int index) const { return index >= 0 && index < usedLength; }//判断索引是否有效 此函数可以声明为protected
    array<elementType>& operator=(const array<elementType> &A);//重载赋值运算符

    elementType& operator[](unsigned int const index);//读写
    void pop();//弹出元素
    void pop(unsigned int const index);//按索引弹出元素
    void push(elementType val);//压入元素
    void push(elementType val, unsigned int const index);//按索引压入元素
};

template<class elementType>
void array<elementType>::increaseSize(){
    elementType* tempPtl = new elementType[maxLength * 2];
    for (int i = 0; i < usedLength; i++){
        tempPtl[i] = ptl[i];
    }
    maxLength *= 2;
    delete[] ptl;
    ptl = tempPtl;
}

template<class elementType>
void array<elementType>::decreaseSize(){
    elementType* tempPtl = new elementType[maxLength / 2];
    for (int i = 0; i < usedLength; i++){
        tempPtl[i] = ptl[i];
    }
    maxLength /= 2;
    delete[] ptl;
    ptl = tempPtl;
}

template<class elementType>
array<elementType>::array(int initSize) : maxLength(initSize) {
    ptl = new elementType[initSize];
}

template<class elementType>
array<elementType>::array(const array<elementType> &theArray) {
    ptl = new elementType[theArray.maxLength];
    *this = theArray;
}

template<class elementType>
array<elementType>& array<elementType>::operator=(const array<elementType> &A) {
    maxLength = A.maxLength;
    usedLength = A.usedLength;
    for (int i = 0; i < A.usedLength; i++){
        ptl[i] = A.ptl[i];
    }
    return *this;
}

template<class elementType>
elementType& array<elementType>::operator[](unsigned int const index) {
    if (vaildIndex(index))
        return ptl[index];
    else
        throw("invaild index");
}

template<class elementType>
void array<elementType>::pop() {
    usedLength--;
    if (usedLength <= maxLength / 4)
        decreaseSize();
}

template<class elementType>
void array<elementType>::pop(unsigned int const index) {
    if (vaildIndex(index)) {
        for (int i = index; i < usedLength - 1; i++)
            ptl[i] = ptl[i + 1];
        usedLength--;
        if (usedLength <= maxLength / 4)
            decreaseSize();
    }else
        throw("invaild index");
}

template<class elementType>
void array<elementType>::push(elementType val) {
    usedLength++;
    if (usedLength >= maxLength)
        increaseSize();
    ptl[usedLength - 1] = val;
}

template<class elementType>
void array<elementType>::push(elementType val, unsigned int const index) {
    usedLength++;
    if (vaildIndex(index)) {
        if (usedLength >= maxLength)
            increaseSize();
        for (int i = usedLength; i > index; i--)
            ptl[i] = ptl[i - 1];
        ptl[index] = val;
    }else {
        usedLength--;
        throw("invaild index");
    }
}

int main() {
    array<int> test;
    for (int i = 0; i < 100; i++){
        test.push(i);
        std::cout << test[-1];
    }
    std::cout << std::endl;
    test.push(200,2);
    std::cout << test[2];
    test[2] = 1;
    std::cout << test[2];
    array<int> test2(test);
    for (int i = 0; i < 99; i++){
        test2.pop();
        std::cout << test2[test2.size() - 1];
    }
}