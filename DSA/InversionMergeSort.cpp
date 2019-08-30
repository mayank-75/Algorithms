# include<bits/stdc++.h>
# define ll long long
using namespace std ;

ll merge(ll a[], ll l, ll r, ll inv)
{

	ll m = (l+r)/2 ;
	ll n1 = m-l+1 ;
	ll n2 = r-m ;
	ll t1[n1], t2[n2] ;
	for(ll i=0;i<n1;i++) t1[i] = a[l+i] ;
	for(ll i=0;i<n2;i++) t2[i] = a[m+1+i] ;

	ll i = 0, j=0 ;
    ll k = l ;
    while(i<n1 && j<n2)
    {
    	if(t1[i]>t2[j]) a[k] = t2[j], j++, inv += (n1-i);
    	else a[k] = t1[i], i++ ;
    	k++ ;
    }

    while(i<n1)
    {
    	a[k] = t1[i] ;
    	i++ ;
    	k++ ;
    }

    while(j<n2)
    {
    	a[k] = t2[j] ;
    	j++ ;
    	k++ ;
    }

    return inv ;
}

ll mergesort(ll a[], ll l ,ll r)
{
	ll ans ;
	if(l<r)
	{
		ll mid = (l+r)/2 ;
		ll inv1 = mergesort(a,l,mid) ;
		ll inv2 = mergesort(a,mid+1,r);
		return  merge(a,l,r,inv1+inv2) ;

    }

    else return 0 ;

    
}

int main()
{
	ll t ; cin>>t ;
	while(t--)
	{
   ll n ; cin>>n ;
   ll a[n] ;
   for(ll i=0;i<n;i++) cin>>a[i] ;
   cout<<mergesort(a,0,n-1)<<endl ; }
}