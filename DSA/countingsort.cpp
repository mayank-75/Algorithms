# include<bits/stdc++.h>
# define ll long long
using namespace std ;

vector<int> csort(vector<int> v)
{
	int n = v.size() ;
	int min = *min_element(v.begin(),v.end());
	int max = *max_element(v.begin(),v.end());
	int r = max-min+1 ;
	vector<int> c(r) ;
	for(int i=0;i<n;i++)
	{
		c[v[i]-min]++ ;
	}

	for(int i=1;i<r;i++)
	{
		c[i] += c[i-1] ;
	}

	vector<int> a(n) ;

	for(int i=0;i<n;i++)
	{
		a[c[v[i]-min]-1] = v[i] ;
		c[v[i]-min]-- ;
	}

	/*for(int x : a) cout<<x<<" " ;
		cout<<endl ;*/

	return a ;


}

int main()
{
	int t ; cin>>t ;
	while(t--)
	{
	   int n ; cin>>n ;
	   vector<int> v(n) ;
	   for(int i=0;i<n;i++) cin>>v[i] ;
	   vector<int> a = csort(v) ;
	   for(int x : a) cout<<x<<" " ;
	   	cout<<endl ;
	}
}