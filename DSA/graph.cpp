# include<bits/stdc++.h>
# define pb push_back
# define ll long long
using namespace std ;

char color[1000001] ;
int lvl[1000001] ;
int vis[1000001] ;
vector<int> adj[1000001] ;
bool magical[1000001] ;
void bfs(int s, int k)
{
  lvl[s] = 0 ;
  vis[s] = 1 ;
  queue<int> q ;
  q.push(s) ;
  while(!q.empty())
  {
  	int p = q.front() ;
  	q.pop() ;
  	for(int i=0;i<adj[p].size();i++)
  	{
  		int node = adj[p][i] ;
  		if(!vis[node])
  		{
  			lvl[node] = lvl[p]+1 ;
  			if(color[node] == 'w')
  			{
  				if(lvl[node]<=k) magical[s] = 1 ;
  				else magical[s] = 0 ;
  			}
  			vis[node] = 1 ;
  			q.push(node) ;
  		}
  	}
  }
}

vector<int> ans ;
int main()
{
	int t ; cin>>t ;
	while(t--)
	{
	  ans.clear() ;
	  int n,m,b,k ; cin>>n>>m>>b>>k ;
	  for(int i=1;i<=n;i++){ color[i] = 'w' ; magical[i] = 0 ; lvl[i] = 0 ; vis[i] = 0 ; adj[i].clear() ; }
	  while(m--)
	  {
		int x,y ; cin>>x>>y ;
		adj[x].pb(y) ;
		adj[y].pb(x) ;
	  }

	  while(b--)
	  {
		int c ; cin>>c ;
		color[c] = 'b' ;
	  }

	  for(int i=1;i<=n;i++)
	  {
	  	
        if(color[i] == 'b')
	  	{
	  	   for(int j=1;j<=n;j++)
	  	   {
	  		lvl[j] = 0 ; vis[j] = 0 ;
	  	   }

           bfs(i,k) ;
           //if(magical[i]) ans.pb(i) ;
	  	}
	  }

	  for(int i=1;i<=n;i++)
	  {
	  	if(magical[i]) ans.pb(magical[i]);
	  }
      
      if(ans.size() == 0)
      {
      	cout<<0<<endl ;
      }
      else
      {
	  cout<<ans.size()<<endl ;
	  sort(ans.begin(),ans.end()) ;
	  for(int x : ans)
	  	cout<<x<<" " ;
	  cout<<endl ; }

	}
}