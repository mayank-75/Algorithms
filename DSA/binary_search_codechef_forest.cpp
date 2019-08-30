// same bin search concept, constraints were tough 
/* my mistake-
there was long long overflow, so needed to break as soon as 
wood required is met, no need to take further
*/

# include<bits/stdc++.h>
using namespace std ;
# define int long long

bool isPossible(int m, pair<int,int> a[], int n, int l, int wood)
{
   int  w = 0 ;
   for(int i=0;i<n;i++)
   {
     int x = a[i].first+(a[i].second*m) ;
     if(x>=l) w += x ;
     if(w >= wood) break ;
   }

   return w>=wood ;
}

int32_t main()
{
   int n,w,l ; cin>>n>>w>>l ;
   pair<int,int> a[n] ;
   for(int i=0;i<n;i++) cin>>a[i].first>>a[i].second ;
   int low = 0, high = 1e18 ;
   while(low < high)
   {
     int mid = (low+high)/2 ;
     if(isPossible(mid,a,n,l,w)) high = mid ;
     else low = mid+1 ;
   }
   cout<<low<<endl ;
}