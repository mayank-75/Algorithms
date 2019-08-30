# include<bits/stdc++.h>
using namespace std ;

int binsearch(int a[],int l,int r, int x)
{
	int mid ;
	while(l<=r)
	{
		mid = (l+r)/2 ;
		if(a[mid] == x) return mid ;
		else if(a[mid]> x) r = mid-1;
		else l = mid+1 ;
	}

	return -1 ;
}

int pos(int a[],int l,int r, int n,int key)
{
	int mid = (l+r)/2 ;
	while(a[mid]<= a[mid+1] && mid!=n-1)
	{

		//cout<<l<<" " ;
		l = mid+1 ;
		mid = (l+r)/2 ;
		
	}

	//cout<<endl ;

	int start = binsearch(a,mid,n-1,key);

	if(start!=-1) return start ;
	else return -1 ;
}

int main()
{
	int t ; cin>>t ;
	while(t--)
	{
		int n ; cin>>n ;
		int a[n] ;
		for(int i=0;i<n;i++) cin>>a[i] ;
		int key ; cin>>key ;
	    int po = pos(a,0,n-1,n,key);
	    if(po!=-1) cout<<po<<endl ;
	    else cout<<"Not Found"<<endl ;

	}
}



/*int squaroot(int x)
{
	if(x == 1 || x == 0) return x ;
	int l = 1, r = x/2 ;
	int ans, mid ;
	while(l<=r)
	{
		mid = (l+r)/2 ;
		if(mid*mid == x) return mid ;
		else if(mid*mid < x) ans = mid , l = mid+1 ;
		else r = mid-1 ;
	}

	return ans;
}*/




/*int lower_bound(int a[], int l, int r, int x, int n)
{
	int mid ;
	while(l<=r)
	{
		if(a[mid] == x) return mid ;
		else if(a[mid]>x) r = mid ;
		else l = mid+1 ;
	}

	return l ;
}



int upper_bound(int a[], int l, int r, int x, int n)
{
	int mid ;
	while(l<=r)
	{
		
		mid = (l+r)/2 ;
		if(a[mid]<= x) l = mid+1 ;
		else r = mid ;
		if(l == r) break ;
	}
}*/



/*int fixedpoint(int a[], int l, int r, int n)
{
    int mid ;
    while(l<r)
    {
        mid = (l+r)/2 ;
        
        if(a[mid] == mid) return mid ;
        if(l == r-1) break ;
        else if(mid > a[mid])
        	l = mid+1 ;
        else if(mid < a[mid])
        	r = mid-1 ;
    }

    return -1 ;

    
}*/

/*int findpeak(int a[], int l, int r, int n)
{
	int mid ;
	while(l<r)
	{
		mid = (l+r)/2 ;
		if(a[mid] < a[mid-1] && mid!=0)
			r  =mid-1 ;
		else if(a[mid] < a[mid+1] && mid!=n-1)
			l = mid+1 ;
		else return a[mid] ;
	}

	return a[l] ;
}

int main()
{
	int t ; cin>>t ;
	while(t--)
    {
	  int n;  cin>>n ;
	  int a[n] ;
	  for(int i=0;i<n;i++) cin>>a[i] ;
	//int x ; cin>>x ;
      int ans = findpeak(a,0,n-1,n) ;
      cout<<"peak element always exists!"<<endl ;
      cout<<"peak element is :"<<ans<<endl ;
 
    }
}*/