/* Algor:
 * - input the arr 
 * - construct a sum arr of each combination of 2 in O(n^2)
 * - sort the sum arr 
 * - binary search the query 
 */

#include <vector>
#include <algorithm>
#include <cstdio>
#include <cmath>

using namespace std;

int TC, n, d, i , j, arr[1000], sum_arr[1000000], output,x, m;

int binarySearch(vector<int>&, int);
int main()
{
    TC = 0;
    while(scanf("%d\n", &n), n>0){
        printf("Case %d:\n", ++TC);

        for(i =0; i<n; i++) scanf("%d\n", &arr[i]);

        for(i = 0; i<n; i++){
            for(j = i+1; j<n; j++){
                sum_arr[x++] = arr[i]+ arr[j];
            }
        }

        vector<int> vec(sum_arr, sum_arr+x);
        sort(vec.begin(), vec.end());

        scanf("%d\n", &d);
        while(d--){
            scanf("%d\n", &m);
            output = binarySearch(vec, m);
            printf("Closest sum to %d is %d.\n", m, output);
        }

        x = 0;
    }
}

int binarySearch(vector<int> &vec, int x){
    
    int end = vec.size()-1;
    int begin = 0;
    int mid = (begin+end)/2;
    if(x <= vec[begin]) return vec[begin];
    if(x >= vec[end]) return vec[end];

    while(begin<mid){
        if(vec[mid]>x) end = mid;
        else if(vec[mid] <x) begin = mid;
        else return vec[mid];

        mid = (begin+end)/2;
    }
    
    return (abs(vec[end]- x*1.0) > abs(vec[begin]-x*1.0)) ? vec[begin] : vec[end];

}
