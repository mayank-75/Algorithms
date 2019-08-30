# include<bits/stdc++.h>
# define int long long
using namespace std ;

int32_t main()
{
    int n ; cin>>n ;
    bool a[n] ;
    for(int i=0;i<n;i++) cin>>a[i] ;
    int cnt1 = 0 ;
    for(int i=0;i<n;i++) 
    {
        if(a[i]) cnt1++ ;
    }
    int res = 0 , s = 0, e = 0 ;
    for(int i=0;i<n;i++)
    {
        if(a[i])
        { 
            res = max(res,e-s) ;
            s = i+1, e = i+1 ; continue ; 
        }

        else e++ ;
    }

    res = max(res,e-s) ;
    if(res == 0) cout<<min(1LL,cnt1-1)<<endl ;
    else cout<<cnt1+res<<endl ;
}

/*void func1(int m ,int n, vector<int> &res, vector<int> comb)
{
    if(m == 0)
    {
        if(n == 0) res.push_back(comb) ;
        return  ;
    }
    for(int i=0;i<=9;i++)
    {
        if(n-i >= 0) 
        {
            comb.push_back(i) ;
            func1(m-1,n-i,res,comb) ;
        }
    }
}

void func2(int m ,int n, vector<int> &res, vector<int> comb)
{
    if(m == 0)
    {
        if(n == 0) res.push_back(comb) ;
        return  ;
    }
    for(int i=9;i>=0;i--)
    {
        if(n-i >= 0) 
        {
            comb.push_back(i) ;
            func2(m-1,n-i,res,comb) ;
        }
    }
}*/



/*int32_t main()
{
    int n ; cin>>n ;
    int a[n] ;
    for(int i=0;i<n;i++) cin>>a[i] ;
    int m ; cin>>m ;
    int b[m] ;
    for(int i=0;i<m;i++) cin>>b[i] ;
    int dp[n+1][m+1] ;
    sort(a,a+n) ; sort(b,b+m) ;
    memset(dp,0,sizeof(dp)) ;
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            if(i == 0 || j == 0) dp[i][j] = 0 ;
            else if(abs(a[i-1]-b[j-1]) <=1) dp[i][j] = 1+dp[i-1][j-1] ;
            else dp[i][j] = max(dp[i-1][j],dp[i][j-1]) ;
        }
    }

    cout<<dp[n][m]<<endl ;
}*/
