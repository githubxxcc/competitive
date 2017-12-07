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


struct point { 
  double x, y; 
  point() {}
  point(double x, double y) : x(x), y(y) {}
  point(const point &p) : x(p.x), y(p.y) {}
  point operator + (const point &p) const { return point(x+p.x, y+p.y); }
  point operator - (const point &p) const { return point(x-p.x, y-p.y); }
  point operator * (double c) const { return point(x*c, y*c); }
  point operator / (double c) const { return point(x/c, y/c); }
  bool operator < (const point &p) const {
      if (x != p.x) return x < p.x;
      return y < p.y;
  }
};

double dot(point p, point q) { return p.x*q.x + p.y*q.y; } // proportional to cos(x)
double dist(point p, point q) { return sqrt(dot(p-q , p-q)); }
double cross(point p, point q) { return p.x*q.y - p.y*q.x; } // proportional to sin(x) - p to q counterclockwise


double
dis_lineseg_pt(struct point& p1, struct point& p2, struct point& x) 
{
    double ll = dist(p1, p2);
    if(ll == 0) return dist(p1, x);

    double t = max(0.0, min(1.0, dot(x-p1, p2-p1) / (ll*ll)));
    struct point proj = p1 + (p2-p1) * t;
    return dist(x, proj);
}

double
dist(int* pts, int psize, int* line, int lsize)
{
    double mmin = (double) INT_MAX;
    int lx1, lx2, ly1, ly2, px1,py1;
    for(int p = 0; p<psize; p++) {
        for(int l = 0; l<lsize; l++) {
            px1 = pts[2*p], py1 = pts[2*p+1];

            lx1 = line[2*l], ly1 = line[2*l+1];
            if(l == lsize-1) {
                lx2 = line[0], ly2 = line[1];
            } else {
                lx2 = line[2*(l+1)], ly2 = line[2*(l+1) +1];
            }

            struct point p1(px1, py1), p3(lx1, ly1), p4(lx2, ly2);

            mmin = min(mmin, (dis_lineseg_pt(p3, p4, p1)));
        }
    }
    return mmin;
}



int main ()
{
    int TC, IN, _IN, OUT, _OUT, i, x, y, pin[200] = {}, pout[200] = {};
    double ans;

    cin >> TC;
    while(TC--) {
        cin >> IN;
        _IN = IN;
        i = 0;
        while(_IN--) {
            cin >> x >> y;
            pin[i] = x;
            pin[i+1] = y;
            i += 2;
        }


        cin >> OUT;
        _OUT = OUT;
        i = 0;
        while(_OUT--) {
            cin >> x >> y;
            pout[i] = x, pout[i+1] = y;
            i+=2;
        }

        ans = min(dist(pin, IN, pout, OUT), dist(pout, OUT, pin, IN));
        cout << fixed << setprecision(8) <<  ans/2 << endl;
    }
}
