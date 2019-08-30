# include<bits/stdc++.h>
using namespace std ;

//int a[1000] ;

void stableselsort(int a[], int n)
{
	for(int i=0;i<n-1;i++)
	{
		int mindex = i ;
  	   for(int j=i+1;j<n;j++)
  	   {
         if(a[mindex] > a[j]) mindex = j ;
  	   }

  	   int x = a[mindex] ;
  	   for(int j = mindex;j>i;j--) a[j] = a[j-1] ;
  	   a[i] = x ;

	}
}

/*void selsort(int a[] ,int n)
{
  for(int i=0;i<n-1;i++)
  {
  	 int mindex = i ;
  	 for(int j=i+1;j<n;j++)
  	 {
       if(a[mindex] > a[j]) mindex = j ;
  	 }

  	 if(mindex!=i)
  	 {
  	 	int temp = a[mindex] ;
  	 	a[mindex] = a[i] ;
  	 	a[i] = temp ;
  	 }
  }
}*/

int main()
{
   int n ; cin>>n ;
   int a[n] ;
   map<int,int> m ;
   for(int i=0;i<n;i++) cin>>a[i] ;
   for(int i=0;i<n;i++) m.insert(pair<int,int>(a[i],i));
   cout<<"order indices before sort :" ;
   for(int i=0;i<n;i++) cout<<a[i]<<" " ; cout<<endl ;
   for(int i=0;i<n;i++) cout<<m[a[i]]<<" " ; cout<<endl ;
   stableselsort(a,n) ;
   cout<<"order indices after sort :" ;
   for(int i=0;i<n;i++) cout<<a[i]<<" " ; cout<<endl ;
   for(int i=0;i<n;i++) cout<<m[a[i]]<<" " ; cout<<endl ;
}