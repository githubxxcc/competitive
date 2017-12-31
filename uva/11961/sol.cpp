
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

char DNAs[4] = { 'A', 'G', 'C', 'T'};

void
rec(string &next, vector<string> &ans, int cur, int N, int K) 
{
    if(K <  0 || cur == N) return;
    ans.pb(string(next));


    for(auto dna : DNAs) {
        for(int c = cur; c < N ; c++) {
            char prev = next[c]; 
            if(dna != prev) {
                next[c] = dna;
                rec(next, ans, c, N, K-1);
                next[c] = prev;
            }
        }
    }

    return;    
}

int main()
{
    int TC, N, K;
    string init;

    scanf("%d\n", &TC);
    REP(i, TC) {
        scanf("%d %d\n", &N, &K);
        cin >> init;

        vector<string> ans;

        rec(init, ans, 0, N, K);
        sort(all(ans));

        auto it = unique(all(ans));
        ans.resize(distance(ans.begin(), it));
        
        cout << ans.size() << endl;
        for(auto x :ans) cout << x << endl;
    }
}
