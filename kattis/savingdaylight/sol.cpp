#include <algorithm>
#include <unordered_map>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <sstream>
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


char buf[40] = {};
int sh, sm, eh, em, diff;
string line, m, d, y, s, e;

int 
compute(const char* s, const char * e, char* buf) 
{
    
    sscanf(s, "%d:%d", &sh, &sm);
    sscanf(e, "%d:%d", &eh, &em);
    diff = (eh * 60 + em - sh * 60 - sm);
    return  sprintf(buf, "%d hours %d minutes ", diff/60, diff%60);
}

int main() 
{
    while(getline(cin, line)) {
        istringstream iss(line);
        iss >> m, cout << m << " ";
        iss >> d, cout << d << " ";
        iss >> y, cout << y << " ";
        iss >> s >> e;
        compute(s.c_str(), e.c_str(), buf); 
        printf("%s\n", buf); 
    }
}
