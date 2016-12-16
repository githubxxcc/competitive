#include <sstream>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
#include <cctype>

bool IsWordPalindrome(string);

int main()
{
    string input;
    while(1) {
        cout << "Enter a word: " << endl;
        getline(cin, input);
        if (IsWordPalindrome(input)) cout << "Yes!" <<endl;
        else cout << "No! " << endl;
    }
}

bool IsNotAlphaNumOrSpace(char k) 
{
    return !isalnum(k) &&  !isspace(k);
}

bool IsWordPalindrome(string input)
{
   //clean punc 
    input.erase(remove_if(input.begin(), input.end(), IsNotAlphaNumOrSpace), input.end());
    
    //cap
    transform(input.begin(), input.end(),input.begin(), ::toupper);

    //tokenize the string 
    stringstream tokenizer(input);
    vector<string> wordlist;
    wordlist.insert(wordlist.begin(), istream_iterator<string>(tokenizer), istream_iterator<string>());

    //compare the wordlist 
    return equal(wordlist.begin(), wordlist.begin() + wordlist.size()/2, wordlist.rbegin());
}
