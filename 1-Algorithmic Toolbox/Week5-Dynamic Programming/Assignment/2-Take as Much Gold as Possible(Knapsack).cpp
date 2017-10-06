#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maximumWeight(int w,const vector <int> &vec)
{
    vector <int> newVec(w+1);

    for (size_t i=0; i<vec.size() ;++i)
        for (int j=w; j-vec[i]>=0 ;--j)
            {
                newVec[j] = max(newVec[j] , newVec[j-vec[i]] + vec[i]);

            }

    return newVec[w];
}

int main()
{
    int w,n;
    cin >>w>>n;

    vector <int> vec(n);

    for(int i=0 ; i<n ; ++i)
        {
        cin>>vec[i];

        }

    cout <<maximumWeight(w,vec)<<endl;

   return 0;
}
