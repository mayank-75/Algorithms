bool comp(vector<int> v1, vector<int> v2)
{
    for(int i=0;i<min(v1.size(),v2.size());i++)
    {
        if(v1[i]==v2[i]) continue ;
        else return v1[i] < v2[i] ;
    }
    
    return v1.size() < v2.size() ;
}


void combination(vector<int> &comb, vector<vector<int>> &res, vector<int> &v, int index, int B)
{
    if(B == 0){  
        
        vector<int> copy(comb) ;
        sort(copy.begin(),copy.end());
        res.push_back(copy) ; return ; 
    }
        
    if(index >= v.size()|| B < 0) return ;
    combination(comb,res,v,index+1,B);
    comb.push_back(v[index]) ;
    combination(comb,res,v,index,B-v[index]) ;
    comb.pop_back() ;
}


vector<vector<int> > Solution::combinationSum(vector<int> &A, int B) {
    
    vector<vector<int>> res ;
    vector<int> comb ;
    combination(comb,res,A,0,B);
    sort(res.begin(),res.end(),comp) ;
    vector<vector<int>> ans ;
    for(auto v : res)
    {
        if(ans.size()!=0 && ans.back()!=v) ans.push_back(v) ;
        else if(ans.size() == 0) ans.push_back(v) ;
    }
    
    return ans ;
}
