# include<bits/stdc++.h>
# define int long long
# define siz 10001
# define pb push_back
using namespace std ;

/* program to find shortest distance to every node from multiple sources */

vector<pair<int, int>> v[siz];
bool vis[siz] ;
int dist[siz] ;
void dijkstra(int src[], int n, int t)
{
	for(int i=1;i<=n;i++)
	{
		vis[i] = false ;
		bool b = 0 ;
		for(int j=0;j<t;j++)
		{
			if(i==src[j]) dist[i] = 0, b = 1 ;
		}

		if(!b) dist[i] = INT_MAX ;
	}

	multiset<pair<int,int>> ms ;
	for(int i=0;i<t;i++) ms.insert({0,src[i]}) ;
	//vis[src] = true ;

	while(!ms.empty())
	{
		pair<int,int> p = *ms.begin() ;
        ms.erase(ms.begin()) ;
		int vertex = p.second ;
		int x = p.first ;
		//cout<<x<<" "<<vertex<<endl ;
        if(vis[vertex] == true) continue ;
		for(int i=0;i<v[vertex].size();i++)
		{
           int e = v[vertex][i].first ;
           int w = v[vertex][i].second ;

           if(dist[e] > x + w)
           { dist[e] = x + w ;
           	 ms.insert({dist[e],e}) ;
           }

		}

		vis[vertex] = true ;

	}
}

int32_t main()
{
   int n,m ; cin>>n>>m ;
   int t ; cin>>t ;
   int src[t] ;
   for(int i=0;i<t;i++) cin>>src[i] ;
   while(m--)
   {
   	 int a,b ; cin>>a>>b ;
   	 v[a].pb({b,1});
   	 v[b].pb({a,1});
   }

   dijkstra(src,n,t);
   cout<<endl ;
   for(int i=1;i<=n;i++)
   {
   	 cout<<i<<" "<<dist[i]<<endl ;
   }


}