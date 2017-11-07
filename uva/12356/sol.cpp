#include <vector>
#include <iostream>

using namespace std;

int main()
{
    int S, B, i, j, L, R;

    while(scanf("%d %d\n", &S, &B), (S || B)){
        vector<int> arr(S+1, 1);

        while(B--){
            scanf("%d %d", &L, &R);
            
            for(int k = L; k<=R; k++)
                arr[k] = 0;

            for(i = L; i>0; i--){
                if(arr[i]) break;
            }

            for(j = R; j<=S; j++){
                if(arr[j]) break;
            }

            
            if(i == 0) cout << "*";
            else cout << i;

            cout << " ";

            if(j == S+1) cout << "*";
            else cout << j;

            cout << endl;
        }

        cout << "-" << endl;
    }
}
