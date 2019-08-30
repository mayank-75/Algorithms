# include<bits/stdc++.h>
using namespace std ;
# define int long long


void dfs(int src, vector<int> adj[], bool vis[], int color[])
{
    vis[src] = true ;
    for(int x : adj[src])
        {
            if(!vis[x]){
            if(color[src] == -1 && color[x] == -1) color[src] =1, color[x] = !color[src] ;
            else if(color[src] == -1) color[src] = !color[x] ;
            else if(color[x] == -1) color[x] = !color[src] ;
            dfs(x,adj,vis,color) ; }
            //cout<<color[i]<<" "<<color[x]<<endl ;
        }
}

int32_t main()
{
    int n;  cin>>n ;
    int u,v ;
    vector<int> adj[n] ;
    for(int i=0;i<n-1;i++) 
    {
        cin>>u>>v ;
        adj[u-1].push_back(v-1) ;
        adj[v-1].push_back(u-1) ;
    }

    int color[n] ;
    memset(color,-1,sizeof(color)) ;
    bool vis[n] ;
    memset(vis,false,n) ;
    dfs(0,adj,vis,color) ;

    int l = 0, r = 0 ;
    for(int i=0;i<n;i++)
    {
        if(color[i] == 1) l++ ;
        else r++ ;
    }
    cout<<l<<" "<<r<<endl ;
    if(l == 0 || r == 0) cout<<0<<endl ;
    else cout<<(l*r -(n-1))<<endl ;
}