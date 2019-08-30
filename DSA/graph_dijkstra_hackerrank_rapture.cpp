/* got me lot of time to solve this question, it is a difficult question, but not once you
understand how to modify dijkstra and apply it, good ques for revision*/

#include <bits/stdc++.h>
# define int long long
using namespace std;

void dijkstra(vector<pair<int,int>> adj[], bool vis[], int dist[])
{
    multiset<pair<int,int>> ms ;
    ms.insert({0,1});
    while(!ms.empty())
    {
        int cum = ms.begin()->first ;
        int node = ms.begin()->second ;
        ms.erase(ms.begin());
        if(vis[node]) continue ;
        vis[node] = true ;
        for(int i=0;i<adj[node].size();i++)
        {
            int n = adj[node][i].second ;
            int cost = adj[node][i].first ;
            if(cost > cum)
            {
                if(dist[n] > cost) dist[n] = cost , ms.insert({dist[n],n});
            }

            else if(dist[n] > cum) dist[n] = cum, ms.insert({dist[n],n});
        }
    }
}

void getCost(int nodes, vector<int> from, vector<int> to, vector<int> wei) {
    // Print your answer within the function and return nothing
    vector<pair<int,int>> adj[nodes+1] ;
    int m = from.size() ;
    for(int i=0;i<m;i++)
    {
        adj[from[i]].push_back({wei[i],to[i]});
        adj[to[i]].push_back({wei[i],from[i]}) ;
    }

    bool vis[nodes+1] ;
    memset(vis,false,sizeof(vis)) ;
    int dist[nodes+1] ;
    for(int i=1;i<=nodes;i++) dist[i] = INT_MAX ;
    dist[1] = 0 ;
    dijkstra(adj,vis,dist) ;
    if(dist[nodes] == INT_MAX) cout<< "NO PATH EXISTS" <<endl ;
    else cout<<dist[nodes]<<endl ;


}

int32_t main()
{
    int n,m ; cin>>n>>m ;
    vector<int> from(m), to(m), wei(m) ;
    for(int i=0;i<m;i++) cin>>from[i]>>to[i]>>wei[i] ;
    getCost(n,from,to,wei);
}
