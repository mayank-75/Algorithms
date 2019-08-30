// definitely a very beautiful dp question, not very hard but 
// hard to think in this line of thought

/*approach-
- as alaways we can either choose an element or not choose
- if we choose we cant choose ele-1 ans ele+1.
- need not connsider ele+1, already been taken care by next element that will be chosen
- then just do cumulative sum 
*/

# include<bits/stdc++.h>
using namespace std ;
# define int long long
int dp[100001] ;
 
int32_t main()
{
    int n;  cin>>n ;
    unordered_map<int,int> mp ;
    int x ; 
    for(int i=0;i<n;i++) cin>>x , mp[x]++ ;
    dp[1] = mp[1], dp[0] = 0 ;
    for(int i=2;i<=100000;i++)
    {
        dp[i] = max(dp[i-1],dp[i-2]+mp[i]*i) ;
    }
    cout<<dp[100000]<<endl ;
}