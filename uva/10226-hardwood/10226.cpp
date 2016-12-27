#include <map>
#include <iostream>
#include <string>
using namespace std;

int main() 
{
    //read input 
    string tree;
    map<string, int> treeMap;
    int total=0;
    int K;
    scanf("%d\n\n", &K);

    while(K--) {
        while(!getline(cin, tree).eof()) {
            if(treeMap.find(tree) != treeMap.end()) {
                treeMap[tree] = ++(treeMap.find(tree)->second);
            } else {
                treeMap[tree] = 1;
            }
            total++;
        }

        for(map<string,int>::iterator itr = treeMap.begin(); itr != treeMap.end(); itr++) {
            printf("%s %.4f\n", itr->first.c_str(), itr->second*100.0/total);
        }

        printf("\n");
        treeMap.clear();
    }
}
