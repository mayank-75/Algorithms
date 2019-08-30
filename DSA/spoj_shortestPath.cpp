# include<bits/stdc++.h>
# define int long long
using namespace std ;

void dijkstra(int src, int des, vector<pair<int,int>> adj[], int dist[], int n)
{
	fill(dist+1,dist+n+1,INT_MAX) ;
	multiset<pair<int,int>> ms ;
	ms.insert({0,src}) ;
	dist[src] = 0 ;
	while(!ms.empty())
	{
	   int u = ms.begin()->second ;
	   if(u == des) break ;
	   ms.erase(ms.begin()) ;
	   for(int i=0;i<adj[u].size();i++)
	   {
	   	  int v = adj[u][i].first ;
	   	  int c = adj[u][i].second ;
	   	  if(dist[v] > c+dist[u])
	   	  {
	   	  	dist[v] = dist[u]+c ;
	   	  	ms.insert({dist[v],v}) ;
	   	  }
	   }
	}
}

int32_t main()
{
	int t ; cin>>t ;
	while(t--)
	{
		int n ; cin>>n ;
		map<string,int> mp ;
		vector<pair<int,int>> adj[n+1] ;
		for(int i=1;i<=n;i++)
		{
			string name ; cin>>name ;
			mp[name] = i ;
			int p ; cin>>p ;
			while(p--)
			{
			  int v,c ; cin>>v>>c ;
              adj[i].push_back({v,c}) ;
			}
		}

		int dist[n+1] ;
		int r ; cin>>r ;
		string name1, name2 ;
		while(r--)
		{
			cin>>name1>>name2 ;
			dijkstra(mp[name1],mp[name2],adj,dist,n) ;
			cout<<dist[mp[name2]]<<endl ;
		}

	}
}