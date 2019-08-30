/* In this question it is not mandatory to climb ladder
if we want so, mark the nodes have ladder and snake starting point*/
# include<bits/stdc++.h>
using namespace std;


int main() {
	//code
	int t ; cin>>t ;
	while(t--)
	{
	    int n ; cin>>n ;
	    vector<pair<int,int>> adj[31] ;
	    int a,b ;
	    while(n--)
	    {
	        cin>>a>>b ;
	        adj[a].push_back({0,b}) ;
	    }
	    for(int i=1;i<=30;i++)
	    {
	        for(int j=1;j<=6;j++)
	        {
	            if(i+j <= 30) adj[i].push_back({1,i+j}) ;
	        }
	    }
	    
	    vector<int> dist(31,INT_MAX) ;
	    dist[1] = 0 ;
	    vector<bool> vis(31,false) ;
	    multiset<pair<int,int>> ms ;
	    ms.insert({0,1}) ;
	    while(!ms.empty())
	    {
	        int w = ms.begin()->first ;
	        int node = ms.begin()->second ;
	        ms.erase(ms.begin()) ;
	        if(vis[node]) continue ;
	        vis[node] = true ;
	        for(int i=0;i<adj[node].size();i++)
	        {
	            int e = adj[node][i].first ;
	            int n = adj[node][i].second ;
	            
	            if(dist[n] > e+w)
	            {
	                dist[n] = e+w ;
	                ms.insert({dist[n],n}) ;
	            }
	        }
	    }
	    
	    cout<<dist[30]<<endl ;
	    
	}
	return 0;
}