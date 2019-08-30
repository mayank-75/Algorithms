# include<bits/stdc++.h>
using namespace std ;

bool isValid(vector<vector<int>> v, int x, int y, int n)
{
	if(x>=0 && x<n && y>=0 && y<n && v[x][y]!=0) return true ;
	return false ;
}

bool bfs(vector<vector<int>> adj, int src, int des, vector<bool> &vis)
{
   queue<int> q ;
   q.push(src) ;
   while(!q.empty())
   {
   	  int node = q.front() ;

   	  q.pop() ;
   	  vis[node] = 1 ;
   	  for(int i=0;i<adj[node].size();i++)
   	  {
   	  	 int n = adj[node][i] ;
   	  	 if(n == des) return true ;
   	  	 if(!vis[n]) q.push(n) ;
   	  }

   }

   return false ;
}

int main()
{
	int t ; cin>>t ;
	while(t--)
	{
		int n ; cin>>n ;
		vector<vector<int>> v(n,vector<int>(n));
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				cin>>v[i][j] ;
			}
		}
        int src, des ;
		vector<vector<int>> adj(n*n,vector<int>()) ;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(isValid(v,i,j,n) && v[i][j] == 1) src = i*n+j ;

				if(isValid(v,i,j,n) && v[i][j] == 2) des = i*n+j ;

				if(isValid(v,i-1,j,n)) adj[i*n+j].push_back((i-1)*n+j);

				if(isValid(v,i+1,j,n)) adj[i*n+j].push_back((i+1)*n+j);

				if(isValid(v,i,j-1,n)) adj[i*n+j].push_back(i*n+(j-1));

				if(isValid(v,i,j+1,n)) adj[i*n+j].push_back(i*n+(j+1));


			}
		}

		vector<bool> vis(n*n,0) ;
		if(bfs(adj,src,des,vis)) cout<<1<<endl ;
		else cout<<0<<endl  ;

	}
}