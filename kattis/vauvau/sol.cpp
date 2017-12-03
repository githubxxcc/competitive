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

int a,b,c,d,p1,p2,p3;

string
attack(int p) 
{
    int cnt = 0;

    if((p % (a + b)) <= a && (p%(a+b)) != 0) 
        cnt++;
    
    if((p % (c + d)) <= c && (p%(d+c)) != 0)
        cnt++;
    
    switch(cnt)
    {
        case 0:
            return "none";
        case 1:
            return "one";
        case 2:
            return "both";
    }
    return "none";
}

int main() {
    cin >> a >> b >> c >> d >> p1 >> p2 >> p3;

    cout << attack(p1) << endl;
    cout << attack(p2) << endl;
    cout << attack(p3) << endl;
}
