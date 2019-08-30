# include<bits/stdc++.h>
using namespace std ;


/*int a[100][100] ;
int c ;

void algoy(int y,int n)
{
    int x = 0 ;
    while(x!=n && y!=-1)
    {
        a[x++][y--] = ++c ;
    }
}

void algox(int x,int n)
{
   int y = n-1 ;
   while(x!=n && y!=-1)
   { 
     a[x++][y--] = ++c ;
   }
}


int main()
{
    int t ; cin>>t ;
    while(t--)
    {
        c = 0 ;
        int n ; cin>>n ;
        
        for(int j=0;j<n;j++)
        {
          algoy(j,n);
        }
        

        for(int i=1;i<n;i++)
        {
          algox(i,n);
        }

        for(int i=0;i<n;i++)
        {    for(int j=0;j<n;j++)
                cout<<a[i][j]<<" " ;
            cout<<endl ;
        }


    }
}*/

int main()
{
    int t; cin>>t ;
    while(t--)
    {
        int n; cin>>n ;
        int a[n];
        for(int i=0;i<n;i++) cin>>a[i];
        int yb,mb,db ; cin>>yb>>mb>>db ;
        int yc,mc,dc ; cin>>yc>>mc>>dc ;
        int lday = a[n-1]+1 ;
        int y = yb ;
        int d = 1 ;
        if(y == yc)
        {
            if(y%4 == 0) a[n-1] = lday;
            if(mb == mc) d += (dc-db) ;
            else{
            for(int i=mb-1;i<mc;i++)
            {
                if(i == mc-1) d += dc;
                else if(i == mb-1) d += (a[i]-db);
                else
                    d += a[i] ;
            }
          }
        }
        else
        {
         while(y!=yc)
         {
           if(y%4 == 0) a[n-1]  = lday  ;
           if(y == yb)
           { 
            d += (a[mb-1]-db) ;
            for(int i=mb;i<n;i++)
            d += a[i] ;
           }
           
           else
            for(int i=0;i<n;i++) d += a[i] ;
           if(a[n-1] = lday) a[n-1] -= 1 ;
           y++ ;

           
         }

         if(yc%4 == 0) a[n-1] = lday ;
         for(int i=0;i<mc;i++)
         {
            if(i == mc-1) d += dc ;
            else
                d += a[i] ;
         }
        }

         cout<<d<<endl ;
        
    }

}

