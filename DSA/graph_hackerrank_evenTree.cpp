#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

int countNode(vector<int> adj[], bool vis[], int src,int dp[])
{
    vis[src] = true ;
    if(dp[src]!=-1) return dp[src] ;
    dp[src] = 1 ;
    for(int i=0;i<adj[src].size();i++)
    {
        int n = adj[src][i] ;
        if(!vis[n]) dp[src] += countNode(adj,vis,n,dp);
    }
    //cout<<dp[src]<<endl ;
    return dp[src] ;
}

// Complete the evenForest function below.
int evenForest(int nodes, int edges, vector<int> from, vector<int> to) {

    int dp[nodes+1] ;
    memset(dp,-1,sizeof(dp));
    vector<int> adj[nodes+1] ;
    bool vis[nodes+1] ;
    memset(vis,false,sizeof(vis));
    for(int i=0;i<edges;i++)
    {
        int x = from[i], y = to[i] ;
        //cout<<x<<" "<<y<<endl ;
        adj[x].push_back(y) ;
        adj[y].push_back(x) ;
    }

    countNode(adj,vis,1,dp) ;
    //for(int i=1;i<=nodes;i++) cout<<i<<"->"<<dp[i]<<endl ;
    memset(vis,false,sizeof(vis));
    int ans = 0 ;
    for(int i=1;i<=nodes;i++)
    {
        vis[i] = true ;
        
            for(int j=0;j<adj[i].size();j++)
            {
                int n = adj[i][j] ;
                if(!vis[n] && dp[n]%2 == 0) ans++ ;
            }
        
    }

    return ans ;
}
// bakwaas
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_nodes_edges_temp;
    getline(cin, t_nodes_edges_temp);

    vector<string> t_nodes_edges = split(rtrim(t_nodes_edges_temp));

    int t_nodes = stoi(t_nodes_edges[0]);
    int t_edges = stoi(t_nodes_edges[1]);

    vector<int> t_from(t_edges);
    vector<int> t_to(t_edges);

    for (int i = 0; i < t_edges; i++) {
        string t_from_to_temp;
        getline(cin, t_from_to_temp);

        vector<string> t_from_to = split(rtrim(t_from_to_temp));

        int t_from_temp = stoi(t_from_to[0]);
        int t_to_temp = stoi(t_from_to[1]);

        t_from[i] = t_from_temp;
        t_to[i] = t_to_temp;
    }

    int res = evenForest(t_nodes, t_edges, t_from, t_to);

    fout << res << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
