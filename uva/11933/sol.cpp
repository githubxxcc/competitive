
#include <iostream>

using namespace std;



unsigned int n, a, b;

void flip_bits(unsigned int n, unsigned int &a, unsigned int &b)
{
    unsigned int i = 0;
    bool toA = true;

    while( (1 << i) <= n) {
        if(n & (1 << i)) {
            if(toA){
                a |= ( 1 << i);
            } else 
                b |= ( 1 << i);

            toA = !toA;
        }

        i++;
    }
}


int main()
{
    while(scanf("%d", &n), n){
        a = b = 0;
        flip_bits(n, a, b);
        
        cout << a << " " << b << endl;

    }
}
