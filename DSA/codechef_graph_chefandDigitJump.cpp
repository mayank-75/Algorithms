# include<bits/stdc++.h>
# define int long long
using namespace std ;

int calCombinations(int n, int r, int dp[])
{
    if(r == 0 || r == n) return 1 ;
    if(dp[n][r]!=-1) return dp[n][r] ;
    return dp[n][r] = calCombinations(n-1,r-1,dp)+calCombinations(n-1,r,dp) ;
}

int32_t main()
{
    int t ; cin>>t ;
    while(t--)
    {
        int n,k ; cin>>n>>k ;
        n -= k ;
        int dp[n+1][k+1] ;
        memset(dp,-1,sizeof(dp)) ;
        cout<<calCombinations(n+k-1,k-1,dp)<<endl ;
    }
}