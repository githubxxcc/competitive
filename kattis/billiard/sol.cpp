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
#include <iomanip>
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

int a, b, t, m, n;
int64 x_off, y_off;
double dis, angle;

int main() {
    while(scanf("%d %d %d %d %d\n", &a, &b,&t, &m, &n), (a || b || t ||m ||n)) 
    {
        x_off = a * m, y_off = b * n;
        dis = sqrt(x_off * x_off + y_off * y_off);
        angle = acos(x_off/dis) * 180.0 / PI;

        cout << fixed << setprecision(2);
        cout << angle << " " << dis/t << endl;
    }
}
