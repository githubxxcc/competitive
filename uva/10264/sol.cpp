
#include <iostream>
#include <vector>

using namespace std;

int T, w; 


void sum_weights(vector<int> &weights,vector<int> & sets, unsigned long idx, int _size)
{
    int sum, bit;
    for(sum=0, bit = 0; bit < _size; bit++) {
        sum+= sets[idx ^ (1UL << bit)];
    }
    weights[idx] = sum;

    return;
}

int pair_weights(vector<int> &weights, unsigned long idx, int _size) 
{
    int local = 0, bit;

    for(bit = 0; bit < _size; bit++) {
        local = max(local, weights[idx] + weights[idx ^ (1UL << bit)]);
    }

    return local;
}

int main()
{

    while(scanf("%d", &T) != EOF) {
        int _size = (1 << T );
        vector<int> sets(_size, 0);
       
        for(unsigned long i = 0; i<_size; i++){
            scanf("%d", &w);
            sets[i] = w;
        }

        int local = 0;
        vector<int> weights(_size, 0);
        for(unsigned long i = 0; i<_size; i++) {
            sum_weights(weights,sets, i, T);
        }

        for(unsigned long i=0; i<_size; i++) {
            local = max(local, pair_weights(weights, i, T));
        }

        cout << local << endl;
    }

}

