/*
least common multiple

-A common multiple is a number that is a multiple of two or more numbers.
-The common multiples of 3 and 4 are 0, 12, 24, ....
-The least common multiple (LCM) of two numbers is the smallest number (not zero) that is a multiple of both.
    for example
    Least Common Multiple of 3 and 5:
        -first we makes list the Multiples of each number,
            -The multiples of 3 are 3, 6, 9, 12, 15, 18, ... etc
            -The multiples of 5 are 5, 10, 15, 20, 25, ... etc
        -Find the first Common (same) value:
            -LCM of 3 and 5 is 15
            -so, 15 is a common multiple of 3 and 5, and is the smallest, or least, common multiple )

    example2:
        multiplies of 3:
            0 3 6 9 12 15 18 21 24 .....
        multiplies of 4:
            0 4 8 12 16 20 24 28 ...
         least common multiple or LCM  of 3 and 14 is 12 (NOT zero)
    example2:
        what is the least common multiple of 6 and 8
        multiplies of 6:
            0 6 12 18 24 30 36 42 48 ....
        multiplies of 8:
            0 8 16 24 32 40 48 56 64 ....
        least common multiple or LCM  of 6 and 8 is 24 (NOT zero)
        so LCM = 24
        WHAT about GCD ?
            6 => 1 2 3 6
            8 => 1 2 4 8
            so, GCD = 2
        so:
        a = 6 , b = 8
        LCM = 24
        GCD = 2

        WHAT we notice ?????
            24.2 = 6.8 = 48
        So we conclude that
            LCM(a,b)·GCD(a,b) = a·b.

-What To Do
    -Play with small data sets to find out how the least common multiple LCM(a,b) is related to the greatest common divisor GCD(a,b).
    -Do you see? For any two positive integers a and b,
        LCM(a,b)·GCD(a,b) = a·b.
        Prove this property and implement an algorithm for computing the least common multiple using your solution for the greatest common divisor.
    -so,   LCM(a,b) = a·b/GCD(a,b)


*/

//-----------------------------------------------------------------------------------------------------------
/*
#include <iostream>
using namespace std;

int main()
{
    long long n1, n2, max;

    cin >>n1>>n2;

    // maximum value between n1 and n2 is stored in max
    max = (n1 > n2) ? n1 : n2;

    do
    {
        if (max % n1 == 0 && max % n2 == 0)
        {
            cout << max;
            break;
        }
        else
            ++max;
    } while (true);

    return 0;
}
*/

//-----------------------------------------------------------------------------------------------------------

/*
//C++ Program to find HCF and LCM of two numbers


#include <iostream>
using namespace std;

int main()
{
    int a,b,c;
    cout <<"Enter two nos :"<<endl;
    cout <<endl;
    cout <<"Enter first no. : ";
    cin >>a;
    cout <<"Enter sec. no. : ";
    cin >>b;

    c=a*b;
    while(a!=b)
    {
        if(a>b)
        a=a-b;
        else
        b=b-a;
    }
    cout<< "HCF = " << a<<endl;
    cout<< "LCM = " << c/a<<endl;
    return 0;
}

*/

/*
//Find LCM using HCF

#include <iostream>
using namespace std;

int main()
{
    int n1, n2, hcf, temp, lcm;

    cout << "Enter two numbers: ";
    cin >> n1 >> n2;

    hcf = n1;
    temp = n2;

    while(hcf != temp)
    {
        if(hcf > temp)
            hcf -= temp;
        else
            temp -= hcf;
    }

    lcm = (n1 * n2) / hcf;

    cout << "LCM = " << lcm;
    return 0;
}

*/

//-----------------------------------------------------------------------------------------------------------

/*
//my idea

#include <iostream>
using namespace std;

int main()
{
    int a,b;
    cin >>a>>b;

    for (int i=0 ; ; i=i+a)
        {
        for (int j=0 ; ; j=j+b)
            {
                if (i==j)
                    cout <<i<<endl;
                    break;
            }
        }

    return 0;
}
*/

//-----------------------------------------------------------------------------------------------------------

//THE best solution
#include <iostream>
using namespace std;

int euclidGCD (long a, long b)
    {
        if (b == 0)
            return a;
        return euclidGCD(b, a%b);
    }

long long lcm(long long a, long long b)
    {
        return (a * b)/euclidGCD(a, b);
    }

int main()
{
    long long a, b;
    cin >>a>>b;
    cout <<lcm(a,b)<<endl;

    return 0;
}


