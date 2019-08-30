# include<bits/stdc++.h>
# define ll long long
using namespace std ;



int main()
{
  ll t ; cin>>t ;
  while(t--)
  {
  	 ll n ; cin>>n ; 
  	 vector<ll> a(n) ;
  	 for(ll i=0;i<n;i++) cin>>a[i] ;
  	 ll swaps = 0 ;
  	 for(ll i=0;i<n;i++)
  	 {
  	 	auto mini = min_element(a.begin()+i,a.end());
  	 	if(a[mini-a.begin()] != a[i]) swap(*mini,a[i]), swaps++ ;
  	 }

  	 cout<<swaps<<endl ;
  }
}