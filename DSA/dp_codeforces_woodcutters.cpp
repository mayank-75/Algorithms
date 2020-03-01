/*
nice dp problem
approach-
There are 3 possibilities for a tree
1- fall it to the left
2- fall it to the right
3- do not fall it
Take the maximum of the 3 possibilities*/

# include<bits/stdc++.h>
# define int long long
# define MOD 1000000007
# define endl '\n'
# define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
# define f first
# define s second
using namespace std ;

int32_t main()
{
	int n ; cin>>n ;
	if(n <= 2) { cout<<n<<endl ; return 0 ;}
	pair<int,int> a[n] ;
	for(int i=0;i<n;i++) cin>>a[i].f>>a[i].s ;
	// 0 means do not fall a tree, 1 means to the left, 2 means to the right
	int dp[n][3] ;
    memset(dp,0,sizeof(dp)) ;
    dp[0][0]= 0, dp[0][1] = 1, dp[0][2] = 0 ;
    for(int i=1;i<n-1;i++)
    {
    	dp[i][0] = max({dp[i-1][0],dp[i-1][1],dp[i-1][2]}) ;
    	if(a[i].f - a[i].s > a[i-1].f) dp[i][1] = 1 + max(dp[i-1][0],dp[i-1][1]) ;
    	if(a[i].f - a[i].s > a[i-1].f + a[i-1].s) dp[i][1] = max(dp[i][1],1+dp[i-1][2]) ;
    	if(a[i].f + a[i].s < a[i+1].f) dp[i][2] = 1 + max({dp[i-1][0], dp[i-1][1],dp[i-1][2]}) ; 
    }

    cout<<1+max({dp[n-2][0],dp[n-2][1],dp[n-2][2]})<<endl ;


}
