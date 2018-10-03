
//includes


/*  Non compliable */

int tc;


bool 
can_place(int row, int col) 
{
    //Check if any col at row has a queen 
    for(int c = 0 ; c<col ; c++) {
        if(row[c] == row) {
            return false;
        }

        if(abs(row[c] - row) == abs(c - col)) {
            //On the same diagnal
            return false;
        }
    }

    return true;
}

void
backtrace(int col, int a, int b) 
{
    if(col > 8) return; /* we are done */

    if(col == 8 && row[b] == a)  {
        /* Last col to fill and found a match */
        print_board();
    } else if (col == 8) {
        return;
    }
    
    //Try to place a queen
    for(r = 0 ; r<8; r++) {
        if(can_place(r, col)) {
            row[c] = r;
            backtrace(c+1);
        }
    }
}

int main()
{
    cin >>tc;

    while(tc--) 
    {
        //Read input a, b as the coordinates
        cin >> a >> b;
        row.fill(0);
        
        backtrace(0, a, b);
    }
}
