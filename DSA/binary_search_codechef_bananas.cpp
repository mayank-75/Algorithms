// banging my head why getting TLE, got to learn something today
// reason for TLE-
/* was sortint the elements, yahh was getting bit lazy to calculate
max element and sorting takes nlogn whereas whole binary search takes logn time
*/

# include<bits/stdc++.h>
# define int long long
using namespace std ;

bool isPossible(int k, int a[], int n, int h)
{
   int hrs = 0 ;
   for(int i=0;i<n;i++)
   {
   	 hrs += ceil(a[i]/k) ;
   }
   //cout<<k<<" "<<hrs<<endl ;
   if(hrs <= h) return true ;
   else return false ;

}

int32_t main()
{
  int t ; cin>>t ;
  while(t--)
  {
  	int n,h ; cin>>n>>h ;
  	int a[n] ;
  	for(int i=0;i<n;i++) cin>>a[i] ;
  	int low = 1, high = *max_element(a,a+n) ;
    while(low < high)
    {
    	int mid = (low+high)/2 ;
    	if(isPossible(mid,a,n,h)) high = mid ;
    	else low = mid+1 ;
    }

    cout<<low<<endl ;
  }
}
