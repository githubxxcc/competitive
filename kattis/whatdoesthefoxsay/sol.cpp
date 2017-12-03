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
#include <sstream>
#include <vector>
#include <array>

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


int TC, i, ssize;
vector<string> v;
unordered_map<string, vector<int> > mmap;
string line, s, animal;
bool first;

int main() 
{
    scanf("%d\n", &TC);
    while(TC--) {
        getline(cin, line);
        istringstream iss(line);
        i = 0;
        while(iss >> s){
            v.push_back(s);

            if(!mmap.count(s)) {
                vector<int> vv;
                mmap[s] = vv;
            }
            mmap[s].push_back(i++);
        }

        ssize = i; 

        while(getline(cin, line), line.back() != '?') {
            animal = line.substr(line.find("goes") + 5);
            for(auto idx : mmap[animal]) {
                v[idx] = " ";
            }
        }

        first = true;
        for(i = 0; i<ssize; i++) {
            if(v[i] != " ") { 
                if(!first) cout << " ";
                cout << v[i], first = false;
            }
        }

        cout << endl;
        mmap.clear(), v.clear();
    }
}
