// this is a must revisit question, teaches how in binary values
// base 2 can be used to finnd the lca of a binary tree
// I just loved the solution

/* approach-
- remove  the leading zeros form the binary representation of a numbers 
whose distnce has to be found out.
- then lca is the size of binary number until which both are same
- could have never thought of this on my own, uhh hard to digest also:)
*/

# include<bits/stdc++.h>
# define int long long
using namespace std ;

int32_t main()
{
    int n; cin>>n ;
    while(n--)
    {
      int i,j ; cin>>i>>j ;
      vector<int> bin_i, bin_j ;
      while(i)
      {
          bin_i.push_back(i%2) ;
          i  /= 2 ;
          
      }
      
      while(j)
      {
          bin_j.push_back(j%2) ;
          j /= 2 ;
      }
      
      reverse(bin_i.begin(),bin_i.end()) ;
      reverse(bin_j.begin(),bin_j.end()) ;
      int c = 0 ;
      for(int x=0;x<min(bin_i.size(),bin_j.size());x++)
      {
          if(bin_i[x] == bin_j[x]) c++ ;
          else break ;
      }
      
      cout<<(bin_i.size()+bin_j.size()-2*c)<<endl ;
      
    }
     
}