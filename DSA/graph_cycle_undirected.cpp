bool iscyclic(vector<int> adj[],int parent, vector<bool> &vis, int src)
{
    vis[src] = true ;
    for(int i=0;i<adj[src].size();i++)
    {
        int n = adj[src][i] ;
        if(!vis[n])
        {
            if(iscyclic(adj,src,vis,n)) return true ;
        }
        else if(n!=parent) return true ;
    }
    
    return false ;
}

bool isCyclic(vector<int> adj[], int V)
{
   // Your code here
   vector<bool> vis(V,false) ;
   for(int i=0;i<V;i++)
   {
       if(!vis[i] && iscyclic(adj,-1,vis,i)) return true ;
   }
   
   return false ;
   
   
}