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
#define RALL(x) x.rbegin(), x.rend()
using namespace std;

deque<int> reds, blus;
int TC, n, d, tc, i, red_more, ans, loop;
char c;


int main() {
    cin >> TC;
    tc = 0;
    while(TC--) {
        cin >> n;
        ans = i  =0;
        while(n--) {
            scanf("%d%c", &d, &c);

            switch(c) {
                case 'R': 
                    reds.push_back(d);
                    break;
                case 'B':
                    blus.push_back(d);
                    break;
            }
        }

        sort(RALL(reds));
        sort(RALL(blus));
    
        red_more = reds.size() -  blus.size();
        loop = min(reds.size(), blus.size());
        if(loop == 0)
            goto end;
        while(i < loop) {
            ans += reds.front(), ans+=blus.front();
            reds.pop_front(), blus.pop_front();
            i++;
        }
        
        ans -= i*2;
end:
        printf("Case #%d: %d\n", ++tc, ans);
        reds.clear();
        blus.clear();
    }
}
