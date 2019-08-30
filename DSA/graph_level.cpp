# include<bits/stdc++.h>
# define pb push_back
using namespace std ;

int lvlcount[1000001] = {0} ;
int lvl[1000001] ;
bool vis[1000001] = {0} ;
vector<int> adj[1000001] ;

int main()
{
    int n ; cin>>n ;
    int m = n-1 ;
    while(m--)
    {
      int x,y ; cin>>x>>y ;
      adj[x].pb(y) ;
      adj[y].pb(x) ;
    }
    
    queue<int> q ; 
    int root = 1 ;
    lvl[root] = 1 ;
    lvlcount[root] = 1 ;
    q.push(root) ;
    vis[root] = 1 ;
    while(!q.empty())
    {
        int p = q.front() ;
        q.pop() ;
        int l = lvl[p]+1 ;
        //cout<<l<<" " ;
        for(int i=0;i<adj[p].size();i++)
        {
            if(vis[adj[p][i]] == 0)
            { 
              lvlcount[l]++ ;
              //cout<<lvlcount[l]<<" " ;
              q.push(adj[p][i]) ;
              vis[adj[p][i]] = 1 ;
              lvl[adj[p][i]] = l ;
            }
        } 
        //cout<<"\n"<<lvlcount[l]<<endl ;
        //cout<<endl ;

    }
    //cout<<endl ;
    int x ; cin>>x ;
    cout<<lvlcount[x]<<endl ;
}


