/* Algorithm:
 * - store lower and higher map for each car makers
 * - sort the lower map
 * - iterate through the map. 
 */

#include <map>
#include <string>
#include <iostream>

using namespace std;


int TC, d, l, h, counter, q, Q;
string M, name;
multimap<int, string> low;
map<string, int> high;
multimap<int,string>::iterator up, it;

int main()
{
    scanf("%d\n", &TC);
    counter = 0;
    while(TC--){
        scanf("%d\n", &d);
        while(d--){
            cin >> M;
            scanf("%d %d\n", &l, &h);
            low.insert(make_pair(l,M));
            high[M] = h;
        }

        scanf("%d\n", &q);

        while(q--){
            scanf("%d\n", &Q);
             up = low.upper_bound(Q);
            for(it = low.begin(); it!= up; it++){
                name = it->second;
                if(Q <= high[name]){
                    counter++;
                    if(counter>=2) break;
                }
            }
            if(counter!=1) printf("UNDETERMINED\n");
            else printf("%s\n",name.c_str());
            counter = 0;
        }
        low.clear();
        high.clear();
        printf("\n");
    }

}
