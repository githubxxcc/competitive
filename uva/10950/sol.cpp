
#include <algorithm>
#include <unordered_map>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <list>
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
#define D_PSTL(msg, stl) cout << msg<< endl; for(auto x: stl) cout << x << " "; \
    cout << endl << endl;

int d8[9] = {-1, 0, 1, 0, -1, 1, 1, -1, -1};
int d4[5] = {-1, 0, 1, 0 , -1};
using namespace std;

typedef vector<int> vi;


void 
_solve(vector<string> &ans, list<char> &word, char mmap[100], int code) 
{
    if(code == 0) ans.pb(string(all(word)));

    int digit = code % 10;

    if(digit  == 0) {
        _solve(ans, word, mmap, code/10);

        digit  = code % 100;
        if(digit != 0 && mmap[digit] != '.') {
            word.push_front(mmap[digit]); 
            _solve(ans, word, mmap, code/100);
        }
    } else {
        if(mmap[digit] != '.') {
            word.push_front(mmap[digit]);
            _solve(ans, word, mmap, code/10);
        }
    }
}

void
solve(char mmap[100], int code) {
    vector<string> ans;
    list<char> word;
    _solve(ans,word, mmap, code);

    for(auto x : ans) cout << x << endl;
}


int main()
{
    int tc = 1, N, i, d;
    char a;
    string code;

    char mmap[100];

    while(cin >> N, N != 0) {
        Fill(mmap, '.');
        REP(i, N) {
            cin >> a >> d;
            mmap[d] = a;
        }

        cin >> code;
        
        if(tc > 1) cout << endl;
        printf("Case #%d\n", tc++);
        solve(mmap,code);
    }
}
