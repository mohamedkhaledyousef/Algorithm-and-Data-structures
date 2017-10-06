//accepted solution

#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>

using namespace std;

vector<int> partition3(vector<int> &arr, int l, int r)
{
    int x = arr[l];
    int m1 = l;
	int m2 = r;
	int i = l;
    while(i <= m2)
    {
		if (arr[i] < x)
            {
			swap(arr[i], arr[m1]);
			m1++;
			i++;
            }
		else if (arr[i] > x)
            {
			swap(arr[i], arr[m2]);
			m2--;
            }
		else
			i++;
    }

	vector<int> m = {m1, m2};

    return m;
}

//we can delete this function
int partition2(vector<int> &arr, int l, int r)
{
    int x=arr[l];
    int j=l;
    for (int i=l+1; i<=r ;i++)
        {
            if (arr[i] <= x)
            {
                j++;
                swap(arr[i], arr[j]);
            }
        }

    swap(arr[l], arr[j]);

    return j;
}

void randomQuickSort(vector<int> &arr, int l, int r)
{
                                                    //2 3 9 2 2
    if (l >= r)                                     //l=2   r=2
        {
            return;
        }

    int k = l + rand() % (r - l + 1);
            //rand() to generate random values
                //v1 = rand() % 100;         // v1 in the range 0 to 99
                //v2 = rand() % 100 + 1;     // v2 in the range 1 to 100
                //v3 = rand() % 30 + 1985;   // v3 in the range 1985-2014

                //k = l + rand() % (r - l + 1);
                    //k = 2 + (2-2+1) = 2+1 = 3

    swap(arr[l], arr[k]);

    //int m = partition2(arr, l, r);
    //randomQuickSort(arr, l, m - 1);
    //randomQuickSort(arr, m + 1, r);

    vector<int> m = partition3(arr, l, r);
    randomQuickSort(arr, l , m[0]-1);
    randomQuickSort(arr, m[1]+1 , r);


}

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
    //2 3 9 2 2

    randomQuickSort(arr,0,arr.size()-1);

    for (size_t i = 0; i < arr.size(); ++i)
        {
            cout <<arr[i]<<" ";
            //printf("%d",&arr[i])

        }

    return 0;
}


---------------------------------------------------------------------------------------------------------------
//Failed case #14/23: time limit exceeded (Time used: 3.99/2.20, memory used: 29216768/536870912.)

#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>

using namespace std;

int partition2(vector<int> &arr, int l, int r)
{
    int x=arr[l];
    int j=l;
    for (int i=l+1; i<=r ;i++)
        {
            if (arr[i] <= x)
            {
                j++;
                swap(arr[i], arr[j]);
            }
        }

    swap(arr[l], arr[j]);

    return j;
}

void randomQuickSort(vector<int> &arr, int l, int r)
{
    if (l >= r)
        {
            return;
        }

    int k = l + rand() % (r - l + 1);
    swap(arr[l], arr[k]);
    
    int m = partition2(arr, l, r);
    randomQuickSort(arr, l, m - 1);
    randomQuickSort(arr, m + 1, r);


}

int main()
{
    int n;
    cin >> n;
    //scanf("%d",&n)

    vector<int> arr(n);
    for (size_t i=0 ;i<arr.size(); ++i)
        {
            //scanf("%d",&arr[i])
            cin >>arr[i];
        }

    randomQuickSort(arr,0,arr.size()-1);

    for (size_t i = 0; i < arr.size(); ++i)
        {
            cout <<arr[i]<<" ";
            //printf("%d",&arr[i])

        }

    return 0;
}


------------------------------------------------------------------------------------------------------------------------------------

/*
// this is C implementation QuickSort
#include<stdio.h>

// A utility function to swap two elements
void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}


int partition (int arr[], int low, int high)
{
	int pivot = arr[high]; // pivot
	int i = (low - 1); // Index of smaller element

	for (int j = low; j <= high- 1; j++)
	{
		// If current element is smaller than or
		// equal to pivot
		if (arr[j] <= pivot)
		{
			i++; // increment index of smaller element
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

/* The main function that implements QuickSort
arr[] --> Array to be sorted,
low --> Starting index,
high --> Ending index 
*/

