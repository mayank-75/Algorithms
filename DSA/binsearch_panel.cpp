# include<bits/stdc++.h>
# define ll long long
using namespace std ;

int binsearch(ll l, ll r)
{
	int mid, ans ;
	while(l<=r)
	{
		ll mid = (l+r)/2 ;
		cout<<1<<" "<<mid<<endl ;
		fflush(stdout) ;
		ll x ; cin>>x ;
		if(x == 1){ r = mid-1 ; cout<<2<<endl ; }
		else if(x == 0) ans = mid, l = mid+1 ;
	}

	return ans+1;
}

int main()
{
  ll n,c ; cin>>n>>c ;
  ll ans = binsearch(1,n);
  cout<<3<<" "<<ans<<endl ;
}
