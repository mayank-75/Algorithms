# include<bits/stdc++.h>
# define pb push_back
using namespace std ;


vector<int> adj[10] ;
bool visited[10] ;

void bfs(int s)
{
	queue<int> q ;
	q.push(s) ;
	visited[s] = 1 ;
	while(!q.empty())
	{
		int node = q.front();
		cout<<node<<" " ;
		q.pop() ;
		for(int i=0;i<adj[node].size();i++)
		{
			if(visited[adj[node][i]] == 0) q.push(adj[node][i]) , visited[adj[node][i]] = 1 ;
		}
	}

	cout<<endl ;
}

int main()
{
	int n,m ; cin>>n>>m ;
	for(int i=0;i<10;i++) adj[i].clear();
	while(m--)
	{
		int x,y ; cin>>x>>y ;
		adj[x].pb(y) ;
		adj[y].pb(x) ;
	}

	int s = 0 ;

	bfs(0) ;


}
