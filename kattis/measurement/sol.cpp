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



int main() {
 unordered_map<string, int> umap( {{"th", 1},
    {"thou", 1},
    {"inch", 1000}, {"in", 1000},
    {"foot", 12000}, {"ft", 12000},
    {"yard", 36000}, {"yd", 36000},
    {"ch",792000}, {"chain", 792000},
    {"fur", 7920000}, {"furlong", 7920000},
    {"mile", 63360000}, {"mi", 63360000},
    {"league", 190080000}, {"lea", 190080000}} );

    char u[50], uu[50];
    double x;
    
    scanf("%lf %s in %s", &x, u, uu);
    string us (u), uus(uu);

    cout << fixed << setprecision(10) <<  x * umap[us] / umap[uus] << endl;
}



