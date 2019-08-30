# include<bits/stdc++.h>
# define pb push_back
using namespace std ;

vector<int> adj[1000] ;
bool visited[1000] ;
int level[1000] ;

int mindis(int u, int v)
{
   visited[u] = 1 ;
   level[u] = 0 ;
   queue<int> q ;
   q.push(u) ;
   while(!q.empty())
   {
   	 int p = q.front() ;
   	 q.pop();
   	 for(int i=0;i<adj[p].size();i++)
   	 {
   	 	if(visited[adj[p][i]] == 0)
   	 	{
   	 		q.push(adj[p][i]) ;
   	 		visited[adj[p][i]] = 1 ;
   	 		level[adj[p][i]] =  level[p]+1 ;
   	 	}
   	 }

   }

   return level[v] ;
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

	int u,v ; cin>>u>>v ;
	cout<<"min distance between u  and v is "<<mindis(u,v)<<endl ;
}