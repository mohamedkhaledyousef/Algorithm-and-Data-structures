#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    long long n,x;
    cin>>n;

    vector<int> a;

    for(int i=0;i<n;i++)
    {
        cin>>x;
        a.push_back(x);
    }

    sort(a.begin(),a.end());

    if((a[0]*a[1])>(a[n-2]*a[n-1]))
        cout<<(a[0]*a[1]);
    else
        cout<<a[n-2]*a[n-1];


    return 0;
}
