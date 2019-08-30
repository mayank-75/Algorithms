# include<bits/stdc++.h>
# define int long long
using namespace std ;
const int MAX = INT_MAX ;


struct edge
{
	int  u, v, w ;
};

bool compare(edge e1, edge e2)
{
	return e1.w < e2.w ;
}

int find(int x, int parent[])
{
	if(parent[x] == x) return x ;
	return find(parent[x],parent);
}



int32_t main()
{
	int n,m ; cin>>n>>m ;
	vector<edge> Edge(m) ;
	for(int i=0;i<m;i++)
	{
		cin>>Edge[i].u>>Edge[i].v>>Edge[i].w ;
	}

	int parent[n+1] ;
	for(int i=1;i<=n;i++) parent[i] = i ;
    sort(Edge.begin(),Edge.end(),compare) ;
    /*for(auto e : Edge)
    {
    	cout<<e.u<<" "<<e.v<<" "<<e.w<<endl ;
    }*/
    //cout<<endl ;
	int res = 0 ;
    for(int i=0;i<m;i++)
    {
    	int x = Edge[i].u , y = Edge[i].v ;
    	int p_x = find(x,parent);
    	int p_y = find(y,parent) ;
    	if(p_x != p_y)
    	{
    		res += Edge[i].w ;
    		//cout<<x<<" "<<y<<" "<<Edge[i].w<<endl ;
    		//we can make any one anyone's parent
    		// parent[p_x] = p_y is also valid
    		parent[p_y] = p_x ;
    	}
    }

    cout<<res<<endl ;

}