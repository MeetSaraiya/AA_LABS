#include <iostream>
#include<string>
using namespace std;

void Native (string T, string P)
{
  int N = T.length ();
  int M = P.length ();

  for (int i = 0; i <= N - M; i++)
    {	
        int j ;/* For current index i, check for pattern match */
        for (j = 0; j < M; j++)
         {
	        if (T[i + j] != P[j])
	        break;
	     }
	     if (j == M) // if P[0...M-1] = T[i, i+1, ...i+M-1]
             printf("Pattern found at index/shift %d \n", i);
    }
}

  int main ()
  {
    string T,P;
    cout<<"Enter Text";
    getline(cin, T);

    cout<<"Enter Patten";
    cin>>P;
    Native(T,P);
    return 0;
  }
