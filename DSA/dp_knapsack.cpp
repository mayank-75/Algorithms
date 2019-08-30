#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t ; cin>>t ;
	while(t--)
	{
	    int n,w ; cin>>n>>w ;
	    int val[n], wei[n];
	    for(int i=0;i<n;i++) cin>>val[i] ;
	    for(int i=0;i<n;i++) cin>>wei[i] ;
	    int dp[n+1][w+1];
	    for(int i=0;i<=w;i++) dp[0][i] = 0 ;
	    for(int i=0;i<=n;i++) dp[i][0] = 0 ;
	    for(int i=1;i<=n;i++)
	    {
	        for(int j=1;j<=w;j++)
	        {
	            if(j-wei[i-1] >=0) dp[i][j] = max(dp[i-1][j],val[i-1]+dp[i-1][j-wei[i-1]]);
	            else dp[i][j] = dp[i-1][j] ;
	        }
	    }
	    
	    cout<<dp[n][w]<<endl ;
	}
	return 0;
}