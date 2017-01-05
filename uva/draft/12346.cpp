/* ALgorithm:
 *
 * - construct a bitmap
 *   - iteratur through it (2 ^ 20) 
 *   - based on the ON bits, access the map array to calculate the efficienct
 *   - compare the cost 
 *   update minim 
 */

#include <cmath>
#include <iostream>
using namespace std;
#define toggleBit(S, j) ( S^=(1<<j))

int main()
{
    int n, m;
    int fl[20],c[20];

    cin >> n;
    for(int i = 0; i< n; i++){
        cin >> fl[i] >> c[i];
    }

    cin >> m;
    int m_ori = m;
    int lf, t,tf,tc;
    int minC= 100000000;
    bool ok;
    while(m--){
        cin >> lf >> t;
        ok = false;
        for(int k = 0; k<(1<<n); k++){
        tf = tc = 0;
            for(int j =0; (k>>j) >0; j++){
                if(k & (1 << j)){
                    tf += fl[j]*t;
                    tc += c[j];
                }
            }
            if(tf>= lf){
                ok = true;

                if(tc < minC){
                    minC = tc;
                }
            }
        }
        if(ok){
            printf("Case %d: %d\n",m_ori - m, minC);    
        }else{
            printf("Case %d: IMPOSSIBLE\n", m_ori-m);
        }
    }
}
