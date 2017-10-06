/*

Hints:
    read: http://www.geeksforgeeks.org/majority-element/
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int getMajority(vector<int> &a, int left, int right)
 {
  if (left == right)
    return -1;
  if (left + 1 == right)
    return a[left];

  sort(a.begin(), a.end());

  int count = 1;
  int element = -1;
  for(int i = 0; i < a.size(); i++)
    {
	  if(a[i] == element)
        {
		  count++;
        }
	  else
        {
		  element = a[i];
		  count = 1;
        }

	  if(count > a.size()/2)
		  return 1;
    }

  return -1;

}

int main()
{
    int n;
    cin >>n;
    vector<int> vecA(n);
    for (int i=0 ;i<vecA.size(); ++i)
        {
        cin >>vecA[i];
        }

    cout <<(getMajority(vecA, 0, vecA.size()) != -1) << endl;

    return 0;
}

//-----------------------------------------------------------------------------------------------------------

/*
//my first code ..wrong answer test 6/21
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  int n;
  cin >>n;
  vector<int> VecA(n);
  for (int i=0; i<VecA.size() ;i++)
    {
    cin >>VecA[i];
    }

  sort(VecA.begin(), VecA.end());

  int i,counts=1;
  for (i=0; i<VecA.size() ;++i)
    {
        if (VecA[i] ==VecA[i+1] )
            counts++;

    }
    int mid = VecA.size()/2;
    if (counts > mid )
        cout<<"1"<<endl;
    else
        cout<<"0"<<endl;

    return 0;

}
*/









