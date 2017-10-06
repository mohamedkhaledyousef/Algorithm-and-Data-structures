//Accepted code

#include <iostream>
#include <vector>

using namespace std;

long long mergeSort(vector<int> &arr, vector<int> &adds, size_t left, size_t m, size_t right)
{
	    size_t i=left , j=m , k=left;

        long long counts = 0;

        while (i<=m-1 && j<=right)
            {
            if (arr[i]<=arr[j])
                {
                    adds[k]=arr[i];
                    i++;
                    k++;
                }
            else
                {
                    adds[k]=arr[j];
                    counts+=m-i;
                    j++;
                    k++;
                }
            }

        while (i<=m-1)
            {
                adds[k] = arr[i];
                i++;
                k++;
            }

        while (j <= right)
            {
            adds[k] = arr[j];
            j++;
            k++;
            }

		for (i=left; i <= right; i++)
			arr[i] = adds[i];

        return counts;
}

long long inversions(vector<int> &arr, vector<int> &adds, size_t left, size_t right)
{
    long long numberOfInversions=0;

    if (right<=left)
        return numberOfInversions;

    size_t m=left+(right-left) / 2;

    numberOfInversions += inversions(arr, adds, left, m);
    numberOfInversions += inversions(arr, adds, m+1, right);
    numberOfInversions += mergeSort(arr, adds, left, m+1, right);

    return numberOfInversions;
}

int main()
{
    int n;
    cin >>n;

    vector<int> arr(n);
    for (size_t i = 0; i < arr.size(); i++)
        {
            cin >>arr[i];
        }

    vector<int> adds(arr.size());

    cout<< inversions(arr, adds, 0, arr.size()-1)<<endl;

    return 0;

}

//---------------------------------------------------------------------------------

#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

int main()
{
    int n;
    cin >> n;       //5
    //scanf("%d",&n)

    vector<int> arr(n);
    for (size_t i=0 ;i<arr.size(); ++i)
        {
            //scanf("%d",&arr[i])
            cin >>arr[i];
        }

    int j=0,counts=0;
    for (size_t i=j+1 ;i<arr.size(); ++i)
        {
            if (arr[i] <= arr[j])
                {
                    swap(arr[i],arr[j+1]);
                    counts++;
                    j=i-1;
                }

        }

    cout <<counts<<endl;

    //2 3 9 2 9     counter = 0
    //j     i
    //2 2 9 3 9     counter = 1
    //    j i
    //2 2 3 9 9     counter = 2

    //-----------------------------------

    //5 3 9 2 9     counter = 0
    //j i

    //swap
    //3 5 9 2 9     counter = 1
    //j i

    //3 5 9 2 9     counter = 1
    //  j i

    //3 5 9 2 9     counter = 1
    //  j   i

    //swap
    //3 2 9 5 9     counter = 2
    //    j i

    //swap
    //3 2 5 9 9     counter = 3
    //    j i
    //this algorithm result ends with counter = 3 and this is false ,counter=4 the correct

    //3 2 5 9 9     counter = 3
    //j i

    //swap
    //2 3 5 9 9     counter = 4
    //j i

    //2 3 5 9 9
    //-------------------------------------------------------
    //this is the optimal
    //another algorithm is comparing with the smallest value in the array
    //5 3 9 2 9     counter = 0
    //j i

    //5 3 9 2 9     counter = 0
    //j     i

    //swap
    //2 3 9 5 9     counter = 1
    //j     i

    //2 3 9 5 9     counter = 1
    //  j i

    //2 3 9 5 9     counter = 1
    //    j i

    //swap
    //2 3 5 9 9     counter = 2


    //------------------------------------------------------------
    //9 8 7 3 2 1   counter = 0

    //8 9 7 3 2 1   counter = 1

    //8 7 9 3 2 1   counter = 2

    //8 7 3 9 2 1   counter = 3

    //8 7 3 2 9 1   counter = 4

    //8 7 3 2 1 9   counter = 5
    //here's my first algorithm stop and this is false
    //now 9 is the largest number in the array

    //7 8 3 2 1 9   counter = 6

    //7 8 2 3 1 9   counter = 7

    //7 8 2 1 3 9   counter = 8

    //7 8 1 2 3 9   counter = 9

    //7 1 8 2 3 9   counter = 10

    //7 1 2 8 3 9   counter = 11

    //7 1 2 3 8 9   counter = 12
    //now 9 and 8 is the largest number in the array

    //1 7 2 3 8 9   counter = 13

    //1 2 7 3 8 9   counter = 14

    //1 2 3 7 8 9   counter = 15
    //the result = 15 not 5

    //this is the optimal
    //another algorithm is comparing with the smallest value in the array
    //but this algorithm must not use it because we must compare


    //9 8 7 3 2 1

    //1 8 7 3 2 9

    //1 2 7 3 8 9

    //1 2 3 7 8 9

    return 0;
}


