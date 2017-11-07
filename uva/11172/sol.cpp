#include <iostream> 

using namespace std;

int TC, a, b;

int main()
{
    scanf("%d", &TC);

    while(TC--){
        scanf("%d %d\n", &a, &b);

        if(a > b) cout << ">\n";
        else if(a == b) cout << "=\n";
        else cout << "<\n";
    }
}

