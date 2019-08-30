// difficullt to think problem as graph
/*
this is just a dijkstra according to me(modified bfs)
*/

# include<bits/stdc++.h>
# define int long long
using namespace std ;
const int MAX = 2e4 ;

int dist[MAX] ;

int32_t main()
{
    int n,m; cin>>n>>m ;
    fill(dist,dist+MAX,INT_MAX) ;
    queue<int>  q ;
    q.push(n) ;
    dist[n] = 0 ;
    while(!q.empty())
    {
        int u = q.front() ;
        q.pop() ;
        if(u == m) break ;
        else if(u > m) 
        {
            if(dist[u-1] > dist[u]+1)
            {
                dist[u-1] = dist[u]+1 ;
                q.push(u-1) ;
            }
        }

        else
        {
            if(dist[u-1] > dist[u]+1)
            {
                dist[u-1] = dist[u]+1 ;
                q.push(u-1) ;
            }

            if(dist[2*u] > dist[u]+1)
            {
                dist[2*u] = dist[u]+1 ;
                q.push(2*u) ;
            }
        }
    }

    cout<<dist[m]<<endl ;
}