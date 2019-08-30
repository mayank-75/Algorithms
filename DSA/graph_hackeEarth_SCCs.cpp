# include<bits/stdc++.h>
using namespace std ;

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

void transpose(vector<int> adj[],int V)
{
    vector<int> Copy[V+1] ;
    copy(adj+1,adj+V+1,Copy+1) ;
    for(int i=1;i<=V;i++) adj[i].clear() ;
    for(int i=1;i<=V;i++)
    {
        for(int j=0;j<Copy[i].size();j++)
        {
            int x = i, y = Copy[i][j] ;
            adj[y].push_back(x) ;
        }
    }
}

int dfs2(vector<int> adj[], int src, bool vis[], int countNode[])
{
    vis[src] = true ;
    if(countNode[src]!=-1) return countNode[src] ;
    countNode[src] = 1 ; 
    for(int i=0;i<adj[src].size();i++)
    {
        int n = adj[src][i] ;
        if(!vis[n]) countNode[src] += dfs2(adj,n,vis,countNode) ;
    }
    
    return countNode[src] ;
    
    
}

int main()
{
    int n,m ; cin>>n>>m ;
    vector<int> adj[n+1] ;
    int a,b ;
    for(int i=0;i<m;i++)
    {
        cin>>a>>b ; adj[a].push_back(b) ;
    }
    stack<int> s ;
    bool vis[n+1] ;
    memset(vis,false,sizeof(vis)) ;
    for(int i=1;i<=n;i++)
    {
        if(!vis[i]) dfs1(adj,i,vis,s);
    }
    transpose(adj,n);
    int countNode[n+1] ;
    memset(countNode,-1,sizeof(countNode)) ;
    int c = 0,d = 0 ;
    int ans = 0 ;
    memset(vis,false,sizeof(vis));
    while(!s.empty())
    {
        int x = s.top() ; s.pop() ;
        if(!vis[x])
        {
            dfs2(adj,x,vis,countNode) ;
            if(countNode[x]%2) c += countNode[x] ;
            else d += countNode[x] ;
        }
    }
    //cout<<ans<<endl ;
    cout<<c-d<<endl ;
}