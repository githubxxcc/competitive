
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


//pufd
typedef vector<int> vi;
typedef vector<vi> vvi;

int _idx = 0;

string init_wake;
int N, M, i, _round;
char a, b;
vi tmap;

int
idx(char c)
{
    if(tmap[c-'A'] == -1) { tmap[c-'A'] = _idx; return _idx++;}
    else return tmap[c-'A'];
}

void
connect(vvi &mmap, int ai, int bi) 
{
    mmap[ai].pb(bi), mmap[bi].pb(ai);
}


void 
init(int N, unordered_map<int, vi> &map_adj, vvi &mmap, vi &wakes) 
{
    REP(i, N) {
        vi v, vv;
        map_adj[i] = v;
        mmap.pb(vv);
    }

    wakes.assign(26, 0);
}

int
solve (unordered_map<int, vi>& map_adj, vi &cur, vi &wakes, vvi &mmap,int curCnt, int remain, int round) {

    
    while(1) 
    {
        vi adj, next, wake_adj;
        REP(i, curCnt) {
            wakes[cur[i]] = 1;
            adj = mmap[cur[i]];

            for(auto neigh : adj) {
                if(wakes[neigh] != 1) {
                    wake_adj = map_adj[neigh];
                    if(wake_adj.size() == 2)
                        next.pb(neigh);
                    map_adj[neigh].pb(cur[i]);
                }
            }
        }

        if(remain == 0) return round;
        else if(curCnt == 0) return 0;

        remain -= curCnt;
        round++;
        curCnt = next.size();
        cur = next;
    }
}




int main()
{
    while(scanf("%d\n%d\n", &N, &M)!= EOF) {
        vi wakes;
        vvi mmap;
        unordered_map<int, vi> map_adj;

        _idx = 0;
        tmap.assign(26,-1);

        getline(cin, init_wake);
        init(N, map_adj, mmap, wakes);

        REP(i, M) {
            scanf("%c%c\n", &a, &b);
            connect(mmap, idx(a), idx(b));
        }

        vi cur;
        REP(i, init_wake.length()) {
            cur.pb(idx(init_wake[i]));
        }

        _round = solve(map_adj, cur, wakes, mmap,init_wake.length(), N, 0);

        if(_round != 0) 
            printf("WAKE UP IN, %d, YEARS\n", _round-1);
        else
            cout << "THIS BRAIN NEVER WAKES UP" <<endl;

        scanf("\n");
    }
}
