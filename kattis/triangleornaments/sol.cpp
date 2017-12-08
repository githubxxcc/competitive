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

int d8[9] = {-1, 0, 1, 0, -1, 1, 1, -1, -1};
int d4[5] = {-1, 0, 1, 0 , -1};
using namespace std;



double
t_width(int a, int b, int c) 
{
    double p = (a+b+c)/2.0;
    double area = sqrt(p * (p-a) * (p-b) * (p-c));
    double mc = sqrt(2.0*a*a + 2 * b * b - c *c)/2;
    return 2* area/mc;
}

int n, a, b, c;
double ans;
int main()
{
    cin >> n;
    ans = 0.0;
    while(n--) {
        cin >> a >> b >> c;
        ans += t_width(a,b,c);
    }

    cout << fixed << setprecision(8)<< ans << endl;
}
