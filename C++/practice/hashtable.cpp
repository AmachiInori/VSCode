#include <bits/stdc++.h>
using namespace std;

template<class type>
class hashTable {
private:
    unsigned int _size = 0;
public:
    unsigned int size() { return _size; }
    bool empty() { return _size == 0; }
    type* find(type const val) = 0;
    void insert(type const &val) = 0;
    void remove(type const val) = 0;
    vector<type> keys() = 0;
};

template<class type>
class chainHash : virtual public hashTable<type> {

};