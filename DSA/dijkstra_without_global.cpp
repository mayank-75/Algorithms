// no need for vis for dijkstra

int main()
{
    int n,m ; cin>>n>>m ;
    vector<pair<int,int>> adj[n+1] ;
    int a,b,w ;
    while(m--)
    {
        cin>>a>>b>>w ;
        adj[a].push_back({b,w}) ;
    }
    vector<int> dist(n+1,INT_MAX) ;
    vector<bool> vis(n+1,false) ;
    multiset<pair<int,int>> ms ;
    ms.insert({0,1});
    dist[1] = 0 ;
    while(!ms.empty())
    {
        int w = ms.begin()->first ;
        int node = ms.begin()->second ;
        ms.erase(ms.begin()) ;
        if(vis[node]) continue ;
        vis[node] = true ;
        for(int i=0;i<adj[node].size();i++)
        {
            int n = adj[node][i].first ;
            int e = adj[node][i].second ;
            if(dist[n] > w+e) dist[n] = w+e , ms.insert({dist[n],n}) ;
        }
        
    }
    
    
    for(int i=2;i<dist.size();i++) cout<<dist[i]<<" " ;
    cout<<endl ;
    
}