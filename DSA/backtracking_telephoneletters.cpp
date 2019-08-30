//function to store all the possible combination of letters  when phone number is pressed.

void combination(vector<string> &res, string comb, vector<string>map, string A, int index)
{
    if(comb.size() == A.size()){ res.push_back(comb) ; return ; }
    if(index >= A.size()) return  ;
    string s = map[A[index]-'0'] ;
    for(int i=0;i<s.size();i++)
    {
        comb.push_back(s[i]) ;
        combination(res,comb,map,A,index+1) ;
        comb.pop_back() ;
    }
    
}


vector<string> Solution::letterCombinations(string A) {
    
    vector<string> map = {"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
    string comb ;
    vector<string> res ;
    combination(res,comb,map,A,0) ;

    return res ;    
    
}