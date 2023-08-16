/******************************************************************************


                             Online C++ Compiler.
              Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.


*******************************************************************************/


#include <iostream>
#include <limits.h>
#include <queue>
#include <string.h>
using namespace std;

#define n 6

bool bfs(int rgraph[n][n],int s,int t,int parent[])
{
   
    int visited [n];
   memset(visited, 0, sizeof(visited));
  
   queue<int> q ;
   q.push(s);
   visited[s]=1;
   parent[s]=-1;
  
   while(!q.empty())
   {
       int u=q.front();
       q.pop();
      
       for(int v = 0;v < n;v++)
       {
           if (visited[v]==0 && rgraph[u][v]>0)
           {
               if(v == t)
               {
                   parent[v] = u;
                   return true;
               }
              
               q.push(v);
               parent[v] = u;
               visited[v] = 1;
               
           }
      }
   }
  
   return false;
}


int FordFulkerson(int G[n][n], int s,int t)
{
   int u,v;
   int rgraph[n][n];
  
   // copy G G into rgraph
   for (u = 0; u < n; u++)
          for (v = 0; v < n; v++)
           rgraph[u][v] = G[u][v];       


   int parent[n];
   int Max_flow = 0;
  
   //for finding Auxliary path
   while (bfs(rgraph, s, t, parent))
   {
       int pathflow = INT_MAX;
      
       // to find bottleneck
       for (v = t; v != s; v = parent[v])
       {
          u = parent[v];
          pathflow = min(pathflow, rgraph[u][v]);
       }
      
       //updation loop
        for (v = t; v != s; v = parent[v])
       {
          u = parent[v];
          rgraph[u][v] -= pathflow;
          rgraph[v][u] += pathflow;
       }
      
       Max_flow += pathflow;
   }
  
   return Max_flow;
}


int main()
{
   int G[n][n]
   = { { 0, 16, 13, 0, 0, 0 }, { 0, 0, 10, 12, 0, 0 },
			{ 0, 4, 0, 0, 14, 0 }, { 0, 0, 9, 0, 0, 20 },
			{ 0, 0, 0, 7, 0, 4 }, { 0, 0, 0, 0, 0, 0 } };
           
   cout<<"The Maximum flow of Graph G is : "<<FordFulkerson(G, 0, 5);

   return 0;
}





