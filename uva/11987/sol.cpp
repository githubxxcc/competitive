
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
        vi p, rank, setSize, sumSet;                       // remember: vi is vector<int>
        int numSets;
        vector<unordered_set<int> > kids;
    public:
        UnionFind(int N) :kids(N+1, unordered_set<int>()) {
            setSize.assign(N+1, 1); numSets = N; rank.assign(N+1, 0); sumSet.assign(N+1,0);
            p.assign(N+1, 0); 
            for (int i = 0; i <=N; i++) {
                p[i] = sumSet[i] = i;
            }
        }

        int findSet(int i) {
            if(p[i] == i) {
                return i;
            } else {
                int op = p[i];
                p[i] = findSet(p[i]);
                kids[op].erase(i);
                kids[p[i]].insert(i);
            }
        }
        bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
        void unionSet(int i, int j) {
            if (!isSameSet(i, j)) { numSets--;
                int x = findSet(i), y = findSet(j);
                // rank is used to keep the tree short
                if (rank[x] > rank[y]) 
                { 
                    p[y] = x; setSize[x] += setSize[y]; sumSet[x] += sumSet[y];
                    kids[x].insert(y);
                }
                else                   
                { p[x] = y; setSize[y] += setSize[x]; sumSet[y] += sumSet[x];
                    kids[y].insert(x);
                    if (rank[x] == rank[y]) rank[y]++; } } }
        int numDisjointSets() { return numSets; }
        int sizeOfSet(int i) { return setSize[findSet(i)]; }
        int sumOfSet(int i) { return sumSet[findSet(i)]; }
        void moveSet(int i, int j) { 
            if(!isSameSet(i, j)){
                if(p[i] == i) {
                    if(!kids[i].empty()) {
                        int k = 0, new_p;
                        for(auto it = kids[i].begin(); it != kids[i].end(); it++) {
                            if(k++ == 0) new_p = *it;
                            else {
                                p[*it] = new_p;
                                kids[new_p].insert(*it);
                            }
                        }

                        p[new_p] = new_p;
                    }
                } else {
                    
                }
                setSize[findSet(i)]--, setSize[findSet(j)]++;
                sumSet[findSet(i)] -= i, sumSet[findSet(j)] += i;
                p[i] = findSet(j);
            }
        } 
};


int main()
{
    int n, m, i, q, a, b;
    while(scanf("%d %d\n", &n, &m) != EOF) {
        UnionFind unf(n);
        
        REP(i, m) {
            cin >> q;

            switch(q) {
                case 1: 
                    cin >> a >> b;
                    unf.unionSet(a, b);
                    break;
                case 2:
                    cin >> a >> b;
                    unf.moveSet(a, b);
                    break;
                case 3:
                    cin >> a;
                    cout << unf.sizeOfSet(a) << " " << unf.sumOfSet(a) << endl;
            }
        }
    }
}
