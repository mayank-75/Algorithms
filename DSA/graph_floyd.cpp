# include<bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t ; cin>>t ;
	while(t--)
	{
	    int n ; cin>>n ;
	    int v[n+1][n+1] ;
	    for(int i=1;i<=n;i++)
	    {
	        for(int j=1;j<=n;j++)
	        {
	            cin>>v[i][j] ;
	        }
	    }
	    
	    for(int k=1;k<=n;k++)
	    {
	        for(int i=1;i<=n;i++)
	        {
	            for(int j=1;j<=n;j++)
	            {
	                v[i][j] = min(v[i][j], v[i][k]+v[k][j]) ;
	            }
	        }
	    }
	    
	    for(int i=1;i<=n;i++)
	    {
	        for(int j=1;j<=n;j++) 
	        {
	            if(v[i][j] == 10000000) cout<<"INF"<<" " ;
	            else cout<<v[i][j]<<" " ;
	        }
	        cout<<endl ;
	    }
	}
	return 0;
}