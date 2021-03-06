
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


int inline 
idx(char x) {
    if(x >= 'A' && x <= 'Z')
        return x- 'A';
    else 
        return 26+x-'a';
}

int main() 
{
    
    int lo, hi, Q, i, x;
    string S, q;
    vector<int> v;
    bool found;
    vector<vector<int> > vs(52, vector<int>(0));
    
    cin >> S;

    REP(i, S.size()) {
        vs[idx(S[i])].pb(i);
    }

    cin >> Q;
    
    REP(i, Q) {
        cin >> q;
        lo = hi = -1;
        x = 0;
        found = true;
        
        for(auto c : q) {
            v = vs[idx(c)];
            auto itr = lower_bound(ALL(v), x);
            if(itr != v.end()) {
                if(lo == -1) {
                    hi = lo = *itr;
                } else {
                    hi = *itr;
                }

                x = *itr +1;
            } else {
                found = false;
                break;
            }
        }

        if(!found) 
            printf("Not matched\n");
        else 
            printf("Matched %d %d\n", lo, hi);
    }
}
