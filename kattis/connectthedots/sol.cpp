
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
#define D_PSTL(msg, stl) cout << msg<< endl; for(auto x: stl) cout << x << " "; \
    cout << endl << endl;

int d8[9] = {-1, 0, 1, 0, -1, 1, 1, -1, -1};
int d4[5] = {-1, 0, 1, 0 , -1};
using namespace std;

typedef vector<int> vi;

char mtx[101][101];

void draw_h(int r, int c1, int c2)
{
    int s = c1 < c2 ? c1: c2;
    int e = c1 < c2 ? c2: c1;

    for(int i = s+1; i <e; i++) {
        if(mtx[r][i] == '.') {
           mtx[r][i] = '-'; 
        } else if(mtx[r][i] == '|') 
            mtx[r][i] = '+';
    }
}

void draw_v(int c, int c1, int c2)
{
    int s = c1 < c2 ? c1: c2;
    int e = c1 < c2 ? c2: c1;

    for(int i = s+1; i <e; i++) {
        if(mtx[i][c] == '.') {
           mtx[i][c] = '|'; 
        } else if(mtx[i][c] == '-') 
            mtx[i][c] = '+';
    }
}

int
idx(char c) {
    if(c >= '0' && c <= '9')
        return c - '0';
    else if(c >= 'a' && c <= 'z') {
        return c - 'a' + 10;
    }
    else 
        return c - 'A' + 36;
}

int main() {
    int size, max = -1, i, j, c, row[101], col[101], prev_r, prev_c, cur_r, cur_c, r = 0;
    char x;
    string line;

    while(true) {
        getline(cin, line);
        if(line.empty() || cin.eof()) {
            // reset 
            REP(i, max+1) {
                if(i == 0) {
                    prev_r = row[i], prev_c = col[i];
                } else {
                    cur_r = row[i], cur_c = col[i];
                  // printf("i : %d\n", i);
                  // printf("cur: %d %d\n", cur_r, cur_c);
                  // printf("prev: %d %d\n", prev_r, prev_c);
                    if(cur_r == prev_r) {
                        draw_h(cur_r, prev_c, cur_c);
                    } else 
                        draw_v(prev_c, prev_r, cur_r);

                    prev_r = cur_r, prev_c = cur_c;
                }
            }

            REP(i, r) {
                REP(j, size) {
                    printf("%c", mtx[i][j]); 
                }
                printf("\n");
            }
            printf("\n");

            r = size =  0;
            max = -1;

            if(cin.eof()) 
                break;
            
        } else {
            size = line.length();
            istringstream iss(line);

            REP(c, size) {
                iss >> x ;
                mtx[r][c] = x;

                if(x != '.') {
                    int id = idx(x);
                    row[id] = r, col[id] = c;
                    max = id <= max ? max : id;
                }
            }
            r++;
        }
    }
}
