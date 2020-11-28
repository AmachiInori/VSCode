# include "../Overall.h"

AMIC_NAMESPACE_START

class big_int {
private:
    bool positive = true; //≤ª‘ –Ì∏∫¡„
    std::deque<uint16_t> number;
public:
    static const uint16_t unit_max = 10000;

    explicit big_int(std::string _str);
    explicit big_int(long long _num);

    operator long long();
    operator std::string();
    big_int operator+(const big_int &rvalue);
    big_int operator-(const big_int &rvalue);
    big_int operator*(const big_int &rvalue);
    big_int operator/(const big_int &rvalue);
    big_int operator%(const big_int &rvalue);
    bool operator>(const big_int &other);
    bool operator>=(const big_int &other);
    bool operator<(const big_int &other);
    bool operator<=(const big_int &other);
    bool operator==(const big_int &other);
    big_int& operator+=(const big_int &rvalue);
    big_int& operator-=(const big_int &rvalue);
    big_int& operator*=(const big_int &rvalue);
    big_int& operator/=(const big_int &rvalue);
    big_int& operator=(const big_int &rvalue) = default;
};

big_int big_power(const big_int &base, const big_int &times);
std::ostream operator<<(std::ostream &os, big_int &_bigi);

AMIC_NAMESPACE_END