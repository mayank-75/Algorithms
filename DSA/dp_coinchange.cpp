#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t ; cin>>t ;
	while(t--)
	{
	    int n ; cin>>n ;
	    int a[n] ;
	    for(int i=0;i<n;i++) cin>>a[i] ;
	    int s ; cin>>s ;
	    int dp[n+1][s+1] ;
	    for(int i=0;i<=s;i++) dp[0][i] = 0 ;
	    for(int i=0;i<=n;i++) dp[i][0] = 1 ;
	    for(int i=1;i<=n;i++)
	    {
	        for(int j=1;j<=s;j++)
	        {
	            if(j-a[i-1] >=0) dp[i][j] = dp[i][j-a[i-1]] + dp[i-1][j];
	            else dp[i][j] = dp[i-1][j] ;
	        }
	    }
	    
	    cout<<dp[n][s]<<endl ;
	}
	return 0;
}