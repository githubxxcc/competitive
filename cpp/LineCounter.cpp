/* Problem Statement: 
 * Here's a simple help free challenge to get you started: write a program that takes a file as an argument and counts the total number of lines. Lines are defined as ending with a newline character. Program usage should be
 *
 * count filename.txt
 * and the output should be the line count.
 */

#include <fstream>
#include <stdlib.h>
#include <iostream>
using namespace std;

int main()
{
    /* open a file 
     * get the file descri
     * read line by line and couter 
     */

    string filename;
    cout << "Enter a file name"<<endl;
    cin >> filename;

    ifstream is;
    is.open(filename.c_str());
    string line;
    int count = 0;
    do {
        getline(is, line, '\n');
        cout << line<<endl;
    } while ( (is.rdstate() & ifstream::eofbit) == 0 && ++count);

    printf("line number: %d\n", count);

}
