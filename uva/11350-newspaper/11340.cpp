/* Learning Points
 * 1. Use get(is, line) in a while loop to extract all the characters. 
 * 2. Use cin >> a >> b to get multiple outputs faster
 * 3. Looked up the sstream library. Some possible methods could be used:
 *      - is.good() / is.eof() to check error status
 *      - is.gcount() to get the last input size.
 *      - ignore() to discard charactors (empty lines)
 */

#include <map>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main() 
{
    int numT, numPaidChar, numLine;
    scanf("%d\n", &numT);
    map<char, int> paidMap;
    char ch;
    int cost;
    double totalCost;
    while(numT--) {
        scanf("%d\n", &numPaidChar);
        while(numPaidChar--) {
            scanf("%c %d\n",&ch, &cost);
            paidMap[ch] = cost;
        }

        scanf("%d\n", &numLine);

        string line;
        stringstream strstrm;
        
        while(numLine--) {
            getline(cin, line);
            strstrm << line;
        }
        while(strstrm.get(ch)) {
            if(paidMap.find(ch) != paidMap.end()) {
                totalCost += (paidMap.find(ch)->second)/100.0;
            }
        }
        
        printf("%.2f$\n", totalCost);
        paidMap.clear();
        totalCost = 0;
    }
}
