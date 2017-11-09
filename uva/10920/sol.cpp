#include <iostream>



using namespace std;

int sz, p, cur_y, cur_x, cur, d, dx, dy, i, j;
bool up;

int main()
{
    while(scanf("%d %d", &sz, &p), (sz || p))
    {
        cur_y = cur_x = (sz+1)/2;
        i = 1;
        d = 3;
        dx = 0; dy = 1;
        up = false;

        if(p >= sz * sz){
            cur_x = cur_y = sz;
            goto print;
        }

        while(i+d<= p)
        {
            cur_x += up ? dx++ : -1* dx++;
            cur_y += up ? dy++ : -1* dy++;
            i+=d;
            d+=2;
            up = !up;
        }

        

        j = p-i;
        if(j <= 0 || (cur_x == sz && cur_y == sz)) {}
        else if(j<=(d+1)/2){
            cur_x += up? -1 : 1;
            cur_y += up? j-1 : -1*(j-1);
        } else {
            cur_y += up? d/2 : -1*(d/2);
            cur_x += up? (j-1-(d+1)/2) : -1 * (j-1-(d+1)/2);
        }
print:
        printf("Line = %d, column = %d.\n", cur_x, cur_y);
    }
}

