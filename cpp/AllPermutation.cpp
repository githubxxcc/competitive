/* Problem Statement:
 * Here is another mathematical problem, where the trick is as much to discover the algorithm as it is to write the code: write a program to display all possible permutations of a given input string--if the string contains duplicate characters, you may have multiple repeated results.
 */

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
void printChar(char k) 
{
    printf("%c ", k);
}


int main() 
{
    string k;

    cin >> k;

    vector<char> charVec(k.c_str(), k.c_str() + k.size());
    
    sort(charVec.begin(), charVec.end());

    do {
        for_each(charVec.begin(), charVec.end(), printChar);
        printf("\n");
    } while( next_permutation(charVec.begin(), charVec.end()) );

    
}

