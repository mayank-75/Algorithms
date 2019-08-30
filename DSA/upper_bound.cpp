# include<bits/stdc++.h>
using namespace std ;

int upper_bound(int a[],int x,int n)
{
	int l = 0, r = n ;
	int mid ;
	while(l<r)
	{
	   mid = (l+r)/2 ;
	   if(a[mid] <= x) l = mid+1 ;
	   else r = mid ;
	}

	return l ;
}





int main()
{
	int t ; cin>>t ;
	while(t--)
	{
		int n,x ; cin>>n>>x ;
		int a[n] ;
		for(int i=0;i<n;i++) cin>>a[i] ;
        cout<<upper_bound(a,x,n)<<endl ;

	}
}