#include <iostream>
using namespace std;

/* Algorithm:
 *  Since test cases from 2->79, and iterating all possible cases costs less than 10^5, and iterativng through all the digits will cost 10 per case. 
 *  So using iterative complete search is possible. 
 */

/* Learning points:
 * 1. Use of bits manipulation to count the number of digits used. 
 * 2. Use of 0.5d to format the integer printf.
 */

int N;

int main()
{
    while(cin>>N, N){

            bool has = false;
        for(int fghij = 1234; fghij < 98765/N; fghij++){
            int temp,used = (fghij<10000);
            int abcde = fghij * N;
            temp = abcde; while(temp) {used |= 1 << (temp%10); temp/=10;}
            temp = fghij; while(temp) {used |= 1 << (temp%10); temp/=10;}

            if(used == (1<<10)-1){
                printf("%0.5d / %0.5d = %d\n", abcde, fghij, N);
                has = true;
            }
        }

        if(!has) printf("There are no solutions for %d.\n", N);
    }
}
