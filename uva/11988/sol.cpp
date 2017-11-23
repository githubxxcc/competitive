#include <iostream>
#include <sstream>
#include <list>
#include <string>

using namespace std;

string line, output;
char c;

int main()
{
    while(getline(cin, line)) {
        istringstream iss(line);
        list<char> _list;
        auto it = _list.end();

        while(iss.get(c)) {
            switch(c) {
                case '[':
                    it = _list.begin();
                    break;
                case ']':
                    it = _list.end();
                    break;
                default: 
                    _list.insert(it, c);
            }
        } 

        string output (_list.begin(), _list.end());
        cout << output << endl;
        _list.clear();
    }
}
