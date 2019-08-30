# include<bits/stdc++.h>
# define int long long
using namespace std ;


int32_t main()
{
	int n,m ; cin>>m>>n ;
	char a[n][m] ;
	pair<int,int> src, des ;
	bool b = 0 ;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
		  cin>>a[i][j] ;
		  if(a[i][j] == 'C')
		  {
		  	if(!b) src.first = i, src.second = j , b = 1 ;
		  	else des.first = i, des.second = j ;
		  } 	
		} 
	}

    int dist[n][m] ;
    for(int i=0;i<n;i++)
    {
    	for(int j=0;j<m;j++) dist[i][j] = 5 ;
    }
    dist[src.first][src.second] = 0 ;
    queue<pair<int,int>> q ;
    q.push({src.first,src.second}) ;
    while(!q.empty())
    {
    	int r = q.front().first , c = q.front().second ;
    	q.pop() ;
    	if(r == des.first && c == des.second) break ;
    	int x = r, y = c+1 ;
    	while(y< m && a[x][y]!='*')
    	{
    		if(dist[x][y] > dist[r][c] +1)
    		{
               dist[x][y] = dist[r][c]+1 ;
               q.push({x,y}) ;
    		}
    		y++ ;
    	}
    	y = c-1 ;
    	while(y>=0 && a[x][y]!='*')
    	{
    		if(dist[x][y] > dist[r][c]+1)
    		{
    			dist[x][y] = dist[r][c]+1 ;
    			q.push({x,y}) ;
    		}
    		y-- ;
    	}
        x = r+1 , y = c ;
    	while(x< n && a[x][y]!='*')
    	{
    		if(dist[x][y] > dist[r][c] +1)
    		{
               dist[x][y] = dist[r][c]+1 ;
               q.push({x,y}) ;
    		}
    		x++ ;
    	}
    	x = r-1 ;
    	while(x>= 0 && a[x][y]!='*')
    	{
    		if(dist[x][y] > dist[r][c] +1)
    		{
               dist[x][y] = dist[r][c]+1 ;
               q.push({x,y}) ;
    		}
    		x-- ;
    	}




    }

   /* for(int i=0;i<n;i++)
    {
    	for(int j=0;j<m;j++) cout<<dist[i][j]<<" " ;
    		cout<<endl ;
    } */

    cout<<dist[des.first][des.second]-1<<endl ;


}