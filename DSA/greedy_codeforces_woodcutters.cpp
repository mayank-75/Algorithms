/* This question can be done  using greedy as well as dp
dp approach is done seperately in different code file
Greedy Appraoch-
It is always benficial to drop the tree in left if it is possible
then in right and it none leave it as it is
*/

# include<bits/stdc++.h>
# define int long long
# define MOD 1000000007
# define endl '\n'
# define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std ;
 
const int N = 1e9 ;
 
int32_t main()
{
	fastio
    #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif
    
    int n ; cin>>n ;
    if(n <=2) { cout<<n<<endl ; return 0 ; }
    pair<int,int> a[n] ;
    for(int i=0;i<n;i++) cin>>a[i].first>>a[i].second ;
    int l = a[0].first ;
    int cnt = 2 ;
    for(int i=1;i<n-1;i++)
    {
    	if(a[i].first - a[i].second > l) cnt++, l = a[i].first ;
    	else if(a[i].first+a[i].second < a[i+1].first)
    	{
    		cnt++, l = a[i].first+a[i].second ;
    	}
    	
    	else l = a[i].first ; 
    }
 
    cout<<cnt<<endl ;
}