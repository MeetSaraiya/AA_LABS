/*****************************************************************************

                          	Online C++ Compiler.
           	Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
const int n=4;

int karger(int G[n][n],int n)
{
   
	int u = rand() % n;
	int v = rand() % n;
	int G1 [n][n];

	for(int i=0;i<n-1;i++)
	{
    	for(int j=i+1;j<n;j++)
    	{
        	int cnt=0;
        	if(i==u && j==v)
        	{
            	G1[i][j]=0;
        	}

        	else if(i==u || i==v)
        	{
            	if (G[u][j]>0)
            	{
                	cnt++;
            	}
            	if(G[v][j]>0)
            	{
                	cnt++;
            	}
           	 
            	// Updatioin of upper triangle Values ...
            	if(u<j)
            	{
                	G1[u][j]=cnt;
            	}
            	else
            	{
                	G1[j][u]=cnt;
            	}
            	if(v<j)
            	{
                	G1[v][j]=cnt;
            	}
            	else
            	{
                	G1[j][v]=cnt;
            	}
        	}

        	else if(j==u || j==v)
        	{
            	if (G[u][i]>0)
            	{
                	cnt++;
            	}
            	if(G[v][i]>0)
            	{
                	cnt++;
            	}
           	 
            	// Updatioin of upper triangle Values ...
            	if(u<i)
            	{
                	G1[u][i]=cnt;
            	}
            	else
            	{
                	G1[i][u]=cnt;
            	}
            	if(v<i)
            	{
                	G1[v][i]=cnt;
            	}
            	else
            	{
                	G1[i][v]=cnt;
            	}           	 

        	}

        	else
        	{
            	G1[i][j]==G[i][j];
        	}
    	}
	}

	for(int i=1;i<n;i++)
	{
    	for(int j=1;j<n;j++)
    	{
        	if(i>=j)
        	{
            	G1[i][j]=G1[j][i];
        	}
    	}
	}

	int x=n-1;
	int G2[x][x];
	int a=0,b=0;
	for(int i=0;i<n;i++)
	{
    	if (i==v) continue;
    	b=0;
    	for(int j=0;j<n;j++)
    	{
        	if (j==v) continue;
        	else
        	//if(i!=v and j!=v)
        	{
            	G2[a][b]=G1[i][j];
            	b++;
        	}
    	}
    	a++;
	}
	// for(int i =0;i<x;i++)
	// {
	// 	for(int j=0;j<x;j++)
	// 	{
	//   	//cout<<G2[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }
	for(int i=0;i<x;i++)
	{
    	for(int j=0;j<x;j++)
    	{
      	G[i][j]=G2[i][j];
    	}
	}

	if(n>2)
	{
    	n=n-1;
    	karger(G,n);
	}
  return G[0][1];
    

}

int main()
{
	int G[4][4]={{0,1,1,1},
           	{1,0,1,0},
           	{1,1,0,1},
           	{1,0,1,0}};
	int m=karger(G,4);
	cout<<"MIN CUT value is: "<<m<<endl;
	return 0;
}


