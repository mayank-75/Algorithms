# include<bits/stdc++.h>
# define int long long
using namespace std ;

int32_t main()
{
	int t ; cin>>t ;
	for(int T=1;T<=t;T++)
	{
		int n,m ; cin>>n>>m ;
		vector<int> adj[n+1] ;
		int color[n+1] ;
		memset(color,-1,sizeof(color)) ;
		int x,y ;
		while(m--)
		{
			cin>>x>>y ;
			adj[y].push_back(x) ;
			adj[x].push_back(y) ;
		}
		//cout<<endl ;
        bool b = 1 ;
		for(int i=1;i<=n;i++)
		{
			for(int v : adj[i])
			{
				if(color[i] == -1 && color[v] == -1)
				{
					color[i] = 0, color[v] = !color[i] ;
				}

				else if(color[i] == -1) color[i] = !color[v] ;
				else if(color[v] == -1) color[v] = !color[i] ;
				else if(color[i] == color[v]){ b = 0 ; break ;}
			}
		}

        cout<<"Scenario #"<<T<<":"<<endl ;
		if(!b) cout<<"Suspicious bugs found!"<<endl ;
		else cout<<"No suspicious bugs found!"<<endl ;


	}
}