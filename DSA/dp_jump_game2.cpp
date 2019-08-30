#include <bits/stdc++.h>
using namespace std;

// o(N) sol
int main() {
	//code
	int t ; cin>>t ;
	while(t--)
	{
	    int n ; cin>>n ;
	    int a[n] ;
	    for(int i=0;i<n;i++) cin>>a[i] ;
	    if(n <= 1) cout<<1<<endl ;
	    int max_index = -1 , lim = a[0] ;
	    int ans = 1 ;
	    bool b = 0 ;
	    for(int i=0;i<n;i++)
	    {
	        if(max_index <= i && a[i] == 0){ b = 1 ; break ; }
	        if(i > lim) ans++ , lim = max_index ;
	        max_index = max(max_index,i+a[i]);
	    }
	    
	    if(max_index < n-1 || b) cout<<-1<<endl ;
	    else cout<<ans<<endl ;
	}
	return 0;
}