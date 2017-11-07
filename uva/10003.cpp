#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

int n, l, left, right, ll, j;
int A[55];
int mem[55][55];


int min_cut(int x, int y) {
    if(x +1 == y) return 0;
    if(mem[x][y] != -1) return mem[x][y];

    int minV = 999999999;
    for(int k =x+1 ; k < y; k++){
        minV = min(minV, min_cut(x, k)+ min_cut(k, y) + (A[y]-A[x]));
    } 
    return mem[x][y] = minV;

};


int main(){
    while(scanf("%d",&n), n != 0){
        memset(mem, -1, sizeof mem);
        scanf("%d", &l);
        for(ll = 1 ; ll <= l; ll++){
        scanf("%d", &A[ll]);
        }
        A[0] = 0;
        A[l+1] = n;

        printf("The minimum cutting is %d.\n", min_cut(0,l+1));
    }
}

