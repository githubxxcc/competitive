#include <algorithm>
#include <unordered_map>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <vector>

#define FileIn(file) freopen(file".inp", "r", stdin)
#define FileOut(file) freopen(file".out", "w", stdout)
#define FOR(i, a, b) for (int i=a; i<=b; i++)
#define REP(i, n) for (int i=0; i<n; i++)
#define Fill(ar, val) memset(ar, val, sizeof(ar))
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define all(ar) ar.begin(), ar.end()
#define pb push_back
#define bit(n) (1<<(n))
#define Last(i) ( i & -i )
#define INF 500000000
#define maxN 101
#define RALL(x) x.rbegin(), x.rend()
using namespace std;


bool ayoda, byoda;

int main() 
{
    int a, b, azero, bzero, aa, bb;
    cin >> a >> b;
    ayoda = byoda = true;
    azero = bzero = 1;
    aa = bb = 0;

    while(a || b) {
        if(a % 10 > b % 10) {
            ayoda = false;
            aa += (a%10) * azero, azero *=10;
        } else if (a % 10 < b % 10) {
            byoda = false;
            bb += (b%10) * bzero, bzero *= 10;
        } else {
            ayoda = byoda = false;
            bb += (b%10) * bzero, bzero *= 10;
            aa += (a%10) * azero, azero *=10;
        }

        a/= 10, b/=10;
    }

    if( a > 0) 
        aa += a * azero;

    if( b > 0)
        bb += b * bzero;
    if(ayoda) 
        cout << "YODA" << endl;
    else 
        cout << aa << endl;

    if(byoda) 
        cout << "YODA" << endl;
    else 
        cout << bb << endl;

}
