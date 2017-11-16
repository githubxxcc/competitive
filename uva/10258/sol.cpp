#include <string>
#include <iostream>
#include <sstream>
#include <unordered_map>
#include <vector>
#include <array>
#include <algorithm>
#include <utility>

using namespace std;



bool compFn(array<int, 3> &a, array<int, 3> &b) {
    if(a[1] == b[1] && a[2] == b[2]) return a[0] < b[0];

    if(a[1] == b[1]) return a[2] < b[2];
    else return a[1] > b[1];
}

int main()
{
    unordered_map<int, pair<int, int> > records;
    vector<array<int, 3> > vec;

    int solved[101][10] = {};
    int c, p, t, TC;
    char L;
    string line;

    scanf("%d\n\n", &TC);


    while(TC--){
        
        while(getline(cin, line) && !line.empty()){
            istringstream iss(line);

            iss >> c >> p >> t >> L;

            if(!records.count(c)){
                records[c] = make_pair(0,0);
            }

            if(solved[c][p] == -1)
                continue;

            switch(L){
                case 'C':
                    records[c].first++;
                    records[c].second += t;
                    records[c].second += 20 * solved[c][p];
                    solved[c][p] = -1;
                    break;
                case 'I': 
                    solved[c][p]++;
                    break;
                default:
                    break;
            }
        }

        for(auto itr = records.begin(); itr != records.end(); itr++){
            vec.push_back((array<int, 3>){itr->first, itr->second.first, itr->second.second});
        }

        sort(vec.begin(), vec.end(),compFn); 

        for(auto entry : vec) {
            printf("%d %d %d\n", entry[0], entry[1], entry[2]);
        }

        if(TC != 0) cout << endl;
        vec.clear();
        records.clear();

        for(int i = 0; i<=100; i++){
            for(int j = 0;j<10; j++)
                solved[i][j] = 0;
        }

    }


}
