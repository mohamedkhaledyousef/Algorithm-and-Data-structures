#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

struct SegmentPair
{
    int start,end;
};

vector<int> optimal(vector<SegmentPair> &segments)
{
    //to sort the vector according to the end or second points
    sort(segments.begin(), segments.end(), [](const SegmentPair &first, const SegmentPair &second) -> bool
    {
        return first.end < second.end;
    });

    vector<int> points; // vector to store the common points in the segments

    int point = segments[0].end; // set the point to the first end point
    points.push_back(point);

    for (size_t i=1 ;i<segments.size(); ++i)
    {
        if (point < segments[i].start || point > segments[i].end)    //means if the point is in the segment which is the second segment
            {
            point = segments[i].end; // update the point to the end point of the current segment
            points.push_back(point); // store it in the vector
            }
    }

    return points;
}

int main()
{
    unsigned int n;
    cin >> n;

    vector<SegmentPair> segments(n);

    for (size_t i = 0; i < segments.size(); ++i)
    {
        cin >>segments[i].start>>segments[i].end;
    }

    vector<int> points=optimal(segments);
    cout<<points.size()<<endl;

    for (size_t i = 0; i < points.size(); ++i)
    {
        cout <<points[i]<<" ";
    }

    return 0;

}

/*

2 4
1 7
4 5
7 10
5 8

1 7         7 6 5 4 3 2 1
2 4         4 3 2
4 5         5 4
5 8         8 7 6 5
7 10        10 9 8 7

supposed solution
2
4 8
*/



/*
     without sorting
4 7     5 6 7
1 3     2 3
2 5     3 4 5
5 6     6

     after sorting
index    a b
 0       1 3        1 2 3
 1       2 5          2 3 4 5
 2       4 7              4 5 6 7
 3       5 6                5 6
                ---------------------
3 is the biggest in the first and second ,6 is the biggest  between the third and fourth

********************
3 2 1
5 4 3 2

        3

7 6 5 4
6 5

----------------------------------
----------------------------------
     after sorting
index    a b    length
0        1 3       2    1 2 3
1        2 5       3      2 3 4 5
2        3 6       3        3 4 5 6
            ---------------------------------
3 is the biggest between the first and second and third
*/

/*
    for(int i=0 ; i<n*2 ; ++i)
    {
        cin >>a[i]>>a[i+1];

    }

    sort(a.begin(),a.end());
  //  sort(b.begin(),b.end());

    //declare iterator
    vector <int> :: iterator j;

    int i;
    for(i=a.front() ; i<=b.front() ; ++i)            //1 2 3
    //for(i=a.begin() ; i!=b.begin() ; ++i)          //1 2 3
        //cout<<*i<<" ";        //uses with second loop
        cout<<i<<" ";           //uses with first loop
        cout<<endl;

    //for(j=a[i+1] ; j<=b[i+1] ; ++j)                      //2 3 4 5
    //for(j=a[a.begin())+1] ; j<=b[b.begin()+1] ; ++j)     //WHY cause error?????
    //for(j=a.begin()+1 ; j!=b.begin()+1 ; ++j)            //2 3 4 5
    for(j=a.begin()+1 ; j!=b.begin()+1 ; ++j)       //2 3 4 5
        cout<<*j<<" ";
        cout<<endl;

*/

/*
    4
    1 3
    2 5
    4 7
    5 6

    1 2 4 5
    3 5 6 7
     3   6
    ----------
    3 7  12 13
    5 8 14 15
     0    14
     ---------
     4 1 2 5
     7 3 5 6

     4 5 6 7
     1 2 3
     2 3 4 5
     5 6

     after sorting
     4 5 6 7
       5 6
        6
     1 2 3
       2 3 4 5
         3

     without sorting
     4 5 6 7
     1 2 3
       2 3 4 5
       5 6



    ---------
    3
    1 2 3
    3 5 6

    2 3 3
    max is 3

    1 2 3 3 5 6

//bad code
#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >>n;

    vector <int> a(n);
    vector <int> b(n);

    for(int i=0 ; i<n ; ++i)
    {
        cin >>a[i]>>b[i];

    }

    for(int i=0 ; i<n ; ++i)
        for(int j=1 ; j<n ; ++j)
            {
                if(a[i]==a[j])
                {
                    curr=a[i];

                }
                else
                if(b[i]==b[j])
                {
                    curr=b[i];
                }
            }
    return 0;
}
------------------------------------------------
bad code
int i=0,j=0;
    int currMax;
    for(int i=a[i] ; i<=b[j] ; ++i)         //1 2 3
        for(int j=a[i+1] ; j<=b[i+1] ; ++j) //2 3 4 5
            {
                if(a[i]==a[j] && a[i]>a[i-1])
                {
                    currMax=a[i];

                }

            }

    cout <<currMax<<endl;
-----------------------------------------------

    int currMax;
    for(int i=a.begin() ; i<=b.begin() ; ++i)         //1 2 3
        for(int j=a[i+1] ; j<=b[i+1] ; ++j)           //2 3 4 5
            {
                if(a[i]==a[j] && a[i]>a[i-1])
                {
                    currMax=a[i];

                }

            }

    cout <<currMax<<endl;




*/
