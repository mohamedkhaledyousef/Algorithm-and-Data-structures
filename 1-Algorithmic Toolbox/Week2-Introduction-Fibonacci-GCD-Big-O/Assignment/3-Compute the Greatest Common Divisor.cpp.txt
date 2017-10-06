#include <iostream>
using namespace std;

// Function to return gcd of a and b
int gcd(int a, int b)
    {
    if (b == 0)
        return a;
    return gcd(b, a%b);
    }

/*
or we can write the function like that
int gcd(int a, int b)
    {
    if (a == 0)
        return b;
    return gcd(b%a, a);
    }

*/

// Driver program to test above function
int main()
{
    int a,b;
    cin >>a>>b;

    cout <<gcd(a,b);

    return 0;
}

/*
NOTES:
    -Time Complexity: O(Log min(a, b))
    -Search about: Extended Euclidean Algorithm: 
    http://www.geeksforgeeks.org/basic-and-extended-euclidean-algorithms/

*/
