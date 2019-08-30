# include<bits/stdc++.h>
# define int long long
# define pi pair<int,int>
using namespace std ;

pi bfs(int src, int des, vector<pi> adj[], bool vis[])
{
	queue<pair<int,pi>> q ; // node level dist
	q.push({src,{1,0}}) ;
	while(!q.empty())
	{
		auto p  = q.front() ;
		int u = p.first, level = p.second.first, dist = p.second.second ;
		vis[u] = true ;
		q.pop() ;
		if(u == des) return {level,dist} ;
		for(auto p : adj[u])
		{
			int v = p.first, edgeWei = p.second ;
			if(!vis[v]) q.push({v,{level+1,dist+edgeWei}}) ;
		}
	}
}

int32_t main()
{
	int t ; cin>>t ;
	while(t--)
	{
		int n ; cin>>n ;
		vector<pi> adj[n+1] ;
		for(int i=1;i<n;i++)
		{
			int a,b,c ; cin>>a>>b>>c ;
			adj[a].push_back({b,c}) ;
			adj[b].push_back({a,c}) ;
		}
		string s ;
		int a,b,k ;
		cin>>s ;
		bool vis[n+1] ;
		while(s!="DONE")
		{
			memset(vis,false,sizeof(vis)) ;
			if(s == "DIST")
			{
			   cin>>a>>b ;
			   pi res = bfs(a,b,adj,vis) ;
               cout<<res.second<<endl ;
			}

			else if(s == "KTH")
			{
               cin>>a>>b>>k ;
               pi res = bfs(a,b,adj,vis) ;
               cout<<res.first<<endl ;
			}
			cin>>s ;
		}
	}
}