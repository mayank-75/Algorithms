/* little scepticle about why does this work without vis bool array
ya but this is similar to dijstra, as always a modified dijstra ,without 
actually creating an adjacency list*/

#include <bits/stdc++.h>
#define int long long
using namespace std;

bool isValid(int x, int y, int n)
{
    if(x>=0 && x<n && y>=0 && y<n) return true;
    return false ;
}

int dx[] = {0,1,-1,0} ;
int dy[] = {1,0,0,-1} ;

void dijkstra(vector<vector<int>> &v,vector<vector<int>> &dist, int n)
{
    multiset<pair<int,int>> ms ;
    ms.insert({0,0}) ;
    while(!ms.empty())
    {
        int x = ms.begin()->first , y = ms.begin()->second ;
        ms.erase(ms.begin());
        //if(vis[x][y]) continue ;
        //vis[x][y] = true ;
        for(int i=0;i<4;i++)
        {
            int x1 = x+dx[i], y1 = y+dy[i] ;
            if(isValid(x1,y1,n) && dist[x1][y1] > v[x1][y1]+dist[x][y])
            {
                dist[x1][y1] = v[x1][y1]+dist[x][y] ;
                ms.insert({x1,y1});
            }
        }
    }
}

int32_t main() {
	//code
	int t ; cin>>t ;
	while(t--)
	{
	    int n ; cin>>n ;
	    vector<vector<int>> v(n,vector<int>(n));
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<n;j++) cin>>v[i][j] ;
	    }
	    //vector<vector<bool>> vis(n,vector<bool>(n,false));
	    vector<vector<int>> dist(n,vector<int>(n,INT_MAX));
	    dist[0][0] = v[0][0] ;
	    dijkstra(v,dist,n);
	    cout<<dist[n-1][n-1]<<endl ;
	    
	    
	}
	return 0;
}