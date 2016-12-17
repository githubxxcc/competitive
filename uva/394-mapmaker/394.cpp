#include <iostream>
#include <vector>
#include <map>
#include <string>
#include "prettyprint.hpp"
using namespace std;

/*
 * Algorithm:
 * - Read input N arrays
 *   For each array store a map<char, pair<int, int>> as meta_map
 *   For each arry stores a map <char, vector<int>> as data_map 
 * - for each input R lines 
 *   output the prefix 
 *   calculate the address based on the prefix
 */


int main() 
{
    int N, R;
    scanf("%d %d", &N, &R);
    map<string, vector<int> > meta_map;
    map<string, vector<int> > data_map;
    map<string, vector<int> > dim_map;
    string name;
    int a, b, c;
    while(N--) {
        cin >> name;
        cin >> a >> b >> c;
        vector<int> meta_vector;
        meta_vector.push_back(a);
        meta_vector.push_back(b);
        meta_vector.push_back(c);
        
        meta_map[name] = meta_vector;

        vector<int> dim_vector;
        while(meta_vector[2]--) {
            int l, u;
            cin >> l >> u;

            dim_vector.push_back(l);
            dim_vector.push_back(u);
        }

        dim_map[name] = dim_vector;
    }

    while(R--) {
        //handle prefix
        cin >> name;
        vector<int> r = meta_map[name];

        printf("%s [", name.c_str());

        int i = r[2]-1;
        while(i--) {
            scanf("%d", &N);
            printf("%d, ", N);
            data_map[name].push_back(N);
        }

        scanf("%d", &N);
        printf("%d]", N);
       
        //calculate physical address

        int b = r[0]; 
        int D = r[2];
        int cd = D;
        int pa = 0;
        vector<int> cd_vec;
        vector<int> dim_vec = dim_map[name];
        vector<int> data_vec = data_map[name];
        do {
            pa += cd * data_vec[D];
            cd_vec.insert(cd_vec.begin(), cd);
            //update the cd
            cd = cd * (dim_vec[2*(D-1)+1]- dim_vec[2*(D-1)]+1);
        } while(--D);

        //add C0
        int c0 = b;
        int d = r[2];

        while(d--) {
            c0 -= cd_vec[d] * dim_vec[2*(d)]; 
        }

        pa += c0;

        printf("%d \n", pa);
        
    }

   cout << dim_map << endl; 
}
