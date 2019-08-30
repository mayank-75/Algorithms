# include<bits/stdc++.h>
# define ld long double
using namespace std ;

int main()
{
    int n,l ; cin>>n>>l ;
    ld a[n] ;
    for(int i=0;i<n;i++) cin>>a[i] ;
    sort(a,a+n);
    ld mini  = max(a[0],l-a[n-1]);
    for(int i=0;i<n-1;i++)
    {
        mini = max(mini,(a[i+1]-a[i])/2);
    }
    
    cout<<setprecision(9)<<fixed<<mini<<endl ;
}

/*# include<bits/stdc++.h>
# define ld long double
using namespace std ;

int check(double mid,double arr[],int n,double l)
{
	int i=0;
	for(i=0;i<n-1;i++)
	{
		if(arr[i+1]-arr[i]>2*mid)
		break;
	}
	if(i==n-1)
	return 1;
	else 
	return 0;
}
double binary_search(double arr[],int n,double l)
{
	double lo=max(arr[0],l-arr[n-1]);
	double h=l;
	while(h-lo>0.0000000001)
	{
		double mid=(h+lo)/2;
		if(check(mid,arr,n,l)==1)
		h=mid;
		else
		lo=mid;
	}
	return lo;
}
int main() 
{
	int n;
	double l;
	cin>>n>>l;
	double arr[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	sort(arr,arr+n);
	double ans=binary_search(arr,n,l);
	cout<<setprecision(9)<<fixed<<ans<<endl ;
	return 0;
}*/