/* very easy ques  but a key thing to learn
 if every node has only one children simply keeping a vis array is sufficient
 finding cycle is very simple since only one child 
 NO TLE expecting a TLE but contraints are small
*/

# include<bits/stdc++.h>
using namespace std ;
# define int long long

int32_t main()
{
   int n;  cin>>n ;
   int child[n+1] ;
   int x ; 
   for(int i=1;i<=n;i++) cin>>x, child[i] = x ;
   for(int i=1;i<=n;i++)
   {
     bool vis[n+1] ;
     memset(vis,false,n+1) ;
     int x = i ;
     while(!vis[x])
     {
        vis[x] = true ;
        x = child[x] ;
     }
     cout<<x<<" " ;
   }

   cout<<endl ;
   

}


