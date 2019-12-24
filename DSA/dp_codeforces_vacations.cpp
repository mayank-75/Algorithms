# include<bits/stdc++.h>
# define int long long
# define MOD 1000000007
# define endl '\n'
# define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
# define f first
# define s second
using namespace std ;

/* approach-
We have to minimise the number of rest days, do we make a 2D dp where 2nd dimension is to tell 
whether vasya is going to gym, giving contest or taking rest.
0 - rest
1- code
2- gym
*/

int32_t main()
{
	fastio
    #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif
	int n ; cin>>n ;
	int a[n] ;
	for(int i=0;i<n;i++) cin>>a[i] ;
	int dp[n][3] ;
    for(auto &x : dp)
    {
    	for(int i=0;i<3;i++) x[i] = 1000 ;
    }

    /*for(auto x : dp)
    {
    	cout<<x[0] << " " << x[1] << " " <<x[2] << endl ; 
    }*/


    for(int i=0;i<n;i++)
    {
    	if(a[i] == 0)
    	{
    		if(i == 0) dp[i][0] = 1 ;
    		else dp[i][0] = 1+min({dp[i-1][0],dp[i-1][1],dp[i-1][2]}) ;
    	} 

    	else if(a[i] == 1)
    	{
    	   if(i == 0) dp[i][0] = 1 , dp[i][1] = 0 ;
           else
           {
             dp[i][1] = min({dp[i-1][0],dp[i-1][2]}) ;
             dp[i][0] = 1+min({dp[i-1][0],dp[i-1][1],dp[i-1][2]}) ;
           }
    	}

    	else if(a[i] == 2)
    	{
    	   if(i == 0) dp[i][0] = 1, dp[i][2] = 0 ;
           else
           {
       		 dp[i][2]  = min({dp[i-1][0],dp[i-1][1]}) ;
             dp[i][0] = 1 + min({dp[i-1][0],dp[i-1][1],dp[i-1][2]}) ;
           }
    	}

    	else 
    	{
    	   if(i == 0) dp[i][0] = 1, dp[i][1] = 0, dp[i][2] = 0 ;
    	   else
    	   {
    	   	 dp[i][0] = 1 + min({dp[i-1][0],dp[i-1][1],dp[i-1][2]});
             dp[i][1] = min(dp[i-1][0],dp[i-1][2]) ;
             dp[i][2] = min(dp[i-1][0],dp[i-1][1]) ;
    	   }
           
    	}
    }

    cout<<min({dp[n-1][0],dp[n-1][1],dp[n-1][2]}) ;
}