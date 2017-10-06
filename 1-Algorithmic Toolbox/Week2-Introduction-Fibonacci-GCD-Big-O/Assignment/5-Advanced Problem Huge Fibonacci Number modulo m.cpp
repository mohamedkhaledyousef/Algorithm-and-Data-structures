#include <iostream>

using namespace std;

/*

??         0  1   2   3   4   5   6   7   8   9   10   11   12   13   14   15
????        0  1   1    2   3   5   8  13  21  34   55  89   144  233  377  610
???? mod 2  0  1   1    0   1   1   0   1   1   0   1   1     0   1    1    0
???? mod 3  0  1   1    2   0   2   2   1   0   1   1   2     0   2    2    1

Take a detailed look at this table. Do you see? Both these sequences are periodic! For ?? = 2, the period
is 011 and has length 3, while for ?? = 3 the period is 01120221 and has length 8. Therefore, to compute,
say, ??2015 mod 3 we just need to find the remainder of 2015 when divided by 8. Since 2015 = 251 · 8 + 7, we
conclude that ??2015 mod 3 = ??7 mod 3 = 1.
This is true in general: for any integer ?? ? 2, the sequence ???? mod ?? is periodic. The period always
starts with 01 and is known as Pisano period.



resources:
	 -http://www.maths.surrey.ac.uk/hosted-sites/R.Knott/Fibonacci/fibmaths.html
 	 -https://medium.com/competitive/huge-fibonacci-number-modulo-m-6b4926a5c836

*/

long long getPisanoPeriod(long long m)
{
    long long a=0, b=1, temp=a+b;
    for (int i=0; i<m*m ; ++i)
    {
        temp=(a+b)%m;
        a=b;
        b=temp;
        if (a==0 && b==1)
            return i+1;
    }
}

long long getFibonacciHuge(long long n, long long m)
{
    long long remainder = n % getPisanoPeriod(m);

    long long first=0;
    long long second=1;

    long long finalReminder=remainder;

    for (int i=1; i<remainder ; ++i)
    {
        finalReminder=(first+second) % m;
        first=second;
        second=finalReminder;
    }

    return finalReminder%m;

}

int main()
{
    long long n, m;
    cin >>n>>m;

    cout << getFibonacciHuge(n, m) <<endl;

    return 0;
}


