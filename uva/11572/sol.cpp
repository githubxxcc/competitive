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

int TC, n, last, x;

int main() {
    cin >> TC;

    while(TC--) {
        cin >> n;
        int i, l, g;
        i = l = g = 0;
        unordered_map<int, int> map;

        while(n--) {
            cin >> x;
            if(map.count(x)) {
                last = map[x];
                if(last >= i-l) {
                    l = i-last;
                } else {
                    l++;
                }
            } else {
                l++;
            }
            
            g = max(l, g);
            map[x] = i;
            i++;
        }

        cout << g << endl;
    }
}
