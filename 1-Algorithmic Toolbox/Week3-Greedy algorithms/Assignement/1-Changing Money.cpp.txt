#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >>n;

    int x1=n/10,                //28/10=2
        x2=(n%10)/5,            //8/5 = 1
        x3=(n%10)-(x2*5);       //8-5 = 3

    cout <<x1+x2+x3<<endl;

    return 0;
}




