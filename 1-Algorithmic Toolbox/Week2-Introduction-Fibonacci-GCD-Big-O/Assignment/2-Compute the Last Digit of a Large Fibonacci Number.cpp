/*
Problem Introduction
	-Your goal in this problem is to find the last digit of ??-th Fibonacci number. 
	-Recall that Fibonacci numbers grow exponentially fast. 
	-For example:
		??200 = 280 571 172 992 510 140 037 611 932 413 038 677 189 525 .
	-Therefore, a solution like
		??[0] ? 0
		??[1] ? 1
		for ?? from 2 to ??:
		??[??] ? ??[?? ? 1] + ??[?? ? 2]
		print(??[??] mod 10)

		-will turn out to be too slow, 
		-because as ?? grows the ??th iteration of the loop computes the sum of longer and longer numbers. 
		-Also, for example, 
			??1000 does not fit into the standard C++ int type. 
		-To overcome this difficulty, you may want to store in ??[??] not the ??th Fibonacci number itself, 
			but just its last digit (thatis, ???? mod 10). 
		-Computing the last digit of ???? is easy: it is just the last digit of the sum of the last digits of?????1 and ?????2:
				??[??] ? (??[?? ? 1] + ??[?? ? 2]) mod 10
		-This way, all ??[??]’s are just digits, so they fit perfectly into any standard integer type, and computing a sum of ??[?? ? 1] and ??[?? ? 2] is performed very quickly.

*/

//----------------------------------------------------------------------------------------------------------

/*
-the last digit of the nth Fibonacci number F(n) (that is, F(n) mod 10).
-For example,
    the 200th Fibonacci number equals 280571172992510140037611932413038677189525 and last digit is 5
-Therefore, a solution like
    F[0]=0
    F[1]=1
    for i=2 to n:
        F[i]=F[i-1]+F[i-2]
    print(F[n] mod 10)

    -will turn out to be too slow,
    -because as i grows the ith iteration of the loop computes the sum of longer and longer numbers.
    -Also, for example, F(1000) does not fit into the standard C++ int type.

-To overcome this difficulty,
    -you may want to store in F[i] not the ith Fibonacci number itself,
    -but just its last digit (that is, F(i) mod 10).
    -Computing the last digit of F(i) is easy:
        it is just the last digit of the sum of the last digits of F(i?1) and F(i?2)
            F[i]=(F[i-1]+F[i-2]) mod 10
    -this performed very quickly.
*/

#include <iostream>

using namespace std;
int fibLastDigit(long long n)
{
    int first = 0;
    int second = 1;

    int res;

    for (int i = 2; i <= n; ++i)
        {
        res = (first + second) % 10;
        first = second;
        second = res;
        }

    return res;
}

int main()
{
    int n;
    cin >> n;

    int c = fibLastDigit(n);

    cout << c <<endl;

    return 0;
}
