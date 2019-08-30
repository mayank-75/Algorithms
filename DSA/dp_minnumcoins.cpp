#include <bits/stdc++.h>
# define int long long
using namespace std;
const int MAX = INT_MAX ;

int32_t main() {
	//code
	int t ; cin>>t ;
	while(t--)
	{
	    int v,n ; cin>>v>>n ;
	    int a[n] ;
	    for(int i=0;i<n;i++) cin>>a[i] ;
	    int dp[n+1][v+1] ;
	    for(int i=0;i<=v;i++) dp[0][i] = INT_MAX-1 ;
	    for(int i=0;i<=n;i++) dp[i][0] = 0 ;
	    for(int i=1;i<=n;i++)
	    {
	        for(int j=1;j<=v;j++)
	        {
	            if(j-a[i-1] < 0) dp[i][j] = dp[i-1][j] ;
	            else dp[i][j] = min(1+dp[i][j-a[i-1]],dp[i-1][j]);
	        }  
	    }
	    
	    
	    if(dp[n][v]==INT_MAX-1) cout<< -1 <<endl ;
	    else cout<<dp[n][v]<<endl ;
	    
	    
	}
	return 0;
}