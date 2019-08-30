# include<bits/stdc++.h>
using namespace std ;


int main()
{
  int t ; cin>>t ;
  while(t--)
  {
   int n,m ; cin>>n>>m ; 
   int a[n+1][m+1] ;
   for(int i=1;i<=n;i++)
   {
    for(int j=1;j<=m;j++)
      cin>>a[i][j] ;
   }

   /*int c = n*m ;
   int r = 0 ;
   while(c)
   {
     for(int j=1+r;j<=m-r;j++)
      cout<<a[1+r][j]<<" " , c-- ;

     for(int i=r+2;i<=n-r;i++)
      cout<<a[i][m-r]<<" " , c-- ;

    for(int j=m-1-r;j>=1+r;j--)
      cout<<a[n-r][j]<<" " , c-- ;

    for(int i=n-r-1;i>=2+r;i--)
      cout<<a[i][1+r]<<" " , c-- ;

    r++ ;
  }

  cout<<endl ;*/

   int k = 1, l = 1 ;
   while(k<=n && l<=m)
   {
     for(int j=l;j<=m;j++)
      cout<<a[k][j]<<" " ;

     for(int i=k+1;i<=n;i++)
      cout<<a[i][m]<<" " ;

     if(k<n)
     {for(int j=m-l;j>=l;j--)
      cout<<a[n][j]<<" " ;}

     if(l<m)
     {for(int i=n-1;i>=k+1;i--)
      cout<<a[i][l]<<" " ;}

     n-- , m-- , k++ ,l++ ;
   }
   
   cout<<endl ;

 }






}
