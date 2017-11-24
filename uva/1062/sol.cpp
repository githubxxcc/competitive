#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <array>

using namespace std;

int i;
array<char, 26> chars;
vector<char> stacks, v;
string line;
char c;
bool share;


int main() {
    array<char, 26> empty = {};
    int tc = 0;
    while(getline(cin, line), line!="end") {
        chars = empty;
        tc++;

        istringstream iss(line);

        while(iss.get(c)) {
            v.push_back(c);
            chars[c-'A']++;
        }

        for(auto ctn: v) {
            sort(stacks.begin(), stacks.end());
            share = false;
            for(i = 0; i< stacks.size(); i++) {
                //can share stack
                if(stacks[i] == ctn 
                        || stacks[i] > ctn ) {
                    chars[ctn-'A']--;
                    stacks[i] = ctn;
                    share = true;
                    break;
                }
            }

            if(share)
                continue;

            //cannot share
            stacks.push_back(ctn);
            chars[ctn-'A']--;
        }

        cout << "Case " << tc << ": "<< stacks.size() << endl;
        v.clear();
        stacks.clear();

    }
}
