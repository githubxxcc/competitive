#include <cmath>
#include <iostream>
/*Algorithm:
 *
 * -  use d, k to locate the position in the {an} sequence. 
 * -  use the line1 to calculate the expression of the {an} sequence. 
 *
 */

int c[21], k, d, TC, i,ii,pos;
unsigned long int result;

int main()
{
    scanf("%d\n", &TC);

    while(TC--){
        //read the line
        //calcualte the output 
        //print the output
        //

        scanf("%d",&i);
        for(ii = 0; ii <=i; ii++){
            scanf("%d",&c[ii]);
        }

        scanf("%d\n%d", &d, &k);
        //find position
        pos = 0;
        while(k>0){
            k -= d*(++pos);
        }

        

        //calculate result
        result = 0;
        for(ii = 0; ii<= i; ii++){
            result+=pow(pos*1.0,ii*1.0)*c[ii];
        }

        printf("%lu\n", result);


    }

}
