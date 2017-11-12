
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int x, mid,mid_l, mid_r;
    bool odd = true;
    vector<int> vi;
    
    while(scanf("%d", &x) != EOF) {
        vi.push_back(x);

        auto mid_itr = vi.begin()+vi.size()/2;

        if(odd) {
            nth_element(vi.begin(), mid_itr, vi.end());
            mid = *mid_itr;
        } else {
            nth_element(vi.begin(), mid_itr, vi.end());
            mid_r = *mid_itr;
            nth_element(vi.begin(), mid_itr-1, vi.end());
            mid_l = *(mid_itr-1);
            mid = mid_l + (mid_r-mid_l)/2;
        }

        odd = !odd;
        cout << mid << endl;
    }
}
