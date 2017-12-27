
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
        vi ft;

    public:
        FenwickTree() {}
        // initialization: n + 1 zeroes, ignore index 0
        FenwickTree(int n) { ft.assign(n + 1, 0); }

        int rsq(int b) {                                     // returns RSQ(1, b)
            int sum = 0; for (; b; b -= LSOne(b)) sum += ft[b];
            return sum; }

        int rsq(int a, int b) {                              // returns RSQ(a, b)
            return rsq(b) - (a == 1 ? 0 : rsq(a - 1)); }

        // adjusts value of the k-th element by v (v can be +ve/inc or -ve/dec)
        void adjust(int k, int v) {                    // note: n = ft.size() - 1
            for (; k < (int)ft.size(); k += LSOne(k)) ft[k] += v; }

};


int main()
{
    int N, K, x, y, i;
    char c;
    cin >> N >> K;

    FenwickTree ft(N);

    REP(i, K) {
        cin >> c;

        switch(c) {
            case 'C':
                cin >> x >> y;
                cout << ft.rsq(x, y) << endl;
                break;
            case 'F':
                cin >> x;
                ft.rsq(x,x) == 1 ? ft.adjust(x, -1) : ft.adjust(x, 1);
        }
    }

}
