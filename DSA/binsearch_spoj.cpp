#include <bits/stdc++.h>
# define ll long long
using namespace std;

bool eqn(vector<ll> v, ll x, ll ind, ll k, ll siz)
{
	ll sum = 0 ;
	for(ll i=ind;i<x+ind;i++) sum += v[i] ;
	ll rem = siz-x ;
    if(sum + rem  >= k*x) return 1 ;
    return 0 ;
}

int main() {
	// your code goes here
	ll t ; cin>>t ;
	while(t--)
	{
	    ll n,q ; cin>>n>>q ; 
	    vector<ll> a(n) ;
	    for(ll i=0;i<n;i++) cin>>a[i] ;
	    while(q--)
	    {
	        ll k ; cin>>k ;
	        ll c= 0 ;
	        sort(a.begin(),a.end(),greater<int>());
	        ll ind = 0 ;
	        ll l = 0, r = n-1 ;
	        ll mid, ans ;
	        while(l < r)
	        {
	            mid = (l+r)/2 ;
	            if(a[mid]>=k) l = mid+1 , ans = mid ;
	            else r = mid-1 ;
	        }
	        
	        c = ans+1 ;
	        ind = ans+1 ;
	        //cout<<a[ind]<<endl ;
	        ll size = n-ind ;
	        l = 0, r = size ;
	        while(l < r)
	        {
	        	ll x = (l+r)/2 ;
	        	if(eqn(a,x,ind,k,size)) l = x+1 , ans = x ;
	        	else r = x-1 ;

	        }
	        
	        cout<<c+ans<<endl ;
	    }
	}
	return 0;
}



