#include <algorithm>
#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
   int n, k, C;

   scanf("%d", &C);

   for(int i = 0; i<C; ++i) {
        scanf("%d %d", &n, &k);
        printf("%d\n", k^(k>>1));
   }

}
