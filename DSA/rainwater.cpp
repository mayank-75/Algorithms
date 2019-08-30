#include <bits/stdc++.h>
using namespace std;



int main() {
	//code
	int t ; cin>>t;
	while(t--)
	{
	    int n ; cin>>n ;

	    int a[n+1] ;
	    for(int i=1;i<=n;i++) cin>>a[i] ;
	    int left[n+1], right[n+1] ;
	    left[1] = a[1];
	    right[n] = a[n] ;
	    for(int i=2;i<=n;i++)
	    {
	    	left[i] = max(left[i-1],a[i]) ;
	    }

	    for(int i=n-1;i>=1;i--)
	    {
	    	right[i] = max(right[i+1],a[i]);
	    }

	    int ans = 0 ;

	    for(int i=1;i<=n;i++)
	    {
	    	ans += min(left[i],right[i])-a[i] ;
	    }

	    cout<<ans<<endl ;
	    
	}
	return 0;
}