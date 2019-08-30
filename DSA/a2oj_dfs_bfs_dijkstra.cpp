# include<bits/stdc++.h>
# define int long long
# define pi pair<int,int>
using namespace std ;

int32_t main()
{
	int t ; cin>>t ;
	while(t--)
	{
		int k ; cin>>k ;
		int n,m ; cin>>n>>m ;
		// node, len, toll
		vector<pair<int,pi>> adj[n+1] ;
		int u,v,l,toll ;
		for(int i=0;i<m;i++)
		{
		   cin>>u>>v>>l>>toll ;
           adj[u].push_back({v,{l,toll}}) ;
		}

		multiset<pair<int,pi>> ms ;
		// dist, node, toll 
		ms.insert({0,{1,0}}) ;
		int dist[n+1] ;
		fill(dist+1,dist+n+1,INT_MAX) ;
		/*int vis[n+1] ;
		fill(vis+1,vis+n+1,false) ;*/
		dist[1] = 0 ;
		while(!ms.empty())
		{
			auto p  = *ms.begin() ;
			int node = p.second.first ;
			if(node == n) break ;
			int ut = p.second.second ;
			ms.erase(ms.begin()) ;
			/*if(vis[node]) continue ;
			vis[node] = true ;*/
			for(int i=0;i<adj[node].size();i++)
			{
				int vv = adj[node][i].first ;
				int vl = adj[node][i].second.first ;
				int vt = adj[node][i].second.second ;
				if(ut+vt <= k)
				{
				  dist[vv] = dist[node]+vl ;
				  ms.insert({dist[vv],{vv,ut+vt}}) ;
				}
			}

		}

		if(dist[n] == INT_MAX) cout<<-1<<endl ;
		else cout<<dist[n]<<endl ;

    }
}