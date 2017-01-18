/*Algorithm:
 * - read inputs -> store in the array 
 * - loop over from the first element, compare it with all the elements in front of it. 
 *  /
 */


#include <stdlib.h>
#include <stdio.h>
int TC, arr[1000], k, p , j, n, counter;

int main()
{
    scanf("%d\n", &TC);

    while(TC--){
        scanf("%d\n", &n);
        for(int j =0; j < n; j++){
            scanf("%d", &arr[j]);
        }

        for(int k = 1; k <n; k++){
            for(int p = 0; p <k; p++){
                if(arr[p] <= arr[k]) counter++;
            }
        }
        
        printf("%d\n", counter);
        counter = 0;
    }

}
