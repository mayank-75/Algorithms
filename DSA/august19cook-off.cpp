# include<bits/stdc++.h>
# define int long long
using namespace std ;

bool compare(pair<int,int> p1, pair<int,int>p2)
{
	return p1.second > p2.second ;
}

int32_t main()
{
	int t ; cin>>t ;
	while(t--){
	int n,m,k,l,r ; cin>>n>>m>>k>>l>>r ;
	pair<int,int> p[n] ;
	for(int i=0;i<n;i++) cin>>p[i].first>>p[i].second ;
	sort(p,p+n,compare) ;
    int cost = -1 ;
    for(int i=0;i<n;i++)
    {
    	int diff ,  temp ;
    	if(p[i].first > k+1)
    	{
    		diff = p[i].first - (k+1) ;
    		if(diff > m) temp = p[i].first - m ;
    		else temp = k ;
    	}

    	else if(p[i].first < k-1)
    	{
    		diff = k-1 - p[i].first ;
    		if(diff > m) temp = p[i].first+m ;
    		else temp = k ;
    	}

    	else temp = k ;
        //cout<<temp<<endl ; 
    	if(temp >= l && temp <= r) cost  = p[i].second ;
    }
    cout<<cost<<endl ; }


}

/*int32_t main()
{
	int t ; cin>>t ;
	while(t--)
	{
		int n,q ; cin>>n>>q ;
		int a[n] ;
		for(int i=0;i<n;i++) cin>>a[i] ;
		sort(a,a+n) ;
		int x ;
	    while(q--)
	    {
	    	cin>>x ;
	    	int cnt  = 0 ;
	    	for(int i=0;i<n;i++)
	    	{
	    		if(x > a[i]) cnt++, x = 2*(x-a[i]) ;
	    		else break ;
	    	}

	    	cout<<cnt<<endl ;

	    }
	}
}*/