# include<bits/stdc++.h>
# define int long long
# define pi pair<int,int>
using namespace std ;
const int MAX = 3000000000 ;

void dijkstra(int src,vector<pi> adj[], int dist[], int n)
{
	fill(dist+1,dist+n+1,MAX) ;
    dist[src] = 0 ;
	multiset<pi> ms ;
	ms.insert({0,src}) ;
	while(!ms.empty())
	{
		int u = ms.begin()->second ;
		ms.erase(ms.begin()) ;
		for(auto p : adj[u])
		{
			int v = p.first , c = p.second ;
			if(dist[v] > dist[u]+c)
			{
				dist[v] = dist[u]+c ;
				ms.insert({dist[v],v}) ;
			}
		}
	}
}


int32_t main()
{
	int t;  cin>>t ;
	while(t--)
	{
		int n,m,k,s,d ; cin>>n>>m>>k>>s>>d ;
		vector<pi> adj1[n+1], adj2[n+1] ;
		int u,v,c ;
		while(m--)
		{
           cin>>u>>v>>c ;
           adj1[u].push_back({v,c}) ;
           adj2[v].push_back({u,c}) ;
		}
		int dist1[n+1], dist2[n+1] ;
		int minDist = MAX ;
		dijkstra(s,adj1,dist1,n);
		dijkstra(d,adj2,dist2,n);
		int uk,vk,ck ;
		for(int i=0;i<k;i++)
		{
		   cin>>uk>>vk>>ck ;
           minDist = min(minDist,min(dist1[uk]+dist2[vk]+ck,dist1[vk]+dist2[uk]+ck)) ;
		}

		if(minDist == MAX) cout<<-1<<endl ;
		else cout<<minDist<<endl ;
	}
}