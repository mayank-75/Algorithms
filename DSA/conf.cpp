# include<bits/stdc++.h>
using namespace std ;

void swapy(int *a, int *b)
{
	int t = *b ;
	*b = *a ;
	*a = t ;
}

int main()
{
	int a,b ; cin>>a>>b ;
	cout<<"values of a and b before swap : "<<a<<" "<<b<<endl ;
    swapy(&a,&b);
    cout<<"values of a and b after swap : "<<a<<" "<<b<<endl ;

}