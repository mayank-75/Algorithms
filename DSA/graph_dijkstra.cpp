# include<bits/stdc++.h>
# define int long long
# define siz 100000
using namespace std ;

/*trying to implement dijkstra algo*/

vector<pair<int, int>> v[siz];
bool vis[siz] ;
int dist[siz] ;
void dijkstra(int src, int n)
{
	for(int i=1;i<=n;i++)
	{
		vis[i] = false ;
		if(i!=src) dist[i] = INT_MAX ;
		else dist[i] = 0 ;
	}

	multiset<pair<int,int>> ms ;
	ms.insert({0,src}) ;
	//vis[src] = true ;

	while(!ms.empty())
	{
		pair<int,int> p = *ms.begin() ;
        ms.erase(ms.begin()) ;
		int vertex = p.second ;
		int x = p.first ;
		//cout<<x<<" "<<vertex<<endl ;
        if(vis[vertex] == true) continue ;
		for(int i=0;i<v[vertex].size();i++)
		{
           int e = v[vertex][i].first ;
           int w = v[vertex][i].second ;

           if(dist[e] > x + w) { dist[e] = x + w ; ms.insert({dist[e],e})} ;

           
           
		}

		vis[vertex] = true ;

	}
}

int32_t main()
{
   int n,m ; cin>>n>>m ;
   for(int i=1;i<=n;i++) v[i].clear() ;
   while(m--)
   {
   	 int a,b,w ; cin>>a>>b>>w ;
   	 v[a].push_back({b,w}) ;
   	 v[b].push_back({a,w}) ;
   }

   int src ; cin>>src ;
   dijkstra(src,n);

   for(int i=2;i<=n;i++) 
      cout<<dist[i]<<" " ;
   cout<<endl ;  
}

