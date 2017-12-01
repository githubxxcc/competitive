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
using namespace std;

#include <cmath>

int mtx[3][24] = {};
int dp[4][25] = {};
int cnt = 0;



void
mark(float x, float y) 
{
    mtx[(int)floor(x)][(int)floor(y)] = 1;
}

int i, j;

int count(int m) {
    
    for(i = 0; i<=m; i++)
        dp[0][i] = 1;

    for(i = 0 ; i <= 3; i++)
        dp[i][0] = 1;

    dp[1][1] = 1-mtx[0][0];
    dp[0][0] = 1;

    for(i = 1; i<=3; i++) {
        for(j = 1; j<=m; j++) {
            if(i == 1 && j == 1) continue;
            if(mtx[i-1][j-1] == 0) {
                if(i-2 >= 0 && mtx[i-2][j-1] == 0)
                    dp[i][j] += dp[i-2][j] + dp[i][j-1] - dp[i-2][j-1];

                if(j-2 >= 0 && mtx[i-1][j-2] == 0)
                    dp[i][j] += dp[i][j-2] + dp[i-1][j] - dp[i-1][j-2];
            }

            dp[i][j] += dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];
        }
    }
    
    return dp[3][m];
}

int m, n;
float x, y;

int main()
{
    cin >> m >> n;

    while(n--) {
        cin >> x >> y, mark(x, y);
    }
    
    cout << count(m) << endl;
}
