//Given a set of numbers, check whether it can be partitioned into two subsets such that the sum of elements in both subsets is same or not

// approach- if sum is odd then not possible, else check if sum/2 can be made using the given array elements.

#include <bits/stdc++.h>
using namespace std;



int main() {
	//code
	int t ; cin>>t ;
	while(t--)
	{
	    int n ; cin>>n ; 
	    int a[n], sum = 0 ;
	    for(int i=0;i<n;i++)
	    {
	        cin>>a[i] ; sum += a[i] ;
	    }
	    int b = 0 ;
	    if(sum%2) b = 0 ;
	    else
	    {
	        bool dp[n+1][sum/2+1] ;
	        for(int i=0;i<=sum/2;i++) dp[0][i] = false ;
	        for(int i=0;i<=n;i++) dp[i][0] = true ;
	        for(int i=1;i<=n;i++)
	        {
	            for(int j=1;j<=sum/2;j++)
	            {
	                if(j-a[i-1] >=0) dp[i][j] = dp[i-1][j-a[i-1]] || dp[i-1][j] ;
	                else dp[i][j] = dp[i-1][j] ;
	            }
	        }
	        
	        if(dp[n][sum/2]) b= 1 ;
	        
	    }
	    
	    if(b) cout<<"YES"<<endl ;
	    else cout<<"NO"<<endl ;
	    
	}
	return 0;
}

