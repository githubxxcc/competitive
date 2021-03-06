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

int a, b, n, ax, ay, fx, fy, d;
char x;

int main () {
    while(scanf("%d %d\n", &a, &b), (a || b)) {
        cin >> n;
        ax = ay = fx = fy = 0;
        a--, b--;
        while(n--) {
            cin >> x >> d;
            switch(x) {
                case 'u': 
                   fy += d, ay = min(b, ay+d);
                   break;
                case 'd':
                   fy -= d, ay = max(0, ay-d);
                   break;
                case 'l':
                   fx -= d, ax = max(0, ax-d);
                   break;
                case 'r':
                   fx += d, ax = min(a, ax+d);
                   break;
            }
        }

        printf("Robot thinks %d %d\n", fx, fy);
        printf("Actually at %d %d\n\n",ax, ay);
    }
}
