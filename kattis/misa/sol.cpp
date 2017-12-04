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


int d8[9] = {-1, 0, 1, 0, -1, 1, 1, -1, -1};

char mtx[50][50] = {};
int i, j, ii, jj, _i, _j, cnt = 0, me, S, R;

int
canShake(int i, int j) 
{
    int loc = 0;
    if(i < 0 || i >= R || j < 0 || j >= S || mtx[i][j] == 'o')
        return 0;

    for(ii = 0, jj = 1; ii < 8; ii++, jj++) {
        _i = i + d8[ii], _j = j + d8[jj];
        if(_i < 0 || _j < 0 || _i >= R || _j >= S || mtx[_i][_j] == '.')
            continue;

        loc++;
    }

    return loc;
}


void 
dfs(int i, int j)
{
    if(i < 0 || i >= R || j < 0 || j >= S || mtx[i][j] == '.')
        return;
    
    if(i-1>=0 && mtx[i-1][j] == 'o') cnt++;
    if(j-1>=0 && mtx[i][j-1] == 'o') cnt++;
    if(i-1>=0 && j-1 >= 0 && mtx[i-1][j-1] == 'o') cnt++;
    if(i+1<R &&j-1 >= 0 && mtx[i+1][j-1] == 'o') cnt++;
}




int main() {
    cin >> R >> S;

    for(i = 0; i<R ; i++) {
        for(j = 0; j< S; j++) {
            cin >> mtx[i][j];
        }
    }

    me = 0;

    for(i = 0; i<R; i++) {
        for(j = 0; j< S; j++) {
            me = max(me, canShake(i, j));
        }
    }

    for(i = 0; i<R; i++) {
        for(j = 0; j<S; j++) {
            dfs(i,j);
        }
    }

    cout << cnt + me<<endl;
}
