#include <iostream> 
#include <vector>

using namespace std;



int N, n;
void
printSquare(vector<vector<char>> &square)
{
    int _size = square.size();

    for(int i = 0; i<_size; i++){
        for(int j = 0; j<_size; j++)
            cout << square[i][j];

        cout << endl;
    }

    cout << endl;

}

bool
match(vector<vector<char>> &S, vector<vector<char>> &s, int i, int j)
{
    for(int m = 0; m < n ; m++){
        for(int k = 0; k < n; k++){
            if(S[i+m][j+k] != s[m][k])
                return false;
        }
    }
    
    return true;
}


char
rotate(int i, int j, vector<vector<char>> &copy)
{
    return copy[n-1-j][i];
}

void
rotate(vector<vector<char>> &square)
{
   vector<vector<char>> copy = square; 
   
   for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            square[i][j] = rotate(i, j, copy);
        }
   }

}

void readSquare(vector<vector<char>> &square, int _size)
{

    for(int i = 0 ; i<_size; i++){
        vector<char> row(_size);
        for(int j = 0; j<_size; j++) {
            cin >> row[j];
        }
        
        square.push_back(row);
    }
}

int countSquare(vector<vector<char> > &S, vector<vector<char>> &s)
{
    int cnt = 0;
    for(int i = 0; i<=(N-n); i++){
        for(int j = 0; j<=(N-n); j++){
            cnt += match(S, s, i, j) ? 1 : 0; 
        }
    }

    return cnt;
}


int main()
{
    while(scanf("%d %d", &N, &n), (N || n)) {
        vector<vector<char>> S;
        vector<vector<char>> s;

        readSquare(S, N);
        readSquare(s, n);

        
        cout <<  countSquare(S, s) << " ";
        rotate(s);
        cout <<  countSquare(S, s) << " ";
        rotate(s);
        cout <<  countSquare(S, s) << " ";
        rotate(s);
        cout <<  countSquare(S, s) << endl;

        S.clear();
        s.clear();
    }
}



