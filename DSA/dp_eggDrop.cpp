#include <bits/stdc++.h>
using namespace std;

/* must go through this, really a good problem*/

/*int eggDrop(int e, int k)
{
    if(e == 1) return k ;
    if(k == 1 || k == 0) return k ;
    int mini = INT_MAX ;
    for(int i=1;i<=k;i++)
    {
        mini = min(mini,1+max(eggDrop(e-1,i-1),eggDrop(e,k-i)));
    }
    
    return mini ;
}*/

int main() {
	//code
	int t ; cin>>t ;
	while(t--)
	{
	    int e,k ; cin>>e>>k ;
	    int dp[e+1][k+1] ;
	    for(int i=0;i<=e;i++) dp[i][0] = 0 , dp[i][1] = 1 ;
	    for(int i=0;i<=k;i++) dp[1][i] = i ;
	    for(int i=2;i<=e;i++)
	    {
	        for(int j=2;j<=k;j++)
	        {
	            dp[i][j] = INT_MAX ;
	            for(int l=1;l<=j;l++)
	            {
	                dp[i][j] = min(dp[i][j],1+max(dp[i-1][l-1],dp[i][j-l]));
	            }
	        }
	    }
	    
	    cout<<dp[e][k]<<endl ;
	}
	return 0;
}