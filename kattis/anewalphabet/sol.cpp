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
#define RALL(x) x.rbegin(), x.rend()
using namespace std;



string line;

int main() {
   string alpha_map[26] = {
        "@",
        "8",
        "(",
        "|)",
        "3",
        "#",
        "6",
        "[-]",
        "|",
        "_|",
        "|<",
        "1",
        "[]\\/[]",
        "[]\\[]",
        "0",
        "|D",
        "(,)",
        "|Z",
        "$",
        "']['",
        "|_|",
        "\\/",
        "\\/\\/",
        "}{",
        "`/",
        "2"
};
    getline(cin , line);

    for(auto c : line) {
        if(c >= 'a' && c <= 'z') 
            cout << alpha_map[c-'a'];
        else if(c >= 'A' && c <= 'Z') 
            cout << alpha_map[c-'A'];
        else 
            cout << c;
    }
}
