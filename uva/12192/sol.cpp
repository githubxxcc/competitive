
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

int d8[9] = {-1, 0, 1, 0, -1, 1, 1, -1, -1};
int d4[5] = {-1, 0, 1, 0 , -1};
using namespace std;

typedef vector<int> vi;

int main()
{

    int N, M, i, j, k, ans, arr[501][501]={}, Q, U, L, ii, jj;

    while(scanf("%d %d\n", &N, &M), (N || M)) {
        vector<vi> v(N+M-1, vector<int>(0));

        REP(i, N) {
            REP(j, M) {
                cin >> arr[i][j];
            }
        }

        k = i = j = 0;
        while(i < N && j < M) {
            v[k].pb(arr[i++][j++]);
        }
        k++;

        FOR(i, 1, N-1) {
            j = 0, ii = i;
            while(ii < N && j < M) {
                v[k].pb(arr[ii++][j++]);
            }
            k++;
        }

        FOR(j, 1, M-1) {
            i = 0, jj = j;
            while(i < N && jj < M) {
                v[k].pb(arr[i++][jj++]);
            }
            k++;
        }
        cin >> Q;

        REP(i, Q) {
            cin >> L >> U;
            ans = 0;
            for(auto vv : v) {
                //D_PSTL("vv", vv);
                auto lo = lower_bound(ALL(vv), L);
                auto hi = upper_bound(ALL(vv), U);

                ans = max(ans, (int)(hi-lo));
            }
            
            cout << ans << endl;
        }

        cout << "-" << endl;
    }
}
