// a silly mistake took a hell lot of time phew!!

# include<bits/stdc++.h>
# define int long long
# define pi pair<int,int>
using namespace std ;

struct Edge
{
	int u,v,w; 
};

bool compare(pair<Edge,int> e1, pair<Edge,int> e2)
{
	return e1.first.w < e2.first.w ;
}

int find(int x, int par[])
{
	if(par[x] == x) return x ;
	else return find(par[x],par) ;
}

int32_t main()
{
	int t ; cin>>t ;
	while(t--)
	{
		int n,m,q ; cin>>n>>m>>q ;
        pair<Edge,int> e[m] ;
        int a,b,c ;
		for(int i=0;i<m;i++)
		{
		  cin>>a>>b>>c ;
          e[i].first.u = a, e[i].first.v = b, e[i].first.w = c ;
          e[i].second = i+1 ;
        }
		sort(e,e+m,compare) ;
        int par[n+1] ;
        for(int i=1;i<=n;i++) par[i] = i ;
        int time = 0 ;
		int timeStamp[n] ;
		for(auto p : e)
		{
		   auto edge = p.first ;
           int x = edge.u,  y = edge.v ;
           int p_x = find(x,par), p_y = find(y,par) ;
           if(p_x != p_y)
           {
           	 time++ , timeStamp[time] = p.second ; 
           	 
           	 par[p_y] = p_x ;
           	 //cout<<x<<" "<<y<<" "<<edge.w<<" "<<time<<endl ;
           } 
           
		}

	    int T ; 
	    while(q--)
	    {
	    	cin>>T ;
	    	cout<<timeStamp[T]<<endl ;
	    }



	}
}