/*The function takes an adjacency matrix representation of the graph (g)
and an integer(v) denoting the no of vertices as its arguments.
You are required to complete below method */

/*this is a wrong approach for bipartite
may be the test cases were weak so it worked
*/

// dfs has to be done instead of looping all the nodes
// if else are conditions are correct and just need to be put in a dfs call
bool isBipartite(int A[][MAX],int V)
{
     //Your code here
     int color[V] ;
     memset(color,-1,sizeof(color)) ;
     for(int i=0;i<V;i++)
     {
         for(int j=0;j<V;j++)
         {
             
             if(i!=j && A[i][j]==1) 
             {
                 if(color[i] == -1 && color[j] == -1) color[i] = 1, color[j] = 0 ;
                 else if(color[i]!=-1 && color[j] == -1) color[j] = !color[i] ;
                 else if(color[j]!=-1 && color[i] == -1) color[i] = !color[j] ;
                 else if(color[i] == color[j]) return 0 ;
            
             }
             
             else if(i == j && A[i][j] == 1) return 0 ;
         }
     }
     
     return 1 ;
     
     
}