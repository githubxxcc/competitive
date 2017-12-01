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

int TC, i, j, idx,n;
char mtx[1000][1000] = {};
string line;

int main()
{
    scanf("%d\n", &TC);
    while(TC--) {
        idx =0;
        getline(cin, line);
        n = sqrt(line.size());

        for(i = 0; i<n; i++)
        {
            for(j = 0; j<n; j++) {
                mtx[i][j] = line[idx++];
            }
        }


        for(i = n-1; i>=0; i--) {
            for(j = 0; j<n; j++) {
                cout << mtx[j][i];
            }
        }

        cout << endl;
    }
}
