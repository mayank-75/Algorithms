# include<bits/stdc++.h>
using namespace std ;

int findPivot(vector<int>&a, int l, int r)
{
	int mid ;
	while(l<r)
	{
		mid = (l+r)/2 ;
		if(mid > l && a[mid] < a[mid-1]) return mid-1 ;
		else if(mid < r && a[mid] > a[mid+1]) return mid ;
		else if(a[mid] < a[l]) r= mid-1 ;
		else l = mid+1 ;
	}

	return l ;
}

int main()
{
	int t ; cin>>t ;
	while(t--)
	{
		int n ; cin>>n ;
		vector<int> v(n) ;
		for(int i=0;i<n;i++) cin>>v[i] ;
		cout<<findPivot(v,0,n)<<endl ;
	}

}