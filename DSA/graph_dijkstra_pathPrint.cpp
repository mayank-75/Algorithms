// got to learn a new thing, how to print the shortest path 
// just need to maintain a parent of each node whose distance is 
// modified

# include<bits/stdc++.h>
# define int long long
using namespace std ;
const int MAX = 1e12+1 ;

void printPath(int x, int parent[])
{
    if(x == -1) return  ;
    printPath(parent[x],parent) ;
    cout<<x<<" " ;

}

int32_t main()
{
    int n,m ; cin>>n>>m ;
    vector<pair<int,int>> adj[n+1] ;
    int a,b,w ;
    for(int i=0;i<m;i++)
    {
        cin>>a>>b>>w ;
        adj[a].push_back({w,b}) ;
        adj[b].push_back({w,a}) ;
    }
    int dist[n+1] ;
    int parent[n+1] ;
    parent[1] = -1 ;
    fill(dist,dist+n+1,MAX) ;
    dist[1] = 0 ;
    multiset<pair<int,int>> ms ;
    ms.insert({0,1});
    vector<int>res ;
    while(!ms.empty())
    {
        int u = ms.begin()->second ;
        //cout<<u<<" " ;
        res.push_back(u) ;
        if(u == n) break ;
        ms.erase(ms.begin()) ;
        for(auto p : adj[u])
        {
            int v = p.second ;
            int e = p.first ;
            if(dist[v] > dist[u]+e)
            {
                dist[v] = dist[u]+e ;
                ms.insert({dist[v],v}) ;
                parent[v] = u ;
            }
        }
    }
    
    if(dist[n] == MAX) cout<<-1<<endl ;
    else 
    {
        printPath(n,parent) ;
        cout<<endl ;
    }
    
    
}