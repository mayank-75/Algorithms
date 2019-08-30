# include<bits/stdc++.h>
using namespace std ;

int insort(int a[], int n)
{
	int c = 0 ;
	for(int i=1;i<n;i++)
	{
		int j = i-1 ;
		int key = a[i] ;
		while(key < a[j] && j>=0)
		{
			a[j+1] = a[j] ;
			j-- ;
			c++ ;
		}

		if(j!=-1) a[j+1] = key, c++ ;
		
	}

	return c ;
}

int main()
{
	int n ; cin>>n ;
	int a[n] ;
	for(int i=0;i<n;i++) cin>>a[i] ;
    int c = insort(a,n);
    for(int i=0;i<n;i++) cout<<a[i]<<" " ;
    	cout<<endl ;
    cout<<c<<endl ;
    
}