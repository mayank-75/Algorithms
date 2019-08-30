# include<bits/stdc++.h>
# define pb push_back
using namespace std ;
 /*program to check how many connected components in disconnected graph*/

vector<int> adj[100001] ;
bool vis[100001] = {0} ;
void dfs(int s)
{
	vis[s] = 1 ;
	//cout<<s<<" " ;
	for(int i=0;i<adj[s].size();i++)
	{
		if(vis[adj[s][i]] == 0) dfs(adj[s][i]) ;
	}
}

int main()
{
  int n,m ; cin>>n>>m ;
  int connected = 0 ;
  while(m--)
  {
  	int x,y ; cin>>x>>y ;
  	adj[x].pb(y) ;
  	adj[y].pb(x) ;
  }

  for(int i=1;i<=n;i++)
  {
    if(vis[i] == 0) dfs(i) , connected++ ;
  }

  cout<<"number of connected components :"<<connected<<endl ;

  /*cout<<"dfs traversal of graph is :" ;
  dfs(1) ;
  cout<<endl ;*/
}

