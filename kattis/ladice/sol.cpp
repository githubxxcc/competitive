
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




//pufd
typedef vector<int> vi;

// Union-Find Disjoint Sets Library written in OOP manner, using both path compression and union by rank heuristics
class UnionFind {                                              // OOP style
    private:
        vi p, rank, setSize, items;                       // remember: vi is vector<int>
        int numSets;
    public:
        UnionFind(int N) {
            setSize.assign(N, 1); numSets = N; rank.assign(N, 0);
            items.assign(N, 0);
            p.assign(N, 0); for (int i = 0; i < N; i++) p[i] = i; }
        int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
        bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
        void unionSet(int i, int j) {
            if (!isSameSet(i, j)) { numSets--;
                int x = findSet(i), y = findSet(j);
                // rank is used to keep the tree short
                if (rank[x] > rank[y]) { p[y] = x; setSize[x] += setSize[y]; items[x]+=items[y]; }
                else                   { p[x] = y; setSize[y] += setSize[x]; items[y]+=items[x];
                    if (rank[x] == rank[y]) rank[y]++; } } }
        int numDisjointSets() { return numSets; }
        int sizeOfSet(int i) { return setSize[findSet(i)]; }
        int numOfItems(int i) { return items[findSet(i)]; }
        void addItem(int i) { items[findSet(i)]++;}

};


int main ()
{
    int N, L, A, B, i;

    cin >> N >> L;
    UnionFind ufd(L+1);

    REP(i, N) {
        cin >> A >> B;
        ufd.unionSet(A, B);
        if(ufd.numOfItems(A) < ufd.sizeOfSet(A)) {
            ufd.addItem(A);
            cout << "LADICA" << endl;
        } else {
            cout << "SMECE" << endl;
        }
    }
}
