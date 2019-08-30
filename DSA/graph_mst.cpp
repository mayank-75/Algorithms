# include<bits/stdc++.h>
# define  int long long
# define pb push_back
# define siz 10001
using namespace std ;

vector<pair<int,int>> adj[siz] ;
bool vis[siz] ;

int prims(int s)
{
  int mincost = 0 ;
  multiset<pair<int,int>> ms ;
  ms.insert({0,s}) ;

  while(!ms.empty())
  {
  	 pair<int,int> p = *ms.begin() ;
  	 ms.erase(ms.begin());
  	 int w = p.first ;
  	 int x = p.second ;
  	 if(vis[x] == true) continue ;
     mincost += w ;
  	 vis[x] = true ;

  	 for(int i=0;i<adj[x].size();i++)
  	 {
  	 	if(!vis[adj[x][i].second])
  	 	{
  	 		ms.insert(adj[x][i]) ;
  	 	}
  	 }
  }

  return mincost ;
}

int32_t main()
{
	int n,e ; cin>>n>>e ;
	int mincost ;
	for(int i=0;i<e;i++)
	{
       int x,y,w ; cin>>x>>y>>w ;
       adj[x].pb({w,y}) ;
       adj[y].pb({w,x}) ;
	}

	mincost = prims(1) ;

	cout<<mincost<<endl ;
}

/*#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <utility>

using namespace std;
const int MAX = 1e4 + 5;
typedef pair<long long, int> PII;
bool marked[MAX];
vector <PII> adj[MAX];

long long prim(int x)
{
    priority_queue<PII, vector<PII>, greater<PII> > Q;
    int y;
    long long minimumCost = 0;
    PII p;
    Q.push(make_pair(0, x));
    while(!Q.empty())
    {
        // Select the edge with minimum weight
        p = Q.top();
        Q.pop();
        x = p.second;
        // Checking for cycle
        if(marked[x] == true)
            continue;
        minimumCost += p.first;
        marked[x] = true;
        for(int i = 0;i < adj[x].size();++i)
        {
            y = adj[x][i].second;
            if(marked[y] == false)
                Q.push(adj[x][i]);
        }
    }
    return minimumCost;
}

int main()
{
    int nodes, edges, x, y;
    long long weight, minimumCost;
    cin >> nodes >> edges;
    for(int i = 0;i < edges;++i)
    {
        cin >> x >> y >> weight;
        adj[x].push_back(make_pair(weight, y));
        adj[y].push_back(make_pair(weight, x));
    }
    // Selecting 1 as the starting node
    minimumCost = prim(1);
    cout << minimumCost << endl;
    return 0;
}*/