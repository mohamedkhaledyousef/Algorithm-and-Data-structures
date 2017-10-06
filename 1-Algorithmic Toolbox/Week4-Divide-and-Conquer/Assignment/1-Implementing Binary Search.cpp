/*
idea:

input
    5 1 5 8 12 13
    5 8 1 23 1 11
Output
    2 0 -1 0 -1
Explanation:
    In this sample,
    we are given an increasing sequence a[0]= 1, a[1] = 5, a[2]= 8, a[3]= 12, a[4]= 13 of length five
    and five keys to search: 8, 1, 23, 1, 11.
    We see that a[2]= 8 and a[0]= 1, but the keys 23 and 11 do not appear in the sequence a For this reason, we output a sequence 2, 0,?1, 0,?1.

Hint
    Samples:
    n = 5; a = [1, 5, 8, 12, 13]
    >>> binary_search(a, 8)
    2
    >>> binary_search(a, 1)
    0
    >>> binary_search(a, 23)
    -1
    >>> binary_search(a, 1)
    0
    >>> binary_search(a, 11)
    -1

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int binarySearch(const vector<int> &a, int x)
{
  int low=0, high=(int)a.size()-1;

  while(low<=high)
    {
	  int mid=low+(high-low)/2;
	  if (x==a[mid])
		  return mid;
	  else if (x<a[mid])
		  high=mid-1;
	  else
		  low=mid+1;
  }
  return -1;
}

/*
int linearSearch(const vector<int> &a, int x) {
  for (size_t i = 0; i < a.size(); ++i)
  {
    if (a[i] == x)
        return i;
  }
  return -1;
}
*/

int main()
{
  int n,k;
  cin >>n;
  vector<int> VecA(n);
  for (int i=0; i<VecA.size() ;i++)
    {
    cin >>VecA[i];
    }

  cin >>k;
  vector<int> vecB(k);
  for (int i=0; i<k ;++i)
    {
    cin >>vecB[i];
    }

  sort(VecA.begin(), VecA.end());

  for (int i=0; i<k ;++i)
    {
    //replace with the call to binary_search when implemented
       cout << binarySearch(VecA, vecB[i]) <<" ";
    //here we send the name of array that we searching on it and the array that will return the values
    }

    return 0;

}

//-----------------------------------------------------------------------------------------------------------

/*
//my first idea is bad
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n,k;

    vector <int> vecA(n);
    vector <int> vecB(k);
    vector <int> indexes(k);

    cin >>n;
    for(int i=0; i<n ;++i)
    {
        cin >>vecA[i];

    }

    int j;
    cin >>k;
    for(j=0; j<k ;++j)
    {
        cin >>vecB[j];

    }

    int index;
    for(int i=0; i<k ;++i)
    {
        //if ()
          //  index = -1;
        if (vecB[j]=vecA[i])
            index = i;


    }



    for(int i=0; i<k ;++i)
    {
        cout <<indexes[index] <<" ";

    }

    return 0;
}

*/



