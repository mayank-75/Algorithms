/* 
based on number of ways to make sum n using m elements- gfg question
DP Approach
make 2D dp, 2nd dimension is to choose if n contains number greater than d or not
0- if it does not contaiin at least one number that is at least d
1- if it contains number at least one number that is at least d
*/

int32_t main()
{
	int n,k,d ; cin>>n>>k>>d ;
    int dp[n+1][2] ;
    memset(dp,0,sizeof(dp)) ;
    dp[0][0] = 1 , dp[0][1] = 0 ;
    //for(int i=0;i<=n;i++) cout<<dp[i][0]<<" "<<dp[i][1]<<endl ;
    for(int i=1;i<=n;i++)
    {
    	for(int j=1;j<=k;j++)
    	{
    		if(i-j >=0)
    		{
    			if(j >= d) dp[i][1] += (dp[i-j][0]%MOD + dp[i-j][1]%MOD)%MOD ;
    			else
    			{
    				dp[i][0] += dp[i-j][0]%MOD ;
    				dp[i][1] += dp[i-j][1]%MOD ;
    			} 

    		}
    	}
    }

    cout<<dp[n][1]%MOD<<endl ;
}