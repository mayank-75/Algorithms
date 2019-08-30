//code for calucalting all the palindomic partitioning in a string

bool comp(vector<string> v1, vector<string> v2)
{
    for(int i=0;i<min(v1.size(),v2.size());i++)
    {
        if(v1[i].size()!=v2[i].size()) return v1[i].size() < v2[i].size() ;
    }
    
    return v1.size() < v2.size() ;
}

bool isPalindrome(int i, int j,string s)
{
    while(i<j)
    {
        if(s[i]!=s[j]) return false ;
        i++, j-- ;
    }
    
    return true ;
}

void combination(vector<vector<string>> &res, vector<string> &comb, int index, string A)
{
    if(index >= A.size()) 
    {
        res.push_back(comb) ; return ;
    }
    
    for(int i=index;i<A.size();i++)
    {
        if(isPalindrome(index,i,A))
        {
            comb.push_back(A.substr(index,i-index+1)) ;
            combination(res,comb,i+1,A) ;
            comb.pop_back() ;
        }
    }
}



vector<vector<string> > Solution::partition(string A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<vector<string>> res ;
    vector<string> comb ;
    combination(res,comb,0,A);
    sort(res.begin(),res.end(),comp) ;
    return res ;

}
