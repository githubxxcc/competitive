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



int main() 
{
double j1, j2, j3, r1, r2, r3, minr;
    cin >> j1 >> j2 >> j3;
    cin >> r1 >> r2 >> r3;

    minr = min((j1/r1), (j2/r2));
    minr = min(minr, (j3/r3));

    cout << fixed << setprecision(6) << j1-minr*r1 << " " << j2-minr*r2 << " " << j3-minr * r3 << endl;
}
