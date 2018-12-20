
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

int overlap(string& a, string&b, int k) {
    int al = a.size();
    FORR(ll, k, 1)  {
        if(b.substr(0,ll) == a.substr(al-ll, ll)) {
            return ll; 
        }
    }

    return 0;
}


int main(){
    int TC,w , k;

    cin >> TC;

    REP(i, TC) {
        cin >> k >> w;
        string s;
        int count = 0;

        REP(j, w) {
            if(s.size() == 0)  {
                cin >> s;
                count += s.size();
            } else {
                int idx = 0;
                string cur;
                cin >> cur;
                int l = s.size()-1;

                idx = overlap(s, cur, k);
                s.append(cur, idx, string::npos);
            }
        }

        printf("%lu\n", s.size());
    }
}

