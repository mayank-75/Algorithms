# include<bits/stdc++.h>
# define int long long
# define f first
# define s second
# define mp make_pair
# define pb push_back
# define siz 1000000
using namespace std ;

/* easier to implement than dijkstra */

vector<int> v[siz] ;
int dist[siz] ;

void bellmanford(int src, int n, int m)
{
	for(int i=1;i<=n;i++)
	{
		if(i!=src) dist[i] = INT_MAX ;
		else dist[i] = 0 ;
	}

	for(int i=0;i<n-1;i++)
	{
       for(int j=1;j<=m;j++)
       {
       	 if(dist[v[j][1]] > dist[v[j][0]] + v[j][2])
       	 	dist[v[j][1]] = dist[v[j][0]] + v[j][2] ;
       }
	}
  
}

int32_t main()
{
  int n,m ; cin>>n>>m ;
  for(int i=1;i<=m;i++) v[i].clear() ;
  for(int i=1;i<=m;i++)
  {
  	int from,to,wei ; cin>>from>>to>>wei ;
  	v[i].pb(from) ;
  	v[i].pb(to) ;
  	v[i].pb(wei) ;
  }

  int src ; cin>>src ;
  bellmanford(src,n,m) ;

  for(int i=1;i<=n;i++) 
  	cout<<dist[i]<<" " ;
  cout<<endl ;


}
