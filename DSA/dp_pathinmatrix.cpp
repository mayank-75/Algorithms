#include <bits/stdc++.h>
using namespace std;


int path(int i, int j, vector<vector<int>> &a, int n, vector<vector<int>> &dp)
{
   if(i <0 || i>=n || j<0 || j>=n) return 0 ;
   if(dp[i][j]!=-1) return dp[i][j] ;
   return dp[i][j] = a[i][j] + max(path(i+1,j,a,n,dp),max(path(i+1,j+1,a,n,dp),path(i+1,j-1,a,n,dp)));
}

int main() {
	//code
	int t; cin>>t ;
	while(t--)
	{
	    int n ; cin>>n ;
	    vector<vector<int>> a(n,vector<int>(n));
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<n;j++) cin>>a[i][j] ;
	    }
	    vector<vector<int>> dp(n,vector<int>(n,-1));
	    int max = INT_MIN ;
	    for(int i=0;i<n;i++)
	    {
	        if(max < path(0,i,a,n,dp)) max = path(0,i,a,n,dp);
	    }
	    
	    cout<<max<<endl ;
	    
	    
	}
	return 0;
}