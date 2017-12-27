
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

typedef vector<int> vi;

int
solve(string &s) {
    int cnt = 0;
    char c;

    REP(i, s.length()) {
        c = s[i];

        switch(c) {
            case 'a':
            case 'e':
            case 'o':
            case 'i':
            case 'u':
            case 'y':
                if(i+1 < s.length() && s[i+1] == c)
                    i+=2, cnt++;
                break;
        }
    }

    return cnt;
}


int main()
{
    int N, cnt, x;
    string s, ans;
    while(cin >> N, N) {
        cnt = 0;
        REP(i, N) {
            cin >> s;
            if(cnt <= (x = solve(s))) {
                cnt  = x;
                ans = s;
            }
        }

        cout << ans << endl;

    }
}
