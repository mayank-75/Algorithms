# include<bits/stdc++.h>
# define ll long long
using namespace std ;

ll pturn(vector<ll> a, ll n)
{
	ll ans = 0 ;
	for(ll i= 1;i<n;i++) ans += abs(a[i]-a[i-1]) ; 
	return ans ; 
}

int main()
{
	ll n,m ; cin>>n>>m ;
	vector<ll> a(m) ;
    for(ll i=0;i<m;i++) cin>> a[i] ;
    ll odiff = pturn(a,m);
    //cout<<odiff<<endl ;
    ll mini = odiff ;
    for(ll i=0;i<m;i++)
    {
    	ll currmin ;
    	if(i == 0) currmin = odiff-abs(a[i]-a[i+1]);
    	else if(i == m-1) currmin = odiff-abs(a[i]-a[i-1]);
    	else
    	{
    		currmin = odiff-(abs(a[i]-a[i-1])+abs(a[i]-a[i+1]))+abs(a[i+1]-a[i-1]);
    	}

    	//cout<<"current min for"<<i<<": "<<currmin<<endl  ;

    	if(currmin < mini) mini = currmin ;
    }

    cout<<mini<<endl ;

}