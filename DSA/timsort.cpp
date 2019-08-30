# include<bits/stdc++.h>
# define ll long long
using namespace std ;

ll insort(ll a[], ll l, ll r)
{
	ll s = 0 ;
	for(ll i=l+1;i<=r;i++)
	{
       ll j = i-1 ;
       ll key = a[i] ;
       while(a[j] > key && j>=l)
       {
       	 a[j+1] = a[j] ;
       	 j-- ;
       	 s++ ;
       }
       
       a[j+1] = key ;
       if(j!=l-1) s++ ;
	}

	return s ;
}

ll merge(ll a[], ll l, ll r, ll mid)
{
	ll n1 = mid-l+1 ;
	ll n2 = r-mid ;
	ll t1[n1], t2[n2] ;
	for(ll i=0;i<n1;i++) t1[i] = a[i+l] ;
	for(ll i=0;i<n2;i++) t2[i] = a[i+mid+1] ;
    ll m = 0 ;
    ll k = l, i=0, j=0;
    while(i<n1 && j<n2)
    {
    	if(t1[i] > t2[j]) a[k] = t2[j++] ;
    	else a[k] = t1[i++] ;
    	k++ ;
    	m++ ;
    }

    while(i<n1) a[k++] = t1[i++] ;
    while(j<n2) a[k++] = t2[j++] ;
    return m ;
}

void timsort(ll  a[], ll n, ll r)
{
	ll s = 0, m = 0 ;
	for(ll i=0;i<n;i+=r)
	{
	   s += insort(a,i,min(i+r-1,n-1)) ;
	}

	for(ll i=r;i<n;i*=2)
	{
		for(ll j=0;j<n;j+=2*r)
		{
          ll left = j;
          ll mid = min(j+i-1,n-1);
		  ll right = min(j+2*i-1,n-1) ;
		  ll x = merge(a,left,right,mid) ;
		  //cout<<x<<" " ;
		  m += x ;
}

	}

	//cout<<endl ;

    if(n>=r) cout<<s<<" "<<m<<endl ;
}

int main()
{
	ll t,r; cin>>t>>r ;
	while(t--)
	{
      ll n ; cin>>n ;
	  ll a[n] ;
	  vector<ll> ans(2) ;
	  for(ll i=0;i<n;i++) cin>>a[i] ;
	  timsort(a,n,r);
      for(ll i=0;i<n;i++) cout<<a[i]<<" " ;
    	cout<<endl ; 
    }
    //cout<<ans[0]<<" "<<ans[1]<<endl ;
}