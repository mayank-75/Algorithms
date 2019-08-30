# include<bits/stdc++.h>
using namespace std ;

void selectsort(int a[], int n)
{
	int key ;
	for(int i=1;i<n;i++)
	{
		key = a[i] ;
		int j = i-1 ;
		while(j>=0 && a[j]>=key)
		{
			swap(a[j],a[j+1]);
			j-- ;
		}


	}
}

int main()
{
   int n ; cin>>n ;
   int a[n] ;
   for(int i=0;i<n;i++) cin>>a[i] ;
   selectsort(a,n);
   for(int i=0;i<n;i++) cout<<a[i]<<" " ; cout<<endl ;
}