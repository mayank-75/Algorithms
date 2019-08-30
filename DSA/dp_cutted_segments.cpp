#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t ; cin>>t ;
	while(t--)
	{
	    int s ; cin>>s ;
	    int a[3] ;
	    for(int i=0;i<3;i++) cin>>a[i] ;
	    int dp[4][s+1] ;
	    for(int i=0;i<=s;i++) dp[0][i] = INT_MIN ;
	    for(int i=0;i<=3;i++) dp[i][0] = 0 ;
	    for(int i=1;i<=3;i++)
	    {
	        for(int j=1;j<=s;j++)
	        {
	            if(j-a[i-1] >=0) dp[i][j] = max(1+dp[i][j-a[i-1]],dp[i-1][j]);
	            else dp[i][j] = dp[i-1][j] ;
	        }
	    }
	    
	    cout<<dp[3][s]<<endl ;
	}
	return 0;
}