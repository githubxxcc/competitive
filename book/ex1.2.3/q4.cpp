#include <vector>
#include <algorithm>
#include <iostream>


#define ALL(x) x.begin(), x.end()
#define UNIQUE(c) (c).resize(unique(ALL(c))-(c).begin())

int main()
{
    int n ;
    std::cin >> n;
    std::vector<int> v (n);
    for(int i = 0; i<n; i++) {
        std::cin >> v[i];
    }
    
    std::sort(ALL(v));
    UNIQUE(v);

    for(int j = 0; j<v.size() ; j++) { printf("%d\t", v[j]);}
    
}
