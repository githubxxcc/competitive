/*
 * =====================================================================================
 *       Filename:  _ds.cpp
 *
 *    Description:  Union Find
 *
 *        Version:  1.0
 *        Created:  12/12/17 08:57:34
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

typedef vi vector<int>

class ufd {
private: 
    vi rank, p; 
    int _size;
public:
        unf(int N) :_size(N) {
            rank.assign(N, 0), p.assign(N, 0);
            for(int i = 0; i<N; i++) 
               p[i] = i; 
        }

        int findSet(int j) {
            return p[j] == j ? j : (p[j] = findSet(p[j])); /*  Path compression  */
        }

        bool isSameSet(int i, j) {
            return findSet(i) == findSet(j);
        }

        void unionSet(int i, int j) {
            int pi, pj = findSet(i), findSet(j);
            if(pi != pj) {
                if(rank[pi] < rank[pj]) p[pi] = pj;
                else if(rank[pi] > rank[pj]) p[pj] = pi;
                else { p[pi] = pj; rank[pj]++;}
            }
        }

        int numDisjoint() {
            return _size;
        }
};
