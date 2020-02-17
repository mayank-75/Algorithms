# include<bits/stdc++.h>
using namespace std ;

int binsearchx(int l, int r,int y)
{
	int mid,ans ;
	while(l<=r)
	{
		mid = (l+r)/2 ;
		cout<<"? "<<mid<<" "<<y<<endl ;
		fflush(stdout) ;
		string s ; cin>>s ;
		if(s == "YES") ans = mid,l = mid+1 ; 
		else r = mid-1 ;
	}

	return ans ;
}

int binsearchy(int l, int r,int x)
{
	int mid,ans ;
	while(l<=r)
	{
		mid = (l+r)/2 ;
		cout<<"? "<<x<<" "<<mid<<endl ;
		fflush(stdout) ;
		string s ; cin>>s ;
		if(s == "YES") ans = mid,l = mid+1 ; 
		else r = mid-1 ;
	}

	return ans ;
}

int main()
{
	int x1 = binsearchx(0,1000,0);
	//cout<<x1<<endl ;
	int x2 = binsearchx(0,1000,2*x1);
	//cout<<x2<<endl ;
	int y  = binsearchy(2*x1,1000,0);
	//cout<<y<<endl ;
    x1 *= 2 ;
	int ans = ((x1*x1)+(x2*(y-x1)));
	cout<<"! "<<ans<<endl ;
	
}
