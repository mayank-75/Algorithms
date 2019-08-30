//Given a string of character, find the length of longest proper prefix which is also a proper suffix.
//proper prefix is one that does not contain whole string.

#include <bits/stdc++.h>
using namespace std;

vector<int>  lps(string pat)
{
    int len = 0 , i = 1 ;
    int n = pat.size() ;
    vector<int> arr(n) ;
    arr[0] = 0 ;
    while(i < n)
    {
        if(pat[i] == pat[len])
        {
            len++, arr[i] = len ;
            i++ ;
        }
        
        else if(len > 0)
        {
            len = arr[len-1] ;
        }
        
        else if(len == 0)
        {
            arr[i] = 0 ;
            i++ ;
        }
    }
    /*for(int x : arr) cout<<x<<" " ;
    cout<<endl ;*/
    return arr ;
    
}

int main() {
	//code
	int t ; cin>>t ;
	while(t--)
	{
	    string s ; cin>>s ;
	    vector<int> res = lps(s) ;
	    cout<<res[res.size()-1]<<endl ;
	    
	}
	return 0;
}