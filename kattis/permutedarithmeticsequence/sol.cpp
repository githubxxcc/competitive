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

using namespace std;


bool
valid(int seq[100], int m)
{
    int diff = seq[1]-seq[0];

    for(int i = 1; i < m-1; i++) {
        if(seq[i+1] - seq[i] != diff) 
            return false;
    }

    return true;
}

int TC, m, seq[100], i;

int main() 
{
    cin >> TC;

    while(TC--) {
        cin >> m;

        for(i = 0; i<m; i++) {
            cin >> seq[i];
        }

        if(valid(seq, m)) 
            cout << "arithmetic" << endl;
        else if(sort(seq, seq+m), valid(seq, m)) 
            cout << "permuted arithmetic" << endl;
        else 
            cout << "non-arithmetic" << endl;
    }
}
