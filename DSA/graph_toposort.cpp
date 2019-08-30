# include<bits/stdc++.h>
# define int long long
using namespace std ;

/* program to calculate not only topological sort but also lexicographically smallest */

stack<int> s ;
bool vis[100001] ;
vector<int> adj[100001] ;
void topo(int src)
{
	vis[src] = true ;
	for(int i=0;i<adj[src].size();i++)
	{
		int node = adj[src][i] ;
		if(!vis[node])
		{
			topo(node) ;
		}
	}

	s.push(src) ;
}

int32_t main()
{
  int n,m ; cin>>n>>m ;
  for(int i=1;i<=n;i++) vis[i] = 0, adj[i].clear() ;
  while(m--)
  {
  	int x,y ; cin>>x>>y ;
  	adj[x].push_back(y) ;
  }

  for(int i=1;i<=n;i++)
  {
  	sort(adj[i].rbegin(),adj[i].rend()) ;
  }

  for(int i=n;i>=1;i--)
  {
  	if(!vis[i]) topo(i) ;
  }

  while(!s.empty())
  {
  	cout<<s.top()<<" " ;
  	s.pop() ;
  }

  cout<<endl ;
}