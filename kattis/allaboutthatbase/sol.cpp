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

int d8[9] = {-1, 0, 1, 0, -1, 1, 1, -1, -1};
int d4[5] = {-1, 0, 1, 0 , -1};
using namespace std;


int64 
inline C2N(int base, char c) 
{
    int64 i;
    if(base == 1) {
        if(c != '1') return -1;
        else return 1;
    }

    if( c >= '0' && c <= '9') i = c - '0';
    else if ( c >= 'a' && c <= 'z') i = c-'a'+ 10;
    else return -1;

    if(i >= base) return -1;
    else return i;
}

char
inline N2B(int base) 
{
    if(base < 10) return '0' + base;
    else if(base == 36) return '0';

    return base - 10 + 'a';
}

int64
valid(int base, char * s)
{
    int64 num =0, max = (1LL << 32) -1;
    for(int ppow = 0, i = strlen(s)-1; i>= 0; i--, ppow++) {
        char c = s[i];
        int64 x = C2N(base, c);
        if(x < 0)
            return 0;

        num += x * pow(base, ppow); 
        if(num >= max) 
            return 0;
    }

    return num;
}

bool
expression(int64 a, int64 b, int64 c, char ops) 
{
    switch(ops) {
        case '+':
            return a + b == c;
        case '*':
            return a * b == c;
        case '/':
            return b * c == a;
        case '-':
            return a - b == c;
        default:
            cout << "error: " << ops << endl;
    }
    return false;
}



int main() {

    int TC;
    int64 n1, n2, n3;
    bool isvalid;
    char op1[100], op2[100], ans[100], ops;

    scanf("%d\n", &TC);

    while(TC--) {
        scanf("%s %c %s = %s\n", op1, &ops, op2, ans);    
        isvalid = false;
        for(int base = 1; base <= 36; base++) {
            n1 = valid(base, op1), n2 = valid(base, op2) , n3 = valid(base, ans);

            if(n1 && n2 && n3 && expression(n1, n2, n3, ops)) {
                cout << N2B(base), isvalid = true;
            }
        }
        if(!isvalid) cout << "invalid";
        cout << endl;
    }
}
