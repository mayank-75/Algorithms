# include<bits/stdc++.h>
using namespace std ;

int merge(int a[], int l, int r)
{
    int c = 0 ;
	int m = (l+r)/2 ;
	int n1 = m-l+1 ;
	int n2 = r-m ;
	int t1[n1], t2[n2] ;
	for(int i=0;i<n1;i++) t1[i] = a[l+i] ;
	for(int i=0;i<n2;i++) t2[i] = a[m+1+i] ;

	  int i = 0, j=0 ;
    int k = l ;
    while(i<n1 && j<n2)
    {
    	if(t1[i]>t2[j]) a[k] = t2[j], j++ ;
    	else a[k] = t1[i], i++ ;
    	k++ ; c++ ;
    }

    while(i<n1) a[k++] = t1[i++] ;
    	
    

    while(j<n2) a[k++] = t2[j++] ;
    	
    

    return c ;
}

void mergesort(int a[], int l ,int r)
{
	if(l<r)
	{
		int mid = (l+r)/2 ;
		mergesort(a,l,mid) ;
		mergesort(a,mid+1,r);
		merge(a,l,r) ;
    }

}

int main()
{
  int n ; cin>>n ;
  int a[n] ; 
  for(int i=0;i<n;i++) cin>>a[i] ;
  cout<<mergesort(a,0,n-1)<<endl ;
}