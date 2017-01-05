#include <iostream>
#include <cmath>

using namespace std;
/* Normal dianoal check version.
 *
 * Algorithm:
 * - Read the fixed row and col 
 * - From col 0 -> 7 
 *   - From row 0 -> 7 
 *      - Try place(r,c) 
 *         - if *finished -> output result -> return true
 *         - else check if can place
 *         - if can -> next col 
 *         - if cannot backtrack ->return or simply return 
 * 
 *
 * Learning point:
 *  cannot use an iterative for loop here. Use of (nested) for loops cannot solve backtrack problem because there is simply no way you can undo a loop. 
 */

int TC, fixedR, fixedC, row[8], solCounter;
void tryPlace(int);
bool canPlace(int, int);
int main()
{
    scanf("%d\n\n", &TC);

    while(TC--){
        cin >> fixedR >> fixedC;

        //normalize to 0 index
        fixedR--; fixedC--;

        //TODO:print solution header
        printf("SOLN       COLUMN\n");
        printf(" #      1 2 3 4 5 6 7 8\n\n");
        
        for(int i=0 ;i<8; i++){
            row[i] = -1;
        }
        solCounter = 0;
        tryPlace(0);

        if (TC)
            printf("\n");

    }
}

void tryPlace(int col){
    if( col >= 8 && row[fixedC] == fixedR){
        //TODO: print answer
        printf("%2d\t%d",++solCounter, row[0]+1);
        for(int j = 1; j<8; j++){
            printf(" %d", row[j]+1);
        }
        printf("\n");
        return;
    }
    for(int r =  0; r < 8; r++){
        if(canPlace(r, col)){
            row[col] = r;
            tryPlace(col+1);
            row[col] = -1;
        }
    }   
}

bool canPlace(int r, int c)
{
    for(int prev=0; prev < c; prev++){
        if(row[prev]==r || (abs(row[prev]-r) == abs(c-prev))){
            return false;
        }
    }

    return true;
}
