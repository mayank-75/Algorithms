 // little tricky questionn on connected components
// best part is the way to link the nodes if their x or y coodinates are same

 # include<bits/stdc++.h>
using namespace std ;
# define int long long


void dfs(int src,vector<int> adj[], bool vis[])
{
    vis[src] = true ;
    for(int v : adj[src])
    {
        if(!vis[v]) dfs(v,adj,vis) ;
    }

}

int32_t main()
{
    int n;  cin>>n ;
    vector<int> adj[n] ;
    pair<int,int> v[n] ;
    for(int i=0;i<n;i++)
    {
        cin>>v[i].first>>v[i].second ;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(v[i].first == v[j].first || v[i].second == v[j].second) adj[i].push_back(j), adj[j].push_back(i) ;
        }
    }
    bool vis[n] ;
    memset(vis,false,n) ;
    int res = 0 ;
    for(int i=0;i<n;i++)
    {
        if(!vis[i]) res++ , dfs(i,adj,vis) ;
    }

    cout<<res-1<<endl ;

}