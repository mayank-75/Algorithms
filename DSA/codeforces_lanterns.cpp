// thought of applying binary search but could be done otherwise also

# include<bits/stdc++.h>
using namespace std ;
# define ld long double

int main()
{
    int n,l ; cin>>n>>l ;
    ld a[n] ;
    for(int i=0;i<n;i++) cin>>a[i] ;
    sort(a,a+n);
    ld mini  = max(a[0],l-a[n-1]);
    for(int i=0;i<n-1;i++)
    {
        mini = max(mini,(a[i+1]-a[i])/2);
    }
    
    cout<<fixed<<setprecision(9)<<mini<<endl ;
}