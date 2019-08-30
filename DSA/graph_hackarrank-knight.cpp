#include <bits/stdc++.h>

using namespace std;

// Complete the knightlOnAChessboard function below.

bool isValid(int x, int y, int n)
{
    if(x >=0 && x<n && y>=0 && y<n) return true ;
    return false ;
}

int minMoves(int n, int a, int b)
{
    int dx[] = {a,a,-a,-a,b,b,-b,-b} ;
    int dy[] = {b,-b,b,-b,a,-a,a,-a} ;
    queue<pair<int,int>> q ;
    q.push({0,0});
    vector<vector<int>> move(n,vector<int>(n,-1)) ;
    move[0][0] = 0 ;
    while(!q.empty())
    {
        int x = q.front().first ;
        int y = q.front().second ;
        if(x == n-1 &&  y == n-1) break ;
        q.pop() ;
        for(int i=0;i<8;i++)
        {
           if(isValid(x+dx[i],y+dy[i],n) && move[x+dx[i]][y+dy[i]]==-1)
           {
               move[x+dx[i]][y+dy[i]] = 1+move[x][y] ; 
               q.push({x+dx[i],y+dy[i]}) ;
           }
        }
    }

    return move[n-1][n-1] ;
}


vector<vector<int>> knightlOnAChessboard(int n) {

   vector<vector<int>> ans ;
   for(int i=1;i<=n-1;i++)
   {
       vector<int> temp ;
       for(int j=1;j<=n-1;j++)
       {
           temp.push_back(minMoves(n,i,j)) ;
       }
       ans.push_back(temp) ;
   }

   return ans ;
}
// igonre this
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<vector<int>> result = knightlOnAChessboard(n);

    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            fout << result[i][j];

            if (j != result[i].size() - 1) {
                fout << " ";
            }
        }

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}
