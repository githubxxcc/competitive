/* binary checking of each different char in the SS query string. 
 * compare it with the char in the S string with the same offset from the begining. 
 * adjust the begining.
 * binary search once in the end
 */

/* Not completed*/

int main()
{
   scanf("%s\n%d", S, &q);

   while(q--){
        k = scanf("%s\n", SS);
        intial = 0;
        
        curIndex = 0;
        prevChar = SS[0];
        found = true;
        
        x = binFind(SS[0]);
        if(

        for(i = 1; i<k && found; i++){
            
            if(SS[i] != prevChar){
                //update the prev char
                prevChar = SS[i];
                offset = i - curIndex;
                curIndex = i ;
    
                //check SS[i]'s position in S
                if(S[j+offset] < SS[i]) found = false;
                
                j = binFind(SS[i]);
            }
        }

        if(!found) printf("Not matched\n");
        else printf("Matched %d %d\n",0, j);

        
        
   }

}
