bool iscyclic(int src, vector<int> adj[], vector<bool> &vis, vector<bool> &backedge)
{
    vis[src] = true ;
    backedge[src] = true ;
    for(int i=0;i<adj[src].size();i++)
    {
        int n =  adj[src][i] ;
        if(!vis[n])
        {
            if(iscyclic(n,adj,vis,backedge)) return true ;
        }
        else if(backedge[n]) return true ;
    }
    backedge[src] = false ;
    return false ;
}

bool isCyclic(int V, vector<int> adj[])
{
    // Your code here
    vector<bool> vis(V,false) ;
    vector<bool> backedge(V,false) ;
    for(int i=0;i<V;i++)
    {
        if(!vis[i] && iscyclic(i,adj,vis,backedge)) return true ;
    }
    
    return false ;
    
}