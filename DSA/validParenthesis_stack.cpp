# include<bits/stc++.h>
using namespace std ;








int main()
{
   string s ; cin>>s ;
   stack<char> st ;
   for(int i=0;i<n;i++)
   {
     if(s[i] == '(' || s[i] == '[' || s[i] == '{'){ st.push(s[i]) ; }
     
     if(s[i] == ')' || s[i] == ']' || s[i] == '}')
     {
        char front  = st.top() ;
        st.pop() ;
        string correct = front + s[i] ;
        if(correct == "()" || s[i] == "[]" || s[i] == "{}"){ continue ; }
        else { cout<<i+1<<endl ; break ;}
     }
     else { cout<<
   }
}
