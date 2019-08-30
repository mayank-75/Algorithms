/* maza aa gya sawal krke :)) */

# include<bits/stdc++.h>
# define int long long
using namespace std ;

bool isCyclic(vector<vector<int>> &adj, bool vis[], bool st[], int src, vector<int> &res)
{
    vis[src] = true ;
    st[src] = true ;
    for(int i=0;i<adj[src].size();i++)
    {
        int n = adj[src][i] ;
        if(!vis[n] && isCyclic(adj,vis,st,n,res)) return true ;
        else if(st[n]) return true ;
    }
    
    if(find(res.begin(),res.end(),src) == res.end()) res.push_back(src) ;
    st[src] = false ;
    return false ;
}

vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    
    int n = graph.size() ;
    bool vis[n], st[n] ;
    memset(vis,false,sizeof(vis)) ;
    memset(st,false,sizeof(st)) ;
    vector<int> res ;
    bool b = false ;
    for(int i=0;i<n;i++)
    {
        if(!vis[i]) b = isCyclic(graph,vis,st,i,res) ;
    }
    
    return res ;
    
    
    
}


int32_t main()
{
  int n,m ; cin>>n>>m ;
  vector<vector<int>> adj(n) ;
  int x,y ; 
  while(m--)
  {
  	cin>>x>>y ; adj[x].push_back(y) ;
  }

  for(int i=0;i<n;i++)
  {
  	cout<<i<<":" ;
  	for(int x : adj[i]) cout<<x<<" " ;
  		cout<<endl ;
  }

  vector<int> res = eventualSafeNodes(adj) ;

  for(int x : res) cout<<x<<" " ;
  	cout<<endl ;





}