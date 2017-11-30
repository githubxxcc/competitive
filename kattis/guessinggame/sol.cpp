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
using namespace std;

string r;

int main() {
    int low = 0, high = 11, gs;
    bool cheat = false;

    while(scanf("%d\n", &gs), gs) {

        getline(cin, r);

        if(r =="too high")
            high = min(high, gs);
        else if(r == "too low")
            low = max(low, gs);
        else if(r == "right on") {
            if(gs <= low || gs >= high)
                cheat = true;

            if(cheat)
                cout << "Stan is dishonest\n";
            else 
                cout << "Stan may be honest\n";
            cheat = false, low = 0, high = 11;
        } else {
            cout <<r;
        }

        if(low +1 >= high) 
            cheat = true;
    }
}
