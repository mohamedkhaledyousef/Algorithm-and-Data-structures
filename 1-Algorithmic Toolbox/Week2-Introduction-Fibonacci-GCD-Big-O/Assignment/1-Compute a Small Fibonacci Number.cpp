/*
#include <iostream>

using namespace std;

int fib(int x) {
    if (x == 0)
        return 0;

    if (x == 1)
        return 1;

    return fib(x-1)+fib(x-2);
}

int main()
{
    int n;
    cin >>n;
    cout << fib(n) << endl;

    return 0;
}
*/

//-------------------------------------------------------------------------------------------------------------------------------------------------------
/*
#include<iostream>

using namespace std;

main()
{
   int n, c, first = 0, second = 1, next;

   cout << "Enter the number of terms of Fibonacci series you want" << endl;
   cin >> n;

   cout << "First " << n << " terms of Fibonacci series are :- " << endl;

   for ( c = 0 ; c < n ; c++ )
   {
      if ( c <= 1 )
         next = c;
      else
      {
         next = first + second;
         first = second;
         second = next;
      }
      cout << next << endl;
   }

   return 0;
}
*/

//------------------------------------------------------------------------------------------------------------------------------------------------------------
/*
-A simple method that is a direct recursive implementation mathematical recurrence relation given above.
-Time Complexity: T(n) = T(n-1) + T(n-2) which is exponential.
-We can observe that this implementation does a lot of repeated work (see the following recursion tree). So this is a bad implementation for nth Fibonacci number.

                         fib(5)
                     /             \
               fib(4)                fib(3)
             /      \                /     \
         fib(3)      fib(2)         fib(2)    fib(1)
        /     \        /    \       /    \
  fib(2)   fib(1)  fib(1) fib(0) fib(1) fib(0)
  /    \
fib(1) fib(0)
*/

/*
#include<iostream>

using namespace std;

long fib(int n)
    {
    if (n <= 1)
        return n;
    return
        fib(n-1) + fib(n-2);
    }

int main ()
    {
    int n;
    cin >>n;
    cout <<fib(n);

    return 0;
    }
*/

//For n = 9
//Output:34

//----------------------------------------------------------------------------------------------------------------------------------------
//Fibonacci Series using Dynamic Programming
//We can avoid the repeated work done is the method 1 by storing the Fibonacci numbers calculated so far.

#include<iostream>

using namespace std;

int fib(int n)
{
  /* Declare an array to store Fibonacci numbers. */
  int f[n+1];
  

  /* 0th and 1st number of the series are 0 and 1*/
  f[0] = 0;
  f[1] = 1;

  for (int i = 2; i <= n; i++)
  {
      /* Add the previous 2 numbers in the series
         and store it */
      f[i] = f[i-1] + f[i-2];
  }

  return f[n];
}

int main ()
    {
        int n;
        cin >>n;
        cout <<fib(n);

        return 0;
    }

//Time Complexity: O(n)
//Extra Space: O(n)
//-------------------------------------------------------------------------------------------------------------------------

