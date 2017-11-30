/*
 * =====================================================================================
 *
 *       Filename:  ref.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  11/28/17 09:36:46
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ricky (), xuchen727@hotmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include <cstdio>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <sstream>
using namespace std;
/*
#define PQ priority_queue
#define P pair<int,int>
#define CLA(array) memset(array,0,sizeof array)
#define CLINF(array) memset(array,0x3f,sizeof array)
#define CLF(array) memset(array,-1,sizeof array)
#define DB(a) cout << "DEBUG " << a << endl;
*/
typedef long long LL;
typedef unsigned long long ULL;
const int MAXN = 100000 + 50;
const int INF = 1 << 30;
const LL MOD = 1000000007;
LL qpow(int n){
    if(n == -1) return 1;
    LL ret = 1,a = 2;
    while(n){
        if(n & 1){
            ret = (ret * a) % MOD;
        }
        n >>= 1;
        a = (a * a) % MOD;
    }
    return ret;
}
int main(){
    //ios_base::sync_with_stdio(false);
    string a;
    int num0 = 0,numq = 0,sumq = 0;
    LL ans = 0;
    cin >> a;
    for(auto c : a){
        if(c == '?') sumq++;
    }
    for(int i = a.size() - 1;i >= 0; --i) {
        if(a[i] == '?'){
            ans += qpow(sumq - numq - 1) * ((numq * qpow(numq-1) + num0 * qpow(numq)) % MOD);
            //ans = (numq * num0 + ans) % MOD;
            ans %= MOD;
            numq++;
        }
        else if(a[i] == '0') num0++;
        else{
            ans += qpow(sumq - numq) * ((numq * qpow(numq - 1) + num0 * qpow(numq)) % MOD);
            ans %= MOD;
            //ans = (numq * num0 + ans) % MOD;
        }
    }
    cout << ans << endl;
    return 0;
}
