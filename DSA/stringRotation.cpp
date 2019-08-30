#include <iostream>
using namespace std;

string acw(string s)
{
    int n = s.size() ;
    char temp = s[n-1] ;
    for(int i=n-2;i>=0;i--)
    {
        s[i+1] = s[i] ;
    }
    
    s[0] = temp ;
    
    return s ;
    
}

string cw(string s)
{
    int n = s.size() ;
    char temp = s[0] ;
    for(int i=0;i<n-1;i++)
    {
        s[i] = s[i+1] ;
    }
    
    s[n-1] = temp ; 
    
    return s ;

}

int main() {
  //code
  int t ; cin>>t ;
  while(t--)
  {
    string a,b ; cin>>a>>b ;
    string temp1 = a, temp2 = a ;
    temp1 = acw(temp1), temp1 = acw(temp1) ;
    cout<<temp1<<endl ;
    temp2 = cw(temp2) , temp2 = cw(temp2) ;
    cout<<temp2<<endl ;
    if(temp1 == b || temp2 == b) cout<<1<<endl ;
    else cout<<0<<endl ;
  }
  return 0;
}