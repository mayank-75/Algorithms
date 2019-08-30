# include<bits/stdc++.h>
# define ld long double
using namespace std ;

ld calcsqrt(ld x,ld l, ld r)
{
   if(x == 1 || x == 0) return x ;
   ld ans , mid ;
   while(r-l > 0.00000001)
   {
      mid = (l+r)/2 ;
      if(mid*mid > x) r = mid, ans = mid ;
      else l = mid, ans = mid ;
   }

   return ans ;
}

int main()
{
   ld t ; cin>>t ;
   while(t--)
   {
   	 ld n ; cin>>n ;
   	 cout<<"squaroot is :"<<" "<<floor(calcsqrt(n,1,n))<<endl ;
   }
}