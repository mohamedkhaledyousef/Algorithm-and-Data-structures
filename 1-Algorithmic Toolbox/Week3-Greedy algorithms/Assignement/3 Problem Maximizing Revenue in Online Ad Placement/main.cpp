
//correct code
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

long long dotProduct(vector<int> a, vector<int> b)
{
  long long sum= 0;

  sort(a.begin(), a.end());
  sort(b.begin(), b.end());

  for (size_t i =0; i<a.size(); ++i)
    {
        //sum += (long long)a[i] * b[a.size()-i-1];
        sum += (long long)a[i] * (long long)b[i];
    }
  return sum;
}

int main()
{
    /*
    if we did not use size_t ... wrong answer case 4
    size_t is data type like int but the stdlib.h and stddef.h header files define a data type called size_t which is used to represent the size of an object.
        -Library functions that take sizes expect them to be of type size_t, and the sizeof operator evaluates to size_t.
        -The actual type of size_t is platform-dependent; a common mistake is to assume size_t is the same as unsigned int, which can lead to programming errors, particularly as 64-bit architectures become more prevalent.
        -The size_t type may be bigger than, equal to, or smaller than an unsigned int, and your compiler might make assumptions about it for optimization.

    for more:
        -http://www.cplusplus.com/reference/cstring/size_t/
        -http://www.embedded.com/electronics-blogs/programming-pointers/4026076/Why-size-t-matters
        -http://stackoverflow.com/questions/1951519/when-should-i-use-stdsize-t

    */

    size_t n;
    cin >>n;

    vector <int> a(n);
    vector <int> b(n);

    for (size_t i=0; i<n ; ++i)
    {
        cin >>a[i];

    }

    for (size_t i=0; i<n ; ++i)
    {
        cin >>b[i];

    }

    //int result=dotProduct(a,b);
    cout <<dotProduct(a,b)<<endl;

    return 0;
}


//-----------------------------------------------------------------------------------------------------------

/LOL

/*

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int n,sum=0;
    cin >>n;

    vector <int> a (n);
    vector <int> b (n);
    vector <int> x (n);

    for (int i=0; i<n ; ++i)
    {
        cin >>a[i];

    }

    for (int i=0; i<n ; ++i)
    {
        cin >>b[i];

    }

    sort(a.begin(), a.end());


    //sort(a,a+n);
    //sort(b,b+n);

    sort(b.begin(), b.end());

    for (int i=0; i<n ; ++i)
    {
        x[i]=a[i]*b[i];

    }


    sum =0;
    for (int i=0; i<n ; ++i)
    {
        sum = sum + x[i];

    }

    cout <<sum <<endl;

    return 0;
}

*/
