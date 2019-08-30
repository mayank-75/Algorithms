// uff took a huge amount of time, not an easy to think
// even the implementation is not very easy

// just see the editorial:P

# include<bits/stdc++.h>
# define int long long
using namespace std ;

bool isSamecolor(int src, int parent, int colour, vector<int> adj[], int color[])
{
   if(color[src] != colour) return false ;
   if(adj)
   for(int x : adj[src])
   {
     if(x!=parent)
     {
        if(!isSamecolor(x,src,colour,adj,color)) return false ;
     }
   }

   return true ;
}

bool solve(int src,vector<int> adj[], int color[])
{
    for(int x : adj[src])
    {
        int colour = color[x] ;
        if(!isSamecolor(x,src,colour,adj,color)) return false; 
    }

    return true ;
}

int32_t main()
{
    int n;  cin>>n ;
    vector<int> adj[n] ;
    int color[n] ;
    int u,v ;
    for(int i=0;i<n-1;i++)
    {
        cin>>u>>v ;
        adj[u-1].push_back(v-1) ;
        adj[v-1].push_back(u-1) ;
    }

    for(int i=0;i<n;i++) cin>>color[i] ;
    int root1 = -1 , root2 = -1 ;
    bool b = 0 ;
    for(int i=0;i<n;i++)
    {
        for(int v : adj[i])
        {
            if(color[i]!=color[v])
            {
               root1 = i, root2 = v ;
               b = 1 ;
               break  ;
            }
        }

        if(b) break ;
    }
    //cout<<root1+1<<" "<<root2+1<<endl ;
    if(root1 == -1)
    {
        cout<<"YES"<<endl ;
        cout<<1<<endl ;
    }
    else if(solve(root1,adj,color)) 
        {
            cout<<"YES"<<endl ;
            cout<<root1+1<<endl ;
        }
    else if(solve(root2,adj,color)) 
        {
            cout<<"YES"<<endl ;
            cout<<root2+1<<endl ;
        }
    else cout<<"NO"<<endl ;



}