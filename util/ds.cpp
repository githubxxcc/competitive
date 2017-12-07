/*
 * =====================================================================================
 *
 *       Filename:  ds.cpp
 *
 *    Description:  Data Structures Defined
 *
 *        Version:  1.0
 *        Created:  12/06/17 21:21:27
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ricky (), 
 *   Organization:  
 *
 * =====================================================================================
 */

/*  For 2D points, Credit: meysamaghighi  */
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




/*  2D Points End */


