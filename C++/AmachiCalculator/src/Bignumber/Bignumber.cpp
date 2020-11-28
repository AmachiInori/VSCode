# include "Bignumber.h"

AMIC_NAMESPACE_START

big_int::big_int(std::string _str) {
    
}

big_int::operator long long() {
    long long int res = 0;
    std::for_each(number.begin(), number.end(), [&res](char temp) {
        res *= big_int::unit_max;
        res += temp;
    });
    return (positive ? 1 : -1) * res;
}

bool big_int::operator>(const big_int &other) {
    if (other.number.empty() && this->number.empty()) return false; // ²»Ó¦Îª¿Õ
    if (other.positive ^ this->positive) return this->positive;
    if (this->number.size() > other.number.size()) return positive;
    if (this->number.size() < other.number.size()) return !positive;
    for (size_t i = this->number.size() - 1; i >= 0; i--) // the number.size() will not be 0.
        if (this->number[i] > other.number[i]) return positive;
    return false;
}

bool big_int::operator==(const big_int &other) {
    if ((this->positive ^ other.positive) || (this->number.size() ^ other.number.size())) return false;
    for (size_t i = this->number.size() - 1; i >= 0; i--)
        if (this->number[i] ^ other.number[i]) return false;
    return true;
}

bool big_int::operator>=(const big_int &other) {
    return *this == other || *this > other;
}

bool big_int::operator<(const big_int &other) {
    return !(*this >= other);
}

bool big_int::operator<=(const big_int &other) {
    return !(*this > other);
}


big_int big_int::operator+(const big_int &rvalue) {

} 

AMIC_NAMESPACE_END