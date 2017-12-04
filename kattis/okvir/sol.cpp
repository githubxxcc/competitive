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
int M, N, u, l, r, d, i, c;
bool dot;
string w;

int main() 
{
    scanf("%d %d\n", &M, &N);
    scanf("%d %d %d %d\n", &u, &l, &r, &d);
    for(i = 0; i<u; i++) {
        dot = (i % 2 == 1);
        for(c = 0; c < N + l + r; c++) {
            cout << (dot? "." : "#");
            dot = !dot;
        }

        cout << endl;
    }

    for(; i<M+u; i++) {
        dot = (i % 2 == 1);
        for(c = 0; c < l; c++) {
            cout << (dot? "." : "#");
            dot = !dot;
        }

        cin >> w, cout << w;
        if(N % 2) 
            dot = !dot;

        for(c = l+N; c < N+l+r; c++) {
            cout << (dot ? "." : "#");
            dot = !dot;
        }
        cout << endl;
    }

    for(; i < M + u + d; i++) {
        dot = (i %2 == 1);
        for(c = 0; c < N + l + r; c++) {
            cout << (dot? "." : "#");
            dot = !dot;
        }
        cout << endl;
    }
}
