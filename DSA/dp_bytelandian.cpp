#include <bits/stdc++.h>
using namespace std;

int maxi (int n, vector<int>&dp)
{	
	
	if (n<=1)
		return n;
	if (dp[n]!=-1)
		return dp[n];
    dp[n]=max(n,maxi(n/2,dp)+maxi(n/3,dp)+maxi(n/4,dp));
    //cout<<dp[n]<<endl ;
    return dp[n] ;
	
}

int main() {
	// your code goes here
	int t; cin>>t ;
	while(t--)
	{
		int n ; cin>>n ;
		vector<int> dp(n+1,-1) ;
		int ans = maxi(n,dp) ;
		cout<<ans<<endl ;
	}
	return 0;
}

int32_t