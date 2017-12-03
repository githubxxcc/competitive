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



int d[9] = {-1, 0, 1, 0, -1, 1, 1, -1, -1};
int r, c, cnt, i, j;
bool nomore;
char mtx[100][100] = {};

bool 
has(char mtx[100][100], int i, int j)  {
    return i>= 0 && i < r && j >= 0 && j < c && mtx[i][j] == '#';
}


void
dfs(char mtx[100][100], int& cnt, int i, int j) 
{
    if(has(mtx, i, j))   {
        nomore = true;
        mtx[i][j] = '.';

       for(int ii = 0, jj = 1; ii < 8; ii++, jj++) {
           if(has(mtx, i+d[ii], j+d[jj]))
                   dfs(mtx, cnt, i+d[ii], j+d[jj]), nomore = false;
       }
       if(nomore) 
           cnt++;
    }
}

int main () 
{
    cin >> r >> c;
    cnt = 0;
    for(i = 0; i<r; i++)  {
        for(j =0; j<c; j++)
            cin >> mtx[i][j];        
    }
    
    for(i = 0; i<r; i++)  {
        for(j =0; j<c; j++)
            dfs(mtx,cnt, i, j);
    }

    cout << cnt;
}
