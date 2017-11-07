#include <iostream>
#include <map>
#include <string>


using namespace std;

int TC, total= 0, c = 1;
map<string, int> tmap;
string name;

int main()
{
    scanf("%d\n\n",&TC);

    while(TC--){
        tmap.clear();
        total = 0;

        if(c++ > 1) printf("\n"); 

        while(getline(cin, name) && !name.empty()){
            total++;
            tmap[name] = tmap.count(name) ? tmap[name]+1 : 1;
        }

        for(auto itr = tmap.begin(); itr != tmap.end(); itr++) {
            printf("%s %.4f\n", itr->first.c_str(), itr->second * 100.0/total);
        }
    }
}
