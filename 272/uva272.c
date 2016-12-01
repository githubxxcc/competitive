#include <stdio.h>

int main() 
{
    int  inQuote;
    inQuote = 0;

    char k, q;
    while(scanf("%c",&k) != EOF)
    {
        if( (int) k ==34 ) {
            if(inQuote) {
                printf("''");
                inQuote = 0;
            } else {
                printf("``");
                inQuote = 1;
            }
        } else {
            printf("%c",k);
        }
    }
}
