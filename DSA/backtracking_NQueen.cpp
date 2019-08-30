bool isSafe(vector<string> comb, int row, int col, int A)
{
    for(int i=0;i<col;i++)
    {
        if(comb[row][i] == 'Q') return false ;
    }
    
    for(int i=row,j = col ; i>=0 && j>=0 ; i-- ,j--)
    {
        if(comb[i][j] == 'Q') return false ; 
    }
    
    for(int i=row, j= col ; i<A && j>=0 ; i++, j--)
    {
        if(comb[i][j] == 'Q') return false ;
    }
    
    return true ;

}


void solveNQ(vector<vector<string>>&res, vector<string>&comb, int col, int A)
{
    if(col >=A){ res.push_back(comb) ; return ; }
    for(int i=0;i<A;i++)
    {
        if(isSafe(comb,i,col,A))
        {
            comb[i][col] = 'Q' ;
            solveNQ(res,comb,col+1,A) ;
            comb[i][col] = '.' ;
        }
    }
    
}

vector<vector<string> > Solution::solveNQueens(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<vector<string>> res ;
    vector<string> comb(A) ;
    for(int i=0;i<A;i++)
    {
        string temp ;
        for(int j=0;j<A;j++) temp += '.' ;
        //cout<<temp<<endl ;
        comb[i] = temp ;
    }
    
    solveNQ(res,comb,0,A) ;
    return res ;
    
}
