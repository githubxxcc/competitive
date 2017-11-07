#include <vector>
#include <iostream>

using namespace std;

int main()
{
    int S, B, i, j, L, R;
    int left[100001], right[100001];

    while(scanf("%d %d\n", &S, &B), (S || B)){

        for(int i = 1; i<= S; i++){
            left[i] = i-1;
            right[i] = i+1;
        }

        while(B--){
            scanf("%d %d", &L, &R);
            
            i = left[L];
            j = right[R];

            if(i == 0) cout << "*";
            else cout << i;

            cout << " ";

            if(j == S+1) cout << "*";
            else cout << j;

            cout << endl;

            right[i] = j;
            left[j] = i;
        }

        cout << "-" << endl;
    }
}
