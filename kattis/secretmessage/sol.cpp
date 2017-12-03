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


char msg[100][100];
int i, idx, j, L, K, M, TC;
string line;

int main () {
    cin >> TC;

    while(TC--) {
        cin >> line;

        L = line.size();
        K = (int) sqrt(L-1)+1;
        M = K*K;
        line.append((size_t)(M-L), '*');
        idx = 0; 
        for(i = 0; i<K; i++) {
            for(j = 0; j<K; j++) 
                msg[i][j] = line[idx++];
        }

        for(i = 0; i < K; i++) {
            for(j = K-1; j>=0; j--) {
                if(msg[j][i] != '*')
                    cout << msg[j][i];
            }
        }

        cout << endl;

    }
}
