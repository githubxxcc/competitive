#ifndef UTIL_PRINT
#define UTIL_PRINT
#include <map>
#include <iostream>
#include <string>
/************** NOTE *****************/
/* Not working for now. Refer to prettyprint for a working version */

//using namespace std;
//template <typename _T, typename _T2> 
//void print_map(const map<_T, _T2> &_a) {
//    for(typename map<_T, _T2>::const_iterator i = _a.begin(); i != _a.end(); i++) {
//        cout << "[" << i->first << ", " <<  i->second << "]" << endl;
//    }
//}

namespace DEBUG {
    bool MODE = 1;

    void print(string message){
        if(MODE) {
            std::cout << message;
        }
    }
}
#endif
