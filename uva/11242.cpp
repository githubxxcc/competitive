/* Algorithm
 *  - get the ratio of the each pair 
 *  - sort and get the largest and smallest 
 */
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int f, r, k ,j, front[10], back[10], counter;
double ratiO[3000], maxvalue;

int main()
{
    while(scanf("%d", &f), f!=0){
        counter = 0;
        maxvalue = 0;
        scanf("%d", &r);
        for(k = 0; k<f; k++) scanf("%d", &front[k]);
        for(k = 0; k<r; k++) scanf("%d", &back[k]);

        for(k = 0; k <f; k++){
            for(j = 0; j<r; j++){
                ratiO[counter++] = (double)back[j]/(double)front[k];
            }
        }

        vector<double> myvec(ratiO, ratiO+counter);
        sort(myvec.begin(), myvec.end());

        for(k = 1; k<myvec.size(); k++){
            maxvalue = (maxvalue > myvec[k]/myvec[k-1])? maxvalue : myvec[k]/myvec[k-1];
        }
        f = r =0;
        printf("%.2f\n", maxvalue);
    }
}
