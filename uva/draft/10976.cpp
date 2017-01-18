/* ALgorithm:
 * get the k 
 * from k to some value generate q (larger than k)
 * output if the check is good 
 */


#include <iostream>
#include <utility>
#include <vector>

using namespace std;
int counter, k, q, p ;
vector<pair<int,int> > result;
int main()
{
    while(scanf("%d\n", &k) >0){
        counter = 0;
        for(p= k+1;p<= 2*k; p++){
            if(q=(p*k)%(p-k), q==0){
                counter++;
                result.push_back(make_pair((p*k/(p-k)),p));
            }
        }
        
        printf("%d\n", counter);

        for(int j = 0; j<result.size(); j++){
            printf("1/%d = 1/%d + 1/%d\n", k, result[j].first, result[j].second);
        }
        result.clear();
    }

}
