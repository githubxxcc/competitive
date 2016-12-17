#ifndef UTIL_PRINT
#define UTIL_PRINT
#include <map>
#include <iostream>
using namespace std;
template <typename _T, typename _T2> 
void print_map(const map<_T, _T2> &_a) {
    for(typename map<_T, _T2>::const_iterator i = _a.begin(); i != _a.end(); i++) {
        cout << "[" << i->first << ", " <<  i->second << "]" << endl;
    }
}

#endif
