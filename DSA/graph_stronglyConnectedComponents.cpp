/*Algorithm-
sort the vertices in topological order using dfs and store them
then reverse the direction of directed edges of the graph
then perform one more dfs on the node in the topologcal order*/

void dfs1(vector<int> adj[], int src, bool vis[], stack<int> &s)
{
    vis[src] = true ;
    for(int i=0;i<adj[src].size();i++)
    {
        int n = adj[src][i] ;
        if(!vis[n]) dfs1(adj,n,vis,s) ;
    }
    s.push(src) ;
}

void dfs2(vector<int> adj[], int src, bool vis[])
{
    vis[src] = true ;
    for(int i=0;i<adj[src].size();i++)
    {
        int n = adj[src][i] ;
        if(!vis[n]) dfs2(adj,n,vis) ;
    }
}


void transpose(vector<int> adj[],int V)
{
    vector<int> Copy[V] ;
    copy(adj,adj+V,Copy) ;
    for(int i=0;i<V;i++) adj[i].clear() ;
    for(int i=0;i<V;i++)
    {
        for(int j=0;j<Copy[i].size();j++)
        {
            int x = i, y = Copy[i][j] ;
            adj[y].push_back(x) ;
        }
    }
}

int kosaraju(int V, vector<int> adj[])
{
    // Your code here
    stack<int> s ;
    bool vis[V] ;
    memset(vis,false,sizeof(vis)) ;
    for(int i=0;i<V;i++)
    {
        if(!vis[i]) dfs1(adj,i,vis,s) ;
    }
    transpose(adj,V) ;
    int ans = 0 ;
    memset(vis,false,sizeof(vis)) ;
    while(!s.empty())
    {
        int x = s.top() ; s.pop() ;
        if(!vis[x]) dfs2(adj,x,vis), ans++ ;
    }
    
    return ans ;
    
}

int main()
{
	int n, m ; cin>>n>>m ;
	vector<int> adj[n] ;
	int u,v ; 
	for(int i=0;i<m;i++)
	{
	   cin >> u >> v ;
           adj[u].push_back(v) ;
	}

	cout<<kosaraju(n,adj)<<endl ;
}
