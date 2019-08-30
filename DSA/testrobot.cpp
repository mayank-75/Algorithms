# include<bits/stdc++.h>
# define pb push_back
# define int long long
using namespace std ;

//trivial code
int32_t main()
{
   int t ; cin>>t ;
   while(t--)
   {
   	 int n,k ; cin>>n>>k ;
   	 int a[n+1] ;
   	 for(int i=1;i<=n;i++) cin>>a[i] ;
   	 int max = INT_MIN ;
   	 for(int i=1;i<=k;i++)
   	 {
   	 	int sum = 0 ;
   	 	for(int j=n-i+1;j>=0;j--)
   	 	{	sum += a[j] ;
   	 	   if(max < sum) max = sum ;
         }
   	 }
   	 

   	 cout<<max<<endl ;
   }
}

