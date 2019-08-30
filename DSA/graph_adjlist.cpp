# include<bits/stdc++.h>
# define pb push_back
using namespace std ;



int main()
{
    int n,m; cin>>n>>m ;
    bool adj[n][n] ;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            adj[i][j] = false ;
    }

    while(m--)
    {
        int a,b ; cin>>a>>b ;
        adj[a][b] = true ;
        adj[b][a] = true ;
    }

    int q ; cin>>q ;
    while(q--)
    {
        int a,b ; cin>>a>>b ;
        if(adj[a][b]) cout<<"YES"<<endl ;
        else cout<<"NO"<<endl ;
    }
}

