# include<bits/stdc++.h>
# define pb push_back
using namespace std ;

int lvlcount[1000001] ;
int lvl[1000001] ;
bool vis[1000001] ;
vector<int> adj[1000001] ;

void bfs(int s, int n, int t)
{
    for(int i=0;i<n;i++){ lvlcount[i] = 0 ; vis[i] = 0 ; lvl[i] = 0 ; }
    queue<int> q ; 
    lvl[s] = 0 ;
    lvlcount[s] = 1 ;
    q.push(s) ;
    vis[s] = 1 ;
    while(!q.empty())
    {
        int p = q.front() ;
        q.pop() ;
        int l = lvl[p]+1 ;
        //if(l > t) break ;
        //cout<<l<<" " ;
        for(int i=0;i<adj[p].size();i++)
        {
            if(vis[adj[p][i]] == 0)
            { 
              lvlcount[l]++ ;
              //cout<<lvlcount[l]<<" " ;
              q.push(adj[p][i]) ;
              cout<<adj[p][i]<<" " ;
              vis[adj[p][i]] = 1 ;
              lvl[adj[p][i]] = l ;
            }
        } 
        
        //cout<<endl ;
        
    }

    cout<<endl ;
}

int main()
{
    int n,m ; cin>>n>>m ;
    while(m--)
    {
      int x,y ; cin>>x>>y ;
      adj[x].pb(y) ;
      adj[y].pb(x) ;
    }

    for(int i=1;i<=n;i++)
    {
        cout<<i<<" " ;
        for(int a : adj[i]) cout<<a<<" " ;
        cout<<endl ;
    }


    
    int q ; cin>>q ;
    while(q--)
    {
        int s,t ; cin>>s>>t ;
        bfs(s,n,t) ;
        cout<<lvlcount[t]<<endl ;
        
    }
    
   
}


