#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

vector<pair<int,int>> v[3001] ;
vector<int> dist(3001) ;
bool vis[3001] ;

// Complete the shortestReach function below.
vector<int> shortestReach(int n, vector<vector<int>> edges, int s) {
   
   for(int i=1;i<=n;i++)
   {
       vis[i] = false ;
       v[i].clear() ;
       if(i!=s) dist[i] = INT_MAX ;
       else dist[i] = 0 ;
   }
   int m = edges.size() ;
   for(int i=0;i<m;i++)
   {
       v[edges[i][0]].push_back({edges[i][1],edges[i][2]}) ;
   }
   multiset<pair<int,int>> ms ;
   ms.insert({0,s}) ;

   while(!ms.empty())
   {
       pair<int,int> p = *ms.begin();
       ms.erase(ms.begin());
       int x = p.first ;
       int vrt = p.second ;

       if(!vis[vrt])
       {
           for(int i=0;i<v[vrt].size();i++)
           {
               int e = v[vrt][i].first ;
               int w = v[vrt][i].second ;

               if(dist[e] > x + w)
               {
                   dist[e] = x + w ;
                   ms.insert({dist[e],e}) ;
               }
           }

           vis[vrt] = true ;
       }


   }

   vector<int> ans(n) ;
   for(int i=1;i<=n;i++)
   {
     if(dist[i] == INT_MAX) dist[i] = -1 ;
     ans[i-1] = dist[i] ;
   } 

   return ans ;

}


int main()
{
  int t ; cin>>t ;
  while(t--)
  {
   int n,m ; cin>>n>>m ;
   vector<vector<int>> edges(m) ;
   for(int i=0;i<m;i++)
   {
     int from, to, wei ; cin>>from>>to>>wei ;
     edges[i].push_back(from) ;
     edges[i].push_back(to) ;
     edges[i].push_back(wei);
   }

   int s ; cin>>s ;

   vector<int> ans(n) ;
   ans = shortestReach(n,edges,s) ;

   for(int x : ans)
    cout<<x<<" " ;
   cout<<endl ;
  }
}