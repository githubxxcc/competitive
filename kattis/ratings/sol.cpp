
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


long
FAC(int s, int e) 
{
    long ans = 1;
    for(int i = s; i <= e ;i++) ans *= i;
    return ans;
}


long
dup_comb(int stars, int bars) 
{
        return FAC(stars+1, stars+bars-1) / FAC(1, bars-1);
}


int 
perm_sum(int sum, vector<int> &v, int size)
{
    long ans = 0;
    
    ans += dup_comb(sum-1, size);

    for(int i = 0; i<size; i++) { /* to last number */
        for(int j = 0; j < v[i]; j++) {
            ans += dup_comb(sum-j, size-i-1);
        }

        sum -= v[i];
    }

    return ans+1;
}




int main()
{

    int n, sum;
    long ans;
    vector<int> v(15, 0);

    while(cin >> n, n) {
        for(int i = 0; i<n; i++) {
            cin >> v[i];
            sum += v[i];
        }

        ans = perm_sum(sum, v, n);

        cout << ans << endl;
        v.clear(); sum = 0;
    }
}
