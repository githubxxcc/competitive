/* Write a program that takes an integer and displays the English name of that value.
 *
 * You should support both positive and negative numbers, in the range supported by a 32-bit integer (approximately -2 billion to 2 billion).
 *
 */

#include <string>
#include <iostream>
using namespace std;

//1. check sign 
//2. have an array map to 000
//3. have an array map to 11- 19 
//4. have an array map to 20, 30 - 90 
void Translate(int);
string TranslateThousand(int, string, int);
string  map_digit[] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

string map_below_twenty[]= {"ten", "eleven", "twelve", "thriteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nighting"};

string map_tens[] = { "", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety" };


int main() 
{
    cout << "Enter an postive or negative number: ";

    int number;
    cin >> number;

    Translate(number);
}

void Translate(int number) 
{
   bool  isNeg = false;
   
    if( number < 0) {
        isNeg = true;
        number *= -1;
    }
    string result = "";
    int triZeroCounter = 0;
    //non-negative number
    while( number % 1000 != 0) {
        printf("number is %d \n trizeroCounter is %d \n", number, triZeroCounter);
        
        result.insert(0,TranslateThousand(number%1000, result, triZeroCounter));
        number /= 1000;
        triZeroCounter++;
    }
    if(isNeg) result.insert(0, "negative ");
    cout << result << endl;
}

string map_zeros[] =  {"", "thousand ", "million ", "billion "};
string TranslateHundred(int, int, string);
string TranslateTen(int, string);

string TranslateThousand(int number, string result, int triZeroCounter) 
{
    result.insert(0, map_zeros[triZeroCounter]);

    result.insert(0, TranslateHundred(number/100, number%100, result));

    return result;
}

string TranslateHundred(int hundredDigit, int tensDigits, string result) 
{
    if(tensDigits) {
        result.insert(0, TranslateTen(tensDigits, result)+" ");
    }
    if(hundredDigit) {
        result.insert(0, map_digit[hundredDigit]+" hundred ");
    }


    return result;
}

string TranslateTen(int tensDigit, string result) 
{
    if(tensDigit < 20) {
        return map_below_twenty[tensDigit];
    }

    result.insert(0, map_digit[tensDigit%10]);
    result.insert(0, map_tens[tensDigit/10]);

    return result;
}
