// this  is a beautiful question on dfs, got to learn something
// one of the best dfs question I have solved

# include<bits/stdc++.h>
using namespace std ;
# define int long long

void dfs(int src, vector<int> adj[], bool vis[], int c, int m, bool cat[], int &res)
{
    vis[src] = true ;
    if(cat[src]) c++ ;
    else c = 0 ;
    if(c > m) return ;
    if(src!=0 && adj[src].size() == 1)
    {
        res++; return ;
    }
    for(int v : adj[src])
    {
        if(!vis[v]) dfs(v,adj,vis,c,m,cat,res) ;
        
    }


}



int32_t main()
{
    int n,m ; cin>>n>>m ;
    vector<int> adj[n] ;
    int x,y ; 
    bool cat[n] ;
    for(int i=0;i<n;i++) cin>>cat[i] ;
    for(int i=0;i<n-1;i++)
    {
        cin>>x>>y ;
        adj[x-1].push_back(y-1) ;
        adj[y-1].push_back(x-1) ;
    }
    bool vis[n] ;
    memset(vis,false,n);
    int res = 0 ;
    dfs(0,adj,vis,0,m,cat,res) ;
    cout<<res<<endl ;
}