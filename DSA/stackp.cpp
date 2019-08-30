# include<bits/stdc++.h>
# define ll long long
using namespace std ;

struct specialstack
{
	stack<ll> st ;
	stack<ll> temp ;
	void push(int x)
	{
      if(temp.empty()) temp.push(x) ;
      else
      {
      	if(x < temp.top()) temp.push(x) ;
      }

      st.push(x) ;
	}

	void pop()
	{
		if(!st.empty())
		{
			if(!temp.empty())
			{
				if(temp.top() == st.top()) temp.pop() ; 
			}

			st.pop() ;
		}
    }

	int getmin()
	{
      return temp.top() ;
	}
};


int main()
{
	specialstack s ;
	s.push(10) ;
	s.push(20) ;
	s.push(30) ;
	cout<<s.getmin()<<endl ;
	s.push(5) ;
	cout<<s.getmin()<<endl ;


}


/*void reverstack(stack<ll> s)
{
   if(s.empty()) return ;
   ll x = s.top();
   s.pop() ;
   reverstack(s) ;
   cout<<x<<" " ;
}

int main()
{
  stack<ll> s ;
  s.push(11) , s.push(0) , s.push(4) , s.push(2), s.push(5) ;

  reverstack(s);
  cout<<endl ;
}*/

