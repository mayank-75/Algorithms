// AC in one go :) 
/*
 just like some other binary search problem, difficult 
 part is what is the element of search 
*/

/*
 approach-
 - assume giving max of candies given of all days is k
 - then apply binary search on k
*/

# include<bits/stdc++.h>
using namespace std ;
# define int long long


bool isPossible(int k, int a[], int b[], int n, int m)
{
   int ballons = 0 ;
   for(int i=0;i<n;i++)
   {
     ballons += max((int)0,a[i]-(k/b[i])) ;
     if(ballons > m) break ;
   }

   if(ballons <= m) return true ;
   return false ;
}

int32_t main()
{
   int n,m ; cin>>n>>m ;
   int a[n], b[n] ;
   for(int i=0;i<n;i++) cin>>a[i] ;
   for(int i=0;i<n;i++) cin>>b[i] ;
   int high = 0 ;
   for(int i=0;i<n;i++) high = max(high,a[i]*b[i]) ;

   int low = 0 ;
   while(low < high)
   {
     int mid = (low+high)/2 ;
     if(isPossible(mid,a,b,n,m)) high = mid ;
     else low = mid+1 ;
   }

   cout<<low<<endl ;
}