void quickSort(int arr[], int low, int high)
{
	if (low < high)
	{
		/* pi is partitioning index, arr[p] is now
		at right place */
		int pi = partition(arr, low, high);

		// Separately sort elements before
		// partition and after partition
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}

/* Function to print an array */
void printArray(int arr[], int size)
{
	int i;
	for (i=0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

// Driver program to test above functions
int main()
{
    int x;
    scanf("%d",&x);

	int arr[x];
    for (int i=0 ; i<x ; ++i)
        scanf("%d",&arr[i]);

	int n = sizeof(arr)/sizeof(arr[0]);

	quickSort(arr, 0, n-1);
	printArray(arr, n);
	return 0;
}

*/

------------------------------------------------------------------------------------------------------------------------------------

/*
//Failed case #14/23: time limit exceeded (Time used: 3.99/2.20, memory used: 29204480/536870912.)

#include<cstring>
#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;

// Following functions are taken from http://goo.gl/ih05BF
int partition(int arr[], int l, int r, int k);
int kthSmallest(int arr[], int l, int r, int k);

/* A O(nLogn) time complexity function for sorting arr[l..h] */
void quickSort(int arr[], int l, int h)
{
    if (l < h)
    {
        // Find size of current subarray
        int n = h-l+1;

        // Find median of arr[].
        int med = kthSmallest(arr, l, h, n/2);

        // Partition the array around median
        int p = partition(arr, l, h, med);

        // Recur for left and right of partition
        quickSort(arr, l, p - 1);
        quickSort(arr, p + 1, h);
    }
}

// A simple function to find median of arr[].  This is called
// only for an array of size 5 in this program.
int findMedian(int arr[], int n)
{
    sort(arr, arr+n);  // Sort the array
    return arr[n/2];   // Return middle element
}

// Returns k'th smallest element in arr[l..r] in worst case
// linear time. ASSUMPTION: ALL ELEMENTS IN ARR[] ARE DISTINCT
int kthSmallest(int arr[], int l, int r, int k)
{
    // If k is smaller than number of elements in array
    if (k > 0 && k <= r - l + 1)
    {
        int n = r-l+1; // Number of elements in arr[l..r]

        // Divide arr[] in groups of size 5, calculate median
        // of every group and store it in median[] array.
        int i, median[(n+4)/5]; // There will be floor((n+4)/5) groups;
        for (i=0; i<n/5; i++)
            median[i] = findMedian(arr+l+i*5, 5);
        if (i*5 < n) //For last group with less than 5 elements
        {
            median[i] = findMedian(arr+l+i*5, n%5);
            i++;
        }

        // Find median of all medians using recursive call.
        // If median[] has only one element, then no need
        // of recursive call
        int medOfMed = (i == 1)? median[i-1]:
                                 kthSmallest(median, 0, i-1, i/2);

        // Partition the array around a random element and
        // get position of pivot element in sorted array
        int pos = partition(arr, l, r, medOfMed);

        // If position is same as k
        if (pos-l == k-1)
            return arr[pos];
        if (pos-l > k-1)  // If position is more, recur for left
            return kthSmallest(arr, l, pos-1, k);

        // Else recur for right subarray
        return kthSmallest(arr, pos+1, r, k-pos+l-1);
    }

    // If k is more than number of elements in array
    return INT_MAX;
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// It searches for x in arr[l..r], and partitions the array
// around x.
int partition(int arr[], int l, int r, int x)
{
    // Search for x in arr[l..r] and move it to end
    int i;
    for (i=l; i<r; i++)
        if (arr[i] == x)
           break;
    swap(&arr[i], &arr[r]);

    // Standard partition algorithm
    i = l;
    for (int j = l; j <= r - 1; j++)
    {
        if (arr[j] <= x)
        {
            swap(&arr[i], &arr[j]);
            i++;
        }
    }
    swap(&arr[i], &arr[r]);
    return i;
}

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// Driver program to test above functions
int main()
{
    //int arr[] = {1000, 10, 7, 8, 9, 30, 900, 1, 5, 6, 20};

    int x;

    cin>>x;
    int arr[x];

    for(int i=0;i<x;i++)
    {
        cin>>arr[i];
    }

    int n = sizeof(arr)/sizeof(arr[0]);

    quickSort(arr, 0, n-1);

    printArray(arr, n);

    return 0;
}

*/

------------------------------------------------------------------------------------------------------------------------------------


/*
//Failed case #14/23: time limit exceeded (Time used: 3.99/2.20, memory used: 29208576/536870912.)
#include<iostream>
using namespace std;

void QUICKSORT(int [],int ,int );
int PARTITION(int [],int,int );

int main()
{
    int n;

    cin>>n;
    int a[n];

    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    int p=1,r=n;
    QUICKSORT(a,p,r);

   for(int i=1;i<=n;i++)
   {
       cout<<a[i]<<" ";
   }
   cout <<endl;

     return 0;
}

void QUICKSORT(int a[],int p,int r)
    {
        int q;
        if(p<r)
        {
         q=PARTITION(a,p,r);
         QUICKSORT(a,p,q-1);
         QUICKSORT(a,q+1,r);
        }
    }

 int PARTITION(int a[],int p,int r)
    {
        int temp,temp1;
        int x=a[r];
        int i=p-1;
        for(int j=p;j<=r-1;j++)
        {
            if(a[j]<=x)
            {

                i=i+1;
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
        temp1=a[i+1];
        a[i+1]=a[r];
        a[r]=temp1;

        return i+1;
    }
*/

------------------------------------------------------------------------------------------------------------------------------------

//Failed case #4/23: unknown signal 11 (Time used: 0.00/2.20, memory used: 29151232/536870912.)
/*
#include <iostream>

using namespace std;

void quick_sort(int[],int,int);
int partition(int[],int,int);

int main()
{
    int a[50],n,i;

    cin>>n;

    for(i=0;i<n;i++)
        cin>>a[i];

    quick_sort(a,0,n-1);
    //a is array name,0 is the first index,n-1 the last index

    //cout<<"\nArray after sorting:";
    for(i=0;i<n;i++)
        cout<<a[i]<<" ";

    return 0;
}

void quick_sort(int a[],int l,int u)
{
    int j;
    if(l<u)
    {
        j=partition(a,l,u);
        quick_sort(a,l,j-1);
        quick_sort(a,j+1,u);
    }
}

int partition(int a[],int l,int u)
{
    int v,i,j,temp;
    v=a[l];
    i=l;
    j=u+1;

    do
    {
        do
            i++;

        while(a[i]<v&&i<=u);

        do
            j--;
        while(v<a[j]);

        if(i<j)
        {
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }while(i<j);

    a[l]=a[j];
    a[j]=v;

    return(j);
}
*/

//--------------------------------------------------------------------------------


