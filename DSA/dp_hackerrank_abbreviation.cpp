#include <bits/stdc++.h>

using namespace std;

// Complete the abbreviation function below.
bool isPossible(string a, string b, int i, int j)
{
    if(b.size() > a.size()) return false ;
    if(b.size() == 0)
    {
        if(a.size() >0)
        {
            for(char c : a)
            {
                if(c<'A' && c>'Z') return false ;
            }
            return true ;
        }
        return true ;
    }
    cout<<a[i]<<" "<<b[j]<<endl ;
    if(a[i] == b[j] || a[i]-32 == b[j])
    {
        a.erase(a.begin()+i), b.erase(b.begin()+j);
        return isPossible(a,b,i,j);
    }
    if(a[i]>='A' && a[i]<='Z') return isPossible(a,b,i+1,j);
    a.erase(a.begin()+i) ;
    return isPossible(a,b,i,j);
    
}

string abbreviation(string a, string b) {

   if(isPossible(a,b,0,0)) return "YES" ;
   else return "NO" ;
}

int main()
{
    int t ; cin>>t ;
    while(t--)
    {
        string a , b ; cin>>a>>b ;
        cout<<abbreviation(a,b)<<endl ;
    }
}
