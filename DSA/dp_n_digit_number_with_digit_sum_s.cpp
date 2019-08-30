# define ll long long
# define mod 1000000007

ll allsumhelper(ll n, ll s, vector<vector<ll>> &dp)
{
    if(n == 0)
    {
        if(s == 0) return 1 ;
        return 0 ;
    }
    
    if(dp[n][s]!=-1) return dp[n][s] ;
    
    ll ans = 0 ;
    for(int i=0;i<=9;i++)
    {
        if(s-i >= 0) ans += allsumhelper(n-1,s-i,dp)%mod ;
    }
    
    return dp[n][s] = ans ;
}

ll allsum(ll n, ll s, vector<vector<ll>> &dp)
{
   ll ans = 0 ;
   for(int i=1;i<=9;i++)
   {
       if(s-i >=0) ans += allsumhelper(n-1,s-i,dp)%mod;
   }
   
   return ans ;
}

int Solution::solve(int N, int S) {
    
    vector<vector<ll>> dp(N+1,vector<ll>(S+1,-1)) ;
    return allsum(N,S,dp)%mod ;
}