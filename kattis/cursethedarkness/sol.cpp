
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

int main(){
    int m ,n;

    cin >> m;

    REP(i, m) {
        double x, y;
        bool can_light = false;

        cin >> x >> y;
        cin >> n;
        REP(j, n) {
            double c_x, c_y;

            cin >> c_x >> c_y;

            if(can_light) continue;

            double dis2 = pow((x-c_x), 2) + pow(y-c_y, 2);

            if(dis2 <= 8*8) {
                can_light = true; 
            }
        }

        if(can_light) {
            printf("light a candle\n");
        } else {
            printf("curse the darkness\n");
        }
    }
}
