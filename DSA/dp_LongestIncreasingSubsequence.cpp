# include<bits/stdc++.h>
# define int long long
using namespace std;

int32_t main() {
	//code
	int t ;  cin>>t ;
	while(t--)
	{
	    int n ; cin>>n ;
	    int a[n] ;
	    for(int i=0;i<n;i++) cin>>a[i] ;
	    int dp[n];
	    fill(dp,dp+n,1) ;
	    for(int i=1;i<n;i++)
	    {
	        for(int j=0;j<i;j++)
	        {
	            if(a[i] > a[j] && 1+dp[j] > dp[i]) dp[i] = 1+dp[j];
	        }
	    }
	    
	    cout<<*max_element(dp,dp+n)<<endl ;
	     
	}
	return 0;
}