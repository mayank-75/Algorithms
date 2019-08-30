/* simiar to all bin search problem
only diffence is need of sorting beacuse it wants 
also the cost to be min, so we sort in increasing order
of cost for each item
*/

#  include<bits/stdc++.h>
using namespace std ;
# define int long long

int32_t main()
{
    int n,sum ; cin>>n>>sum ;
    int a[n] ;
    for(int i=0;i<n;i++) cin>>a[i] ;
    int b[n] ;
    int low = 0, high = n ;
    int k,t ;
    while(low <= high)
    {
        int mid = (low+high)/2 ;
        for(int i=0;i<n;i++) b[i] = a[i]+((i+1)*mid) ;
        sort(b,b+n) ;
        int s = 0 ;
        for(int i=0;i<mid;i++) s += b[i] ;
        if(s<=sum) low = mid+1 , k =mid, t = s ;
        else high = mid-1 ;
    }

    cout<<k<<" "<<t<<endl ;
}