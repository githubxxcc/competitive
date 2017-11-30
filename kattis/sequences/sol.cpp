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
#define MOD 1000000007
using namespace std;


string line;

int count_inv(string & s, int idx,int cnt, int numq, int totalq) {
    int local, zeros, ones;
    auto size = s.size();
    if(idx == size) return cnt;
    char cur;
    
    cnt = cnt % MOD;
    while(idx <size && (cur = s[idx])!='?') {
        if(cur == '0')
            local += one, zero++;
        else 
            one++;

        local %= MOD;
        idx++;
    }

    if(idx >= size)
        return cnt;
    
     
    numq++;
    
    cnt += (totalq-numq) * (local+one+local)

}

int main() {
    cin >> line;
    int numq = 0;
    for(auto c : line) 
        numq++;

    cout << count_inv(line, 0,0,0, numq) << endl;

}
