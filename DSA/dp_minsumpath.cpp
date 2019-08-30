// top down memoization approach
int minpath(int x, int y,vector<vector<int>> &A, vector<vector<int>> &dp, int n, int m)
{
    if(x == n-1 && y == m-1) return A[x][y] ;
    if(dp[x][y]!=-1) return dp[x][y] ;
    if(x == n-1) dp[x][y] = A[x][y] + minpath(x,y+1,A,dp,n,m) ;
    if(y == m-1) dp[x][y] = A[x][y] + minpath(x+1,y,A,dp,n,m) ;
    else dp[x][y] = A[x][y] + min(minpath(x,y+1,A,dp,n,m),minpath(x+1,y,A,dp,n,m)) ;
    return dp[x][y] ;
}

int Solution::minPathSum(vector<vector<int> > &A) {
    
    int n = A.size(), m = A[0].size() ;
    vector<vector<int>> dp(n,vector<int>(m,-1));
    return minpath(0,0,A,dp,n,m) ;
    
}

//bottom up approach
int Solution::minPathSum(vector<vector > &A) {
int i,j,n=A.size(),m=A[0].size();
int dp[n][m];
dp[0][0]=A[0][0];
for(i=0;i<n;i++){
for(j=0;j<m;j++){
if(i==0 and j==0)
continue;
else if(i==0)
dp[i][j]=dp[i][j-1]+A[i][j];
else if(j==0)
dp[i][j]=dp[i-1][j]+A[i][j];
else{
dp[i][j]=A[i][j]+min(dp[i-1][j],dp[i][j-1]);
}
}
}
return dp[n-1][m-1];
}