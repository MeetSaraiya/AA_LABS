// Online C++ compiler to run C++ program online
#include <iostream>

using namespace std;



int Random(int p,int r)
{
srand(time(NULL));

    
    	int j=p+rand()%(r-p+1);
    	return j;
   	 
	}

int Part(int A[],int p,int r)
{
	int x=A[r];
	int i=p-1;
	int j;
    
	for(j=p;j<=r-1;j++)
	{
    	if (A[j]<=x)
    	{
        	i=i+1;
        	int temp=A[i];
        	A[i]=A[j];
        	A[j]=temp;
    	}
	}
	int t=A[i+1];
	A[i+1]=A[r];
	A[r]=t;
	return i+1;
}

int RP(int A[],int p,int r)
{
	int i=Random(p,r);
	int temp=A[i];
	A[i]=A[r];
	A[r]=temp;
    
	return Part(A,p,r);
}

 void RQ(int A[],int p,int r)
{
	if (p<r)
	{
    	int q=RP(A,p,r);
    	RQ(A,p,q-1);
    	RQ(A,q+1,r);
	}
}

void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout<<arr[i]<<" ";
}

int main() {
	// Write C++ code here
	int A[]={23,32,65,86,12,56,78,26,38,07};
	RQ(A,0,10);
   printf("Sorted array: \n");
    printArray(A, 10);
	return 0;
}
