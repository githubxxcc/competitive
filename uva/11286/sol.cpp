#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <unordered_map>
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

int N, cl;

int main() {
    while(cin >> N, N) {
        map<vector<int>, int> mmap;
        REP(j,N){        
            vector<int> comb;
            REP(i, 5){
                cin >> cl;
                comb.pb(cl);
            }

            sort(comb.begin(), comb.begin()+5);
            mmap[comb]++;
        }

        
        int ans=0, max=0;
        
        for(auto itr =  mmap.begin(); itr != mmap.end(); itr++) {
            if(itr->second > max) 
                max = itr->second, ans = 0;

            if(itr->second == max)
                ans += max;
        }

        cout << ans << endl;
    }
}
