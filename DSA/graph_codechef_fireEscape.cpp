// easy ques but used DSU data structure first time in a question
# include<bits/stdc++.h>
# define int long long
# define mod 1000000007
using namespace std ;

// lets do using DSU 

int find(int x, int parent[])
{
    if(parent[x] == x) return x ;
    return find(parent[x],parent) ;
}

void unite(int x, int y, int parent[])
{
    int p_x = find(x,parent), p_y = find(y,parent) ;
    parent[p_x] = p_y ;
}

int32_t main()
{
    int t ; cin>>t ;
    while(t--)
    {
        int n,m ; cin>>n>>m ;
        int parent[n+1] ;
        for(int i=1;i<=n;i++) parent[i] = i ;
        int u,v ;
        for(int i=0;i<m;i++)
        {
            cin>>u>>v ;
            unite(u,v,parent) ;
        }
        
        map<int,int> mp ;
        for(int i=1;i<=n;i++) mp[find(i,parent)]++ ;
        int res = 1 ;
        for(auto p: mp) res *= p.second , res %= mod ;
        cout<<mp.size()%mod<<" "<<res%mod<<endl ;
    }
}

// simple dfs

/*int dfs(int src, vector<int> adj[], bool vis[])
{
    vis[src] = true ;
    int cnt = 1 ;
    for(int x : adj[src])
    {
        if(!vis[x]) cnt += dfs(x,adj,vis) ;
    }
    
    return cnt ;
    
}

int32_t main()
{
    int t ; cin>>t ;
    while(t--)
    {
       int n,m ; cin>>n>>m ;
       vector<int> adj[n+1] ;
       int u,v ;
       for(int i=0;i<m;i++)
       {
           cin>>u>>v ;
           adj[u].push_back(v) ;
           adj[v].push_back(u) ;
       }
       bool vis[n+1] ;
       memset(vis,false,n+1) ;
       int conn = 0 ;
       int res = 1 ;
       for(int i=1;i<=n;i++)
       {
           if(!vis[i]) 
           {
               conn++ ;
               conn %= mod ;
               res *= dfs(i,adj,vis) ;
               res %= mod ;
           }
       }
       
       
       cout<<conn<<" "<<res<<endl ;
       
    }
}*/