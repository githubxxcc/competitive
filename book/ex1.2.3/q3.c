#include <time.h>
#include <stdio.h>

int main() 
{
    char line[128];
    struct tm time;
    time_t t;
   
    scanf("%[^\n]", line);
    printf("%s", line);
    if(strptime(line, "%d %b %Y", &time) == NULL) {
        printf("error\n");
    }
    printf("%d\n%d\n", time.tm_mday, time.tm_year);
    printf("%d\n%d\n", time.tm_wday, time.tm_yday);
    
}
