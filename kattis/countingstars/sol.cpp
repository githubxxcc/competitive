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


int dir[5] = {0, 1, 0, -1, 0};

void 
dfs( char matrix[100][100], int i, int j, int r, int c) {
    if(i < 0 || i >= r || j < 0 || j >= c || matrix[i][j] != '-') 
        return;

    matrix[i][j] = '#';

    for(int k = 0; k <4; k++) 
        dfs(matrix, i+dir[k], j+dir[k+1], r, c);
}

int 
count_starts(char matrix[100][100], int r, int c) {
    int cnt = 0;
    for(int i = 0; i<r ; i++) {
        for(int j = 0; j<c; j++) {
            if(matrix[i][j] == '-'){
                dfs(matrix, i, j, r, c);
                cnt++;
            }
        }
    }

    return cnt;
}

int main() {
    int tc, r, c;
    char matrix[100][100] = {};
   
    tc = 1;
    while(scanf("%d %d", &r, &c) != EOF) {
        for(int i = 0; i < r; i++) {
            for(int j = 0; j<c ; j++) 
                cin >> matrix[i][j];
        }

        printf("Case %d: %d\n", tc++, count_starts(matrix,r,c));
    }
}
