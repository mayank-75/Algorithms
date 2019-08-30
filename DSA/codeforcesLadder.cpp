# include<bits/stdc++.h>
# define int long long
using namespace std ;


bool compare(pair<int,int>p1, pair<int,int>p2)
{
	if(p1.first!=p2.first) return p1.first > p2.first ;
	return p1.second > p2.second ;
}

int32_t main()
{
	int n,m ; cin>>n>>m ;
	vector<pair<int,int>> v ;
	int x ;
	for(int i=1;i<=n;i++)  cin>>x , v.push_back({x,i}) ;
	sort(v.begin(),v.end(),compare) ;
	int maxi  = v[0].first ;
    if(maxi <= m) cout<<n<<endl ;
    else cout<<v[0].second<<endl ;
}

/*int32_t main()
{
	int n ; cin>>n ;
	int numFingers = 0 ;
	int x  ;
	for(int i=0;i<n;i++) cin>>x, numFingers += x ;
	int res = 0 ;
	for(int i=1;i<=5;i++)
	{
		if((i+numFingers)%(n+1) != 1) res++ ;
	}
	cout<<res<<endl ;
}*/

/*int32_t main()
{
	int n ; cin>>n ;
	int arr[n+1] ;
	unordered_map<int,int> mp ;
	for(int i=1;i<=n;i++){ cin>>arr[i] , mp[arr[i]] = i ; }
	int m ; cin>>m ;
    int num , vasya = 0, petya = 0 ;
    while(m--)
    {
    	cin>>num ;
    	int comp = mp[num] ;
    	//cout<<comp<<" "<<(n-comp+1)<<endl ;
    	vasya += comp ;
    	petya += (n-comp+1) ;

    }

    cout<<vasya<<" "<<petya<<endl ;
}*/

/*int32_t main()
{
	int n ; cin>>n ;
	int sumX  = 0, sumY = 0, sumZ = 0 ;
	int x,y,z; 
	while(n--)
	{ 
      cin>>x>>y>>z ;
      sumX += x , sumY += y, sumZ += z ;
	}

	if(!sumX && !sumY && !sumZ) cout<<"YES"<<endl; 
	else cout<<"NO"<<endl ;
}*/