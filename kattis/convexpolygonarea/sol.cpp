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

int d8[9] = {-1, 0, 1, 0, -1, 1, 1, -1, -1};
int d4[5] = {-1, 0, 1, 0 , -1};
using namespace std;


int a[100][2] = {},n, _m, i, j, m ;
double ans;


int main() 
{
    cin >> n;

    while(n--) {
        cin >> m;
        _m = m;
        i = 0, ans = 0;
        while (_m--) {
           cin >> a[i][0] >> a[i][1]; 
           i++;
        }


        for(i =0, j = 1; j < m; i++, j++) {
            ans += a[i][0] * a[j][1];
        }

        ans += a[m-1][0] * a[0][1];


        for(i = 0, j = 1; j < m ; i++, j++) {
            ans -= a[i][1] * a[j][0];
        }

        ans -= a[m-1][1] * a[0][0];

        cout << setprecision(10) << ans/2.0 << endl;
    }
}
