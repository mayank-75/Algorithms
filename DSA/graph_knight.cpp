// may want to refer this question, it teaches that there is no need to make a graph explicitly in questions

bool isValid(int x, int y,int n, int m)
{
    if(x >= 1 && x<=n && y>=1 && y<=m) return true ;
    return false ;
} 
 
int Solution::knight(int A, int B, int C, int D, int E, int F) {
    
    vector<vector<int>> v(A+1,vector<int>(B+1,-1)) ;
    v[C][D] = 0 ;
    queue<pair<int,int>> q ;
    q.push({C,D}) ;
    while(!q.empty())
    {
        int x = q.front().first, y = q.front().second ;
        q.pop() ;
        if(x == E && y == F) return v[x][y] ;
        // can apply a loop instead of writing againa and again
        if(isValid(x+2,y-1,A,B) && v[x+2][y-1] == -1) v[x+2][y-1] = v[x][y]+1 , q.push({x+2,y-1}) ;
        if(isValid(x+2,y+1,A,B) && v[x+2][y+1] == -1) v[x+2][y+1] = v[x][y]+1 , q.push({x+2,y+1}) ;
        if(isValid(x-2,y-1,A,B) && v[x-2][y-1] == -1) v[x-2][y-1] = v[x][y]+1 , q.push({x-2,y-1}) ;
        if(isValid(x-2,y+1,A,B) && v[x-2][y+1] == -1) v[x-2][y+1] = v[x][y]+1 , q.push({x-2,y+1}) ;
        if(isValid(x-1,y+2,A,B) && v[x-1][y+2] == -1) v[x-1][y+2] = v[x][y]+1 , q.push({x-1,y+2}) ;
        if(isValid(x+1,y+2,A,B) && v[x+1][y+2] == -1) v[x+1][y+2] = v[x][y]+1 , q.push({x+1,y+2}) ;
        if(isValid(x-1,y-2,A,B) && v[x-1][y-2] == -1) v[x-1][y-2] = v[x][y]+1 , q.push({x-1,y-2}) ;
        if(isValid(x+1,y-2,A,B) && v[x+1][y-2] == -1) v[x+1][y-2] = v[x][y]+1 , q.push({x+1,y-2}) ;
    }
    
    return -1 ;
    
    
    
}
