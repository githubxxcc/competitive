#include <bitset>
#include <iostream>

using namespace std;

bitset<1000001> bset;
unsigned int n,m,s,e,t,ss,ee, i;

#define MAX_SIZE 1000001

bool test_conflict(bitset<1000001>& bset, unsigned int s, unsigned int e)
{
    for(auto i = s; i<e; i++){
        if(bset.test(i))
            return true;

        bset.set(i);
    }
    return false;
}

int main()
{
    while(scanf("%u %u\n", &n, &m), (n || m)) {
    
        bset.reset();
        bool conflict = false;
        for(i = 0; i<n; i++) {
            scanf("%u %u\n", &s, &e);

            if(!conflict && test_conflict(bset, s, e))
                conflict = true;
        }

        for(i = 0; i<m; i++) {
            scanf("%u %u %u", &s, &e, &t);
            int dif = e -s;
            for(ss = s; ss < MAX_SIZE && !conflict ; ss += t){
                ee = min((unsigned int)MAX_SIZE-1, ss+dif);

                if(test_conflict(bset, ss, ee))
                    conflict = true;
            }
        }
        if(!conflict)
            cout << "NO CONFLICT" << endl;
        else 
            cout << "CONFLICT" << endl;
    }

}
