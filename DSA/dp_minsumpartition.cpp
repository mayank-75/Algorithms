/* In this we basically check if it is possible to make sum = sum/2 using given array
   we basically start checking from sum/2 beacuse min diff possible between 2 subserts
   is 0, and then we keep on decrementing sum/ to 0 ;*/

#include <bits/stdc++.h>
using namespace std;

bool isPossible(int sum, int n, int a[])
{
    bool dp[n+1][sum+1] ;
    for(int i=0;i<=sum;i++) dp[0][i] = false ;
    for(int i=0;i<=n;i++) dp[i][0] = true ;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=sum;j++)
        {
            if(j-a[i-1] >=0) dp[i][j] = dp[i-1][j-a[i-1]] || dp[i-1][j] ;
            else dp[i][j] = dp[i-1][j] ;
        }
    }
    
    return dp[n][sum] ;
}

int main() {
	//code
	int t ; cin>>t ;
	while(t--)
	{
	    int n ; cin>>n ;
	    int a[n] , sum = 0 ;
	    for(int i=0;i<n;i++){ cin>>a[i] ; sum += a[i] ;}
	    for(int i=sum/2;i>=0;i--)
	    {
	        if(isPossible(i,n,a)){ cout<<abs(sum-2*i)<<endl ; break ; }
	    }
	    /*if(isPossible(sum/2,n,a)) cout<<1<<endl ;
	    else cout<<-1<<endl ;*/
	    
	}
	return 0;
}