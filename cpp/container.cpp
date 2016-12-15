#include <iomanip>
#include <sstream>
#include <iostream>
#include <fstream>
#include <map>
#include <string>

using namespace std;
void OpenUserFile(ifstream& fileStream);

string GetFileContents(ifstream& file);

map<string, size_t> GenerateKeywordReport(string contents);

int main() 
{
    ifstream input;
    OpenUserFile(input);

    string contents = GetFileContents(input);
    map<string, size_t> reports = GenerateKeywordReport(contents);

    for(map<string, size_t>::iterator itr = reports.begin(); itr != reports.end(); ++itr) {
        cout << "Keyword " << itr->first <<left<< setw(5) << " Occured : "  << itr->second << " times" << endl;
    }
}


void OpenUserFile(ifstream& input) 
{
    string fileName;
   while(true){
    cout << "Enter a file name: " ;
    getline(cin, fileName);

    input.open(fileName.c_str());

    if(input.is_open()) {
        return;
    }
   }
    cout << "Error in opening file : " << fileName << endl;
    input.clear();
   
}

string GetFileContents(ifstream& file) 
{
    string result;
    string line;
    while(getline(file, line)) {
        result += line+ "\n";
    }

    return result;
}

void PrepocessString(string& content) 
{
    for(size_t k=0; k<content.size(); ++k) {
        if(ispunct(content[k]) && content[k] != '_') {
            content[k] = ' ';
        }
    }
}

map<string, size_t> GenerateKeywordReport(string content) 
{
    map<string, size_t> my_report;
    PrepocessString(content);

    string keyword;
    stringstream ss;
    ss.str(content);

    while(getline(ss, keyword, ' ')){
        my_report[keyword] ++;
    }
    
    return my_report;
}
