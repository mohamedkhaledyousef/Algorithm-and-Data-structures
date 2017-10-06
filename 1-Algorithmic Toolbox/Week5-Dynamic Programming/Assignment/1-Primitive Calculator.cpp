//the accepted code

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <int> optimal(int n)     //takes vector with size n and return vector
{
    vector <int> vec;      //the return vector
    vector <int> newVec(n+1);

    for (int i=1; i<newVec.size() ; ++i)
    {
        newVec[i]=newVec[i-1]+ 1 ;
        if(i%2==0)
            newVec[i]= min(1+newVec[i/2],newVec[i]);
        if(i%3==0)
            newVec[i]= min(1+newVec[i/3],newVec[i]);

    }
    int i=n;

    while(i>1)
    {
        vec.push_back(i);
        //5 4 2 1
        //5 4 3 2 1


        if (newVec[i-1] == newVec[i]-1)
			i=i-1;
		else if (i%2==0 && (newVec[i/2] == newVec[i]-1))
			i=i/2;
		else if (i%3==0 && (newVec[i/3] == newVec[i]-1))
			i=i/3;


        /*
        if (n%2==0 && n/2<n-1 || n%3==0 && n-1>n/3 || n-1>n/2 || n-1>n/3)
            {
            n = n-1;
            }

        //12
        else if (n%2==0 && n/2>n/3 || n%3==0 && n/2>n/3)
            {
            n = n/2;
            }
        */

    }

    vec.push_back(1);
    reverse(vec.begin(),vec.end());

    return vec;

}

int main()
{
    int n;
    cin >>n;

    vector <int> vec = optimal(n);

    cout<< vec.size()-1<<endl;

    for(int i=0 ; i<vec.size() ; ++i)
        {
        cout<<vec[i]<<" ";

        }

    return 0;
}

//-----------------------------------------------------------------------------------------------------------

//failed test case #4

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <int> optimal(int n)     //takes vector with size n and return vector
{
    vector <int> vec;      //the return vector

    while(n>=1)
    {
        vec.push_back(n);

        if (n==10)
            {
            n = n-1;
            }

        else if (n%3==0)
            {
            n = n/3;
            }
        else if (n%2==0)
            {
            n = n/2;
            }

        else
            {
            n = n-1;
            }

    }

    reverse(vec.begin(),vec.end());

    return vec;

}

int main()
{
    int n;
    cin >>n;

    vector <int> vec = optimal(n);

    cout<< vec.size()-1<<endl;

    for(int i=0 ; i<vec.size() ; ++i)
        {
        cout<<vec[i]<<" ";

        }

    return 0;
}

//------------------------------------------------------------

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <int> optimal(int n)     //takes vector with size n and return vector
{
    vector <int> vec;      //the return vector

    while(n>=1)
    {
        vec.push_back(n);

        if (n%3==0)
            {
            n = n/3;
            }
        else if (n%2==0)
            {
            n = n/2;
            }
        else
            {
            n = n-1;
            }

    }

    reverse(vec.begin(),vec.end());

    return vec;

}

int main()
{
    int n;
    cin >>n;

    vector <int> vec = optimal(n);

    cout<< vec.size()-1<<endl;

    for(int i=0 ; i<vec.size() ; ++i)
        {
        cout<<vec[i]<<" ";

        }

    return 0;
}


//---------------------------------------------------------------------------------------


/*
first solution

Failed case #3/16: (Wrong answer)
got: 15 expected: 14
Input:
96234

Your output:
15
1 2 4 5 10 11 22 66 198 594 1782 5346 16038 16039 32078 96234
Correct output:
14
1 3 9 10 11 22 66 198 594 1782 5346 16038 16039 32078 96234
 (Time used: 0.00/1.50, memory used: 9375744/536870912.)

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n,counts=0;
    cin >>n;

    vector <int> vec(counts);

    while(n>=1)
    {
        vec.push_back(n);

        if (n%3==0)
            {
            counts++;
            n = n/3;
            }
        else if (n%2==0)
            {
            counts++;
            n = n/2;
            }
        else
            {
            counts++;
            n = n-1;
            }

    }

    cout<< counts-1<<endl;

    reverse(vec.begin(),vec.end());
    //vector <int> vecc(counts) = reverse(vec.begin(),vec.end());

    for(int i=0 ; i<counts ; ++i)
        {
        cout<<vec[i]<<" ";

        }

    return 0;
}
