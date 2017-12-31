
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <deque>
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


int
rec(int cnt, deque<int> &dam, unordered_set<int> &res) {
    int i, x, ans = cnt;


    if(cnt == 0 || res.size() == 0) return cnt;

    REP(i, cnt) {
        x = dam.front();
        dam.pop_front();

        if(res.count(x-1)) {
            res.erase(x-1);
            ans = min(ans, rec(cnt-1, dam, res));
            res.insert(x-1);
        } else {
            if (res.count(x+1)) {
                res.erase(x+1);
                ans = min(ans,rec(cnt-1, dam, res));
                res.insert(x+1);
            }
        }

        dam.pb(x);
    }

    return ans;
}

int main()
{
    int N, S, R, i, x,_s, ans;
    deque<int> dam;
    unordered_set<int> res;

    cin >> N >> S >> R;
    

    REP(i, S) {
        cin >> x;
        dam.pb(x);
    }

    REP(i, R) {
        cin >> x;
        res.insert(x);
    }

    //take into account those dmg but have res
    _s = S; 
    REP(i, S) {
        x = dam.front();
        dam.pop_front();

        if(res.count(x)) res.erase(x), _s--;
        else dam.pb(x);
    }
   
    ans = rec(_s, dam, res);

    cout << ans << endl;
}
