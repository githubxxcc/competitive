#include <stdlib.h>
#include <iostream>
#include <vector>

using namespace std;

int  n, cnt, cur, prevv;
typedef vector<int> vi;


int main()
{
    while(scanf("%d", &n) != EOF){
        vi vec(n, 0);
        cnt = 0;
        
        scanf("%d", &prevv);
        for(int i = 1; i<n; i++){
            scanf("%d", &cur);
            if(abs(cur-prevv) < n && vec[abs(cur-prevv)] == 0) {
                vec[abs(cur-prevv)] = 1;
                cnt++;
            }

            prevv = cur;
        }

        if(cnt == n-1)
            cout << "Jolly" << endl;
        else 
            cout << "Not jolly" << endl;
    }

}
