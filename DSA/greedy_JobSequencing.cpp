// really a good problem, teaches how to use slots to distribute task to attain max profit
# include<bits/stdc++.h>
using namespace std;

struct job
{
  int id,dead,profit ;  
};

bool comp(job a, job b)
{
    return a.profit > b.profit ;
}

int main() {
  //code
  int t ; cin>>t ;
  while(t--)
  {
      int n ; cin>>n ;
      job Job[n] ;
      for(int i=0;i<n;i++)
      {
          cin>>Job[i].id>>Job[i].dead>>Job[i].profit ;
      }
      bool slot[n] ;
      memset(slot,false,sizeof(slot)) ;
      int total_profit = 0 , num_jobs = 0 ;
      sort(Job,Job+n,comp) ;
      for(int i=0;i<n;i++)
      {
          for(int j=min(n,Job[i].dead)-1;j>=0;j--)
          {
              if(!slot[j])
              {
                  slot[j] = true ;
                  total_profit += Job[i].profit ;
                  num_jobs += 1 ;
                  break ;
              }
          }
      }
      
      cout<<num_jobs<<" "<<total_profit<<endl ;
  }
  return 0;
}