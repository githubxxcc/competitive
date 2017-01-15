#include "segtree.cpp"
#include <iostream>
#include <vector>

using namespace std;

#include <string.h>
int N, x;
vector<int> v;
char action[3];
int caseNo=0;

int main()
{
    while(scanf("%d", &N), N){
        v.push_back(0); // 1-indexed
        while(N--){
        cin >> x;
        v.push_back(x);
        }
        //construct the tree
        SegmentTree_Sum st(v);

        printf("Case %d:\n", ++caseNo);
        while(true){
            scanf("%s", action);
        
            if(!strcmp(action, "END")) break;
            else if(!strcmp(action, "S")){
                int index, value;
                cin >> index >> value;
                st.update_point(index, value);
            } else if(!strcmp(action, "M")){
                int a, b;
                cin >> a >> b;
                printf("%d\n", st.rmq(a,b));
            }
        }
    }

}
