#include <iostream>;
#include <string>;
#include <vector>;
using namespace std;

int n, l, left, right;
int x[1000];
int mem[1000][1000];
vector<int> anws;
int min_cut(left , right, cuts, cutLeft, cutRight) {
    if(left +1 == right) return 0;
    if(mem[left][right] != -1) return mem[left][right];

    for(int k = 0; k < cuts.length; k++){
        anws.push_back(min_cut(left, k, cuts)+min_cut(k, right, cuts) + cuts[right]-cuts[left]);
    }
    
    min = min_element(anws);
    mem[left][right] = min;

    return min;
}


int main(){
    while(scanf('%d',&n), n != 0){
        for(int i = 0; i < 1000; i++){
            for(int j = 0; j< 1000; j++){
                mem[i][j] = -1;
            }
        }
        scanf('%d', &l);
        ll = l
        while(ll--){
           scanf('%d', x[ll-1]);
        }

        printf("The minimum cutting is %d\n", min_cut(0,l, x));
    }
}

