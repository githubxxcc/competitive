
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

typedef vector<int> vi;


#define LSOne(S) (S & (-S))

class FenwickTree {
    private:
        vector<int64> ft;

    public:
        FenwickTree() {}
        // initialization: n + 1 zeroes, ignore index 0
        FenwickTree(int n) { ft.assign(n + 1, 0); }

        int64 rsq(int b) {                                     // returns RSQ(1, b)
            int64 sum = 0; for (; b; b -= LSOne(b)) sum += ft[b];
            return sum; }

        int64 rsq(int a, int b) {                              // returns RSQ(a, b)
            return rsq(b) - (a == 1 ? 0 : rsq(a - 1)); }

        // adjusts value of the k-th element by v (v can be +ve/inc or -ve/dec)
        void adjust(int k, int64 v) {                    // note: n = ft.size() - 1
            for (; k < (int)ft.size(); k += LSOne(k)) ft[k] += v; }
};


int main ()
{
    int N, Q, i, a,b;
    int64 v;
    char c;
    cin >> N >> Q;

    FenwickTree ft(N+1);

    REP(i, Q) {
        cin >> c;

        switch(c) {
            case '+':
                cin >> a >> v;
                ft.adjust(a+1, v);
                break;
            case '?':
                cin >> b ;
                cout <<  (b == 0 ? 0 :ft.rsq(b)) << endl;
                break;
        }
    }
}
