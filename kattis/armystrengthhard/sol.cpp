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

int TC, _G, G, _M, M, g, gi, mi;
vector<int> vm, vg;

int main()
{
    cin >> TC;

    while(TC--) {
        cin >> G >> M;
        _G = G, _M = M;

        while(_G--) {
            cin >> g;
            vg.push_back(g);
        }

        while(_M--) {
            cin >> g;
            vm.pb(g);
        }

        sort(ALL(vg)), sort(ALL(vm));
        gi = mi = 0;

        while(gi < G && mi < M) {
            if(vg[gi] < vm[mi]) gi++;
            else mi++;
        }

        if(gi == G && mi == M) cout << "uncertain";
        else if(gi == G) cout << "MechaGodzilla";
        else cout << "Godzilla";

        cout << endl;
        vg.clear(), vm.clear();
    }
}
