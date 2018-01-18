
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
#define ALL(x) x.begin(), x.end()
#define D_PSTL(msg, stl) cout << msg<< endl; for(auto x: stl) cout << x << " "; \
    cout << endl << endl;
#define E 1e-7

int d8[9] = {-1, 0, 1, 0, -1, 1, 1, -1, -1};
int d4[5] = {-1, 0, 1, 0 , -1};
using namespace std;

typedef vector<int> vi;

int p, q, r, s, t, u;
double lo, hi, mid, val, ans;

double
f(double x) 
{
    return p * exp(-1 * x) + q * sin(x) + r * cos(x) + s * tan(x) + t * x * x + u;
}

int main()
{
    while(cin >> p >> q >> r >> s >> t >> u) {

        lo = 0.0, hi = 1.0, ans = -1.0;

        while(lo < hi) {
            mid = (hi + lo)/2.0;
            val = f(mid);
            if(fabs(val) < E) {
                ans = mid;
                break;
            } else if(val > 0) {
                lo = mid;
            } else 
                hi = mid;
        }

        if(ans != -1.0) 
            printf("%.4lf\n", ans);
        else 
            printf("No solution\n");
    }
}
