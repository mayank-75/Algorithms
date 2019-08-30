void permutations(vector<vector<int>> &res, vector<int> &comb, int index, vector<int> &A)
{
    if(comb.size() == A.size()){ res.push_back(comb) ; return  ; }
    if(index >= A.size()) return  ;
    for(int i=0;i<A.size();i++)
    {
        if(comb.size() == 0) comb.push_back(A[i]) ;
        else if(find(comb.begin(),comb.end(),A[i])!=comb.end()) continue ;
        else comb.push_back(A[i]) ;
        permutations(res,comb,index+1,A) ;
        comb.pop_back() ;
    }
}


vector<vector<int> > Solution::permute(vector<int> &A) {
    
    vector<vector<int>> res ;
    vector<int> comb ;
    permutations(res,comb,0,A) ;
    return res ;
    
}