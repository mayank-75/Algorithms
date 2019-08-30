# include<bits/stdc++.h>
# define pb push_back
using namespace std ;

vector<int> adj[1000001] ;
deque<int> dq ;
int vis[1000001] = {0} ;

void allpaths(int u, int v)
{
	vis[u] = 1 ;
	dq.push_back(u) ;
    //cout<<dq.size()<<" " ;
	for(int i=0;i<adj[u].size();i++)
	{
		int node = adj[u][i] ;
		if(vis[node] == 0) allpaths(node,v) ;
    }

    if(dq.back()==v)
    {
    	for(auto it = dq.begin();it!=dq.end();it++)
    		cout<<*it<<" " ;
    	cout<<endl ;
    }
    vis[dq.back()] = 0 ;
    dq.pop_back();

}

int main()
{
	/* input test case
	5 7
    2 1
    2 4
    2 3
    1 5
    1 3
    4 3
    4 5
    2 3
    */
    int n,m ; cin>>n>>m ;
    while(m--)
    {
      int x,y ; cin>>x>>y ;
      adj[x].pb(y) ;
    }

    for(int i=1;i<=n;i++)
    {
        cout<<i<<" " ;
        for(int a : adj[i]) cout<<a<<" " ;
        cout<<endl ;
    }

    int u,v ; cin>>u>>v ;
    allpaths(u,v) ;
    //cout<<endl ;
    
    
    
   
}