#include <stdio.h>
#include <string.h>
#include <math.h>


int main() 
{
    //int digit;
    //char regex[20];
    //char buf[4]; 

    //scanf("%d", &digit);
    //snprintf(buf, sizeof(buf), "%d", digit);

    //strcpy(regex, "%."); 
    //strcat(regex, buf);
    //strcat(regex, "f\n");
    //printf(regex, M_PI);
   
    double pi = 2*acos(0.0);
    int width;
    scanf("%d", &width);

    printf("%.*f", width,pi);
}
