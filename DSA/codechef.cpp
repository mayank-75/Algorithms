# include<bits/stdc++.h>
# define int long long
using namespace std ;

int32_t main()
{
   int t;  cin>>t ;
   while(t--)
   {
     int n,q; cin>>n>>q ;
     int a[n] , b[n] ;
     map<int,int> mp ;
     for(int i=0;i<n;i++) cin>>a[i] , mp[a[i]] = i , b[i] = a[i] ;
     sort(b,b+n) ;


     int x ; cin>>x ;
     while(q--)
     {
       cin>>x ;
       int total_swaps = 0 ;
       int low = 0, high = n-1 ;
       while(low < high)
       {
         int mid = (low+high)/2 ;
         if(a[mid] > x)
         {
           if(mp[x] > mid) total_swaps++ ;
           high = mid-1 ;
         }
         else if(a[mid] < x)
         {
           if(mp[x] < mid) total_swaps++ ;
           low = mid-1 ;
         }
         else if (a[mid] == x) break ;
       }

       cout<<total_swaps<<endl ;
     }
   }
}