
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
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



//pufd
typedef vector<int> vi;

// Union-Find Disjoint Sets Library written in OOP manner, using both path compression and union by rank heuristics
class UnionFind {                                              // OOP style
    private:
        vi p, rank, setSize, cooked;                       // remember: vi is vector<int>
        int numSets, count;
    public:
        UnionFind(int N) {
            setSize.assign(N, 1); numSets = N; rank.assign(N, 0);
            count = 0;
            p.assign(N, 0); for (int i = 0; i < N; i++) p[i] = i; }
        int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
        bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
        void unionSet(int i, int j) {
            if (!isSameSet(i, j)) { numSets--; 
                int x = findSet(i), y = findSet(j);
                // rank is used to keep the tree short
                if (rank[x] > rank[y]) { p[y] = x; setSize[x] += setSize[y]; }
                else                   { p[x] = y; setSize[y] += setSize[x];
                    if (rank[x] == rank[y]) rank[y]++; } } }
        int numDisjointSets() { return numSets; }
        int sizeOfSet(int i) { return setSize[findSet(i)]; }
        void addCount(int i) { count++; cooked.pb(i);}
        int getCount() { return count;}
        vector<int> getCooked() { return cooked;}
};



bool
can_concoct(vector<int> &v, UnionFind &ufd) 
{
    unordered_set<int> sset;
    int sum, need, cooked;
    need = cooked = 0;

    for(auto x : v) {
        if(ufd.sizeOfSet(x) > 1) {
            sset.insert(ufd.findSet(x));
            need++;
        }
    }

    for(auto y : sset) {
        cooked += ufd.sizeOfSet(y);
    }

    int count = 0;
    if(need == cooked) {
        for(auto y: v) {
            if(count++ == 0) {
                sum = y;
            } else {
                ufd.unionSet(y, sum);
            }
        }

        return true;
    } else {
        return false;
    }
}

int main()
{
    int n, j, i, m, x, ans= 0;
    vector<int> v;
    UnionFind ufd(500009);

    cin >> n;

    REP(i, n) {
        cin >> m;

        REP(j, m) {
            cin >> x;
            v.pb(x);
        }

        if(can_concoct(v, ufd)) 
            ans++;

        v.clear();
    }

    cout << ans << endl;
}


