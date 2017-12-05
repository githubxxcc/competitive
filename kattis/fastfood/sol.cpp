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

int d8[9] = {-1, 0, 1, 0, -1, 1, 1, -1, -1};
int d4[5] = {-1, 0, 1, 0 , -1};
using namespace std;


int n, m, k, ki, ti, lmin, total, TC;
vector<vector<int> > prize;


int main() 
{
    cin >> TC;

    while(TC--) {
        cin >> n >> m;
        total = 0;

        while(n--) {
           cin >> k;
            vector<int> v;  
            k++;
           while(k--) {
                cin >> ki;
                v.push_back(ki);
           }

           prize.push_back(v);
        }
        
        vector<int> t(m, 0);
        for(int i = 0; i< m; i++) {
            cin >> ti;
            t[i] = ti;
        }


        for(auto& p: prize) {
            int _size = p.size()-1;
            lmin =200;

            for(int i = 0 ; i<_size; i++) {
                lmin = min(lmin, t[p[i]-1]);
            }
           
            total += p[_size] * lmin;
        }

        cout << total << endl;

        prize.clear(), t.clear();
        
    }
}
