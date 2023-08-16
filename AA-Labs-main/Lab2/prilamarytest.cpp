/******************************************************************************

                          	Online C++ Compiler.
           	Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

unsigned long gcd(unsigned long a,unsigned long b)
{
  while(b!=0)
  {
 	unsigned long r=a%b;
  	a=b;
  	b=r;
  }
  return a;
}
int  power(unsigned long a,unsigned long n,unsigned long p)
{
	int res=1;
	a=a%p;
    
	while(n>0)
	{
    	if (n %2==1)
    	{
        	res=(res*a)%p;
    	}
    	n=n/2;
    	a=(a*a)%p;
	}
	return res;
}

bool isPrime(unsigned long n)
{
	int k=100;
	if (n==1 || n==4)
   	{
       	return false;
   	}
 
  else
  {
  	int k=100;
  	while(k>0)
   {
   	unsigned long a=2+rand()%(n-4);
  	 
   	if(gcd(n,a)!=1)
   	{
       	return false;
   	}
  	 
   	if(power(a,n-1,n)!=1)
   	{
       	return false;
   	}
   	k--;
   }
   return true;
  }
}
int main()
{
	unsigned long n;
	std::cout << "Enter The no.." << std::endl;
	std::cin >> n;
   if( isPrime(n)==1)
   {
   	cout<<"The no. is prime";
   }
   else
   {
   	cout<<"The no. is odd.";
   }
    

	return 0;
}
