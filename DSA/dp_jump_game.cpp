// O(N^2 sol)
int Solution::canJump(vector<int> &A) {
    
    int n = A.size() ;
    int dp[n] ;
    dp[n-1] = n-1 ;
    for(int i=n-2;i>=0;i--)
    {
        if(i+A[i] >=n-1){ dp[i] = n-1 ; continue ; }
        dp[i] = i+A[i] ;
        for(int j=i+1;j<=i+A[i];j++) 
        {
            if(dp[j] > dp[i]) dp[i] = dp[j] ;
        }
    }
    
    if(dp[0] == n-1) return 1 ;
    return 0 ;
    
    
}

//O(N) sol
int Solution::canJump(vector<int> &A) {
    
    int n = A.size() ;
    if (n<=1) return 1 ;
    int max_index = 0 ;
    for(int i=0;i<n;i++)
    {
        if(max_index <= i && A[i] == 0) return 0 ;
        if(max_index < A[i]+i) max_index = A[i]+i ;
    }
    
    if(max_index >= n-1) return 1 ;
    return 0 ;
    
}