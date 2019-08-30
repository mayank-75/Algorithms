# include<bits/stdc++.h>
# define pb push_back
using namespace std ;

vector<int> adj[100001] ;
bool vis[100001] = {0} ;
void dfs(int s)
{
	vis[s] = 1 ;
	cout<<s<<" " ;
	for(int i=0;i<adj[s].size();i++)
	{
		if(vis[adj[s][i]] == 0) dfs(adj[s][i]) ;
	}
}

int main()
{
  int n,m ; cin>>n>>m ;
  while(m--)
  {
  	int x,y ; cin>>x>>y ;
  	adj[x].pb(y) ;
  	adj[y].pb(x) ;
  }

  cout<<"dfs traversal of graph is :" ;
  dfs(1) ;
  cout<<endl ;
}

