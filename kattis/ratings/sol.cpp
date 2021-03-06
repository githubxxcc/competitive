
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
#define FORR(i, a, b) for (int i=a; i>=b; i--)
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
typedef vector<vi> vvi;

//dp = 31 x 15
//dp[0, i] = 1;
//dp[j,i] = dp[k, i-1] for k = 0->j;
void precompute(vector<vector<long long> > &dp) {
    //0 p, 15 c 
    FOR(i, 1, 15) {
        dp[0][i] = 1;
    }
    
    //any p, 1 c 
    FOR(i, 0, 30) {
        dp[i][1] = 1;
    }

    FOR(c, 2, 15) {
        FOR(p, 1, 30) {
            FOR(pp, 0, p) {
                dp[p][c] += dp[pp][c-1];
            }
        }
    }
}

int main(){

    int n;
    vector<vector<long long> > dp(31, vector<long long>(16, 0));
    precompute(dp);

    while(1) {
        cin >> n;

        if(n == 0) break;

        vi nums;
        long long sum = 0;

        REP(i, n) {
            int x;
            cin  >> x;
            nums.pb(x);
            sum += x;
        }
        
        long long cnt = 1;

        FOR(i, 0, sum-1) {
            cnt += dp[i][n];
        }

        FOR(c, 1, n-1) {
            int y = nums[c-1];
            FOR(j, 0, y-1) {
                cnt += dp[sum-j][n-c];
            }

            sum-=y;
        }

        cout << cnt << endl;
    }

}
