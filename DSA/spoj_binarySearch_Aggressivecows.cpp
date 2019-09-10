# include<bits/stdc++.h>
# define ll long long
using namespace std ;

bool check(ll a[], ll x, ll c,ll n)
{
   ll prevpos = a[0] ;
   ll cows = 1 ;
   for(ll i=1;i<n;i++)
   {
   	 if((a[i]-prevpos)>=x){ cows++ ; prevpos = a[i] ; }
   	 if(cows == c) return 1 ;
   }

   return 0 ;
}

int binsearch(ll a[],ll n,ll c)
{
	ll l = 1,r = a[n-1]-a[0] ;
	ll mid, ans ;
	while(l<=r)
	{
		mid = (l+r)/2 ;
		if(check(a,mid,c,n)) ans = mid,l = mid+1 ;
		else r = mid-1 ;
	}

	return ans ;

}

int main()
{
	ll t ; cin>>t ;
	while(t--)
	{
		ll n,c ; cin>>n>>c ;
		ll a[n] ;
		for(ll i=0;i<n;i++) cin>>a[i] ;
		sort(a,a+n) ;
		ll ans = binsearch(a,n,c);
	    cout<<ans<<endl ;
	}
}