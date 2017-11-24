#include <iostream>
#include <stack>
#include <vector>

using namespace std;
int i, N, cur, _next, idx;
vector<int> v;
int main()
{
    stack<int> s;
_next_case:
    while(scanf("%d", &N), N) {

repeat: 
        for(i = 1 ; i<= N; i++) {
            cin >> cur;
            if(cur == 0) {
                cout << endl;
                goto _next_case;
            }

            v.push_back(cur);
        }
        idx =0;
        for(i = 1; i<=N; i++) {
            s.push(i);

            while(!s.empty() && s.top() == v[idx]) {
                s.pop();
                idx++;
            }
        }

        if(idx == N)
            cout << "Yes" << endl;
        else 
            cout << "No" << endl;

        while(!s.empty())
            s.pop();

        v.clear();

        goto repeat;
    }
}
