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
#include <iomanip>
#include <sstream>

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


void
multi(int p1[800], int p2[800], int d1, int d2) {
    int64 cum;
    int k;
    for(int d = 0; d <= d1 + d2; d++) {
        cum = 0;
        for(int i = max(0, d-d2); i <= min(d, d1); i++) {
            cum += p1[i] * p2[d-i];
        }
        if(d > 0) cout << " ";
        cout << cum;
    }
    cout << endl;
}

int p1[800] = {}, p2[800] = {}, TC, i, d1, d2, _d1, _d2;

int main() 
{
    cin >> TC;

    while(TC--) {
        cin >> d1;
        _d1 = d1+1;

        for(i = 0; i<_d1; i++) 
            cin >> p1[i];

        cin >> d2;
        _d2 = d2+1;
        for(i = 0; i<_d2; i++)
            cin >> p2[i];

        cout << d1+d2 << endl;
        multi(p1, p2, d1, d2);
    }
}
