#include <algorithm>
#include <string>
#include <iostream>


using namespace std;

string line;

int main()
{
    while(getline(cin, line), line.compare(string("#"))){
        if(next_permutation(line.begin(), line.end())){
            cout << line << endl;
        }
        else
            cout << "No Successor"<<endl;
    }
}
