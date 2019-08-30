/* very proud of myself could dp this question*/
/* got a lot of confidence :) , very good question :)*/
#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'cutTheTree' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY data
 *  2. 2D_INTEGER_ARRAY edges
 */

int nodeSum(int node, vector<int> adj[], vector<bool> &vis, vector<int>&data,vector<int> &dp)
{
   vis[node] = true ;
   if(dp[node]!=-1) return dp[node] ;
   dp[node] = data[node] ;
   for(int i=0;i<adj[node].size();i++)
   {
       int n = adj[node][i] ;
       if(!vis[n]) dp[node] += nodeSum(n,adj,vis,data,dp);
   }

   return dp[node] ;
}

int cutTheTree(vector<int> data, vector<vector<int>> edges) {

    int n = data.size() ;
    vector<int> adj[n];
    int m = edges.size() ;
    for(int i=0;i<m;i++)
    {
        int x = edges[i][0]-1, y = edges[i][1]-1 ;
        adj[x].push_back(y), adj[y].push_back(x) ;
    }
    vector<bool> vis(n,false) ;
    vector<int>  dp(n,-1) ;
    int ans = INT_MAX ;
    nodeSum(0,adj,vis,data,dp) ;
    for(int i=0;i<n;i++)
    {
        int sum1, sum2 ;
        for(int j=0;j<adj[i].size();j++)
        {
          sum1 = dp[adj[i][j]] ;
          sum2 = dp[0]-sum1 ;
          ans = min(ans,abs(sum1-sum2)) ;   
        }
    }

    return ans ;

   

}
// bakwaas
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string data_temp_temp;
    getline(cin, data_temp_temp);

    vector<string> data_temp = split(rtrim(data_temp_temp));

    vector<int> data(n);

    for (int i = 0; i < n; i++) {
        int data_item = stoi(data_temp[i]);

        data[i] = data_item;
    }

    vector<vector<int>> edges(n - 1);

    for (int i = 0; i < n - 1; i++) {
        edges[i].resize(2);

        string edges_row_temp_temp;
        getline(cin, edges_row_temp_temp);

        vector<string> edges_row_temp = split(rtrim(edges_row_temp_temp));

        for (int j = 0; j < 2; j++) {
            int edges_row_item = stoi(edges_row_temp[j]);

            edges[i][j] = edges_row_item;
        }
    }

    int result = cutTheTree(data, edges);

    fout << result << "\n";

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
