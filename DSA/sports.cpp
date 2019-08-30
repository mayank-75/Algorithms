# include<bits/stdc++.h>
# define ld long double
using namespace std ;

int func(int n, ld m)
{
	if((int)m != ceil(m)) return 0 ;
	if(m == 0) return n ;
	return func(n+1,(6*(m-n))/7);
}

int main()
{
	ld m = 2 ;
    int n ;
     while(m++)
     {
        if(func(0,m)!=0){ n = func(0,m) ; break; }
     } 

     cout<<m<<" "<<n<<endl ;
}