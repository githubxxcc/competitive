
#include <vector>
#include <queue>
#include <iostream>

using namespace std;


class comp{
    bool rev;

public: 
    comp(const bool & rev=false) {
        this->rev = rev;
    }

    bool operator()(const int& lhs, const int& rhs) {
        if(this->rev) return rhs < lhs;
        else return lhs < rhs;
    }
};

typedef priority_queue<int, vector<int>, comp> myq;

int main(){
  
    myq right(comp(true));
    myq left(comp(false));
    bool even = false;
    int x, mid;

    while(scanf("%d", &x) != EOF){
        if(even){
            if(x <= left.top()) {
                right.push(left.top());
                left.pop();
                left.push(x);
            } else {
                right.push(x);
            }
            
            mid = left.top() + (right.top() - left.top()) /2 ;
        } else {
            if(!left.empty() && x > left.top()){
                right.push(x);
                x = right.top();
                right.pop();
            }
            left.push(x);
            mid = left.top();
        }

        cout << mid << endl;
        even = !even;
    }
}

