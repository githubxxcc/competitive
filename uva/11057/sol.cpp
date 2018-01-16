
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
    int i, n, p, k, j, x, val,tc = 0,t;
    vi v(10000);
    while(scanf("%d\n", &n) != EOF) 
    {
    //    REP(k, n) {
    //        cin >> x;
    //        mmap[x]++;
    //    }

    //    cin >> p;
    //    i = 0, j = p;
    //    for(auto pair: mmap) {
    //        val = pair.first;
    //        if(val *2 == p) {
    //            if(mmap[val] > 1){
    //                i = j = val;
    //                break;
    //            }
    //        } else {
    //            if(mmap.count(p-val)) {
    //                if(abs(val-p+val) < abs(i-j)) {
    //                    i = val,j = p-val;
    //                }
    //            }
    //        }
    //    }
    //    
    //    if( i > j) { t = i, i = j, j = t;}
    //
    
        REP(k, n) {
            cin >> v[k];   
        }

        cin >> p;
        sort(v.begin(), v.begin()+n);
        i = 0, j = p;

        for(auto itr = v.begin(); itr != v.begin()+n; itr++) {
            val = p - *itr;
            auto k = lower_bound(v.begin(), v.begin()+n, val);
            if(k != itr && *k + *itr == p) {
                if(abs(*k- *itr) < abs(i-j))
                    i = *k, j = *itr;
            }
        }

        if( i > j) { t = i, i = j, j = t;}

        printf("Peter should buy books whose prices are %d and %d.\n\n", i, j);
        scanf("\n");
    }
}
