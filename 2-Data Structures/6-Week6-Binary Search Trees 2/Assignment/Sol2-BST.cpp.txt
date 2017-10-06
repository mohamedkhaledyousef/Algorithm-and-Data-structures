#include <bits/stdc++.h>

using namespace std;

vector<int> keys;
vector<int> lefts;
vector<int> rights;

	//case 6
    //         0   1    2    3
	//keys  :  4   2    1    5
	//lefts :  1   2   -1   -1
	//rights: -1   3   -1   -1

/*
lefts     keys      rights      cur
 1          4           -1       0
 2          2           3
 -1         1           -1
 -1         5           -1
*/

/*
lefts     keys      rights      cur
1           4       2           0
3           2       4
5           6       6
-1          1       -1
-1          3       -1
-1          5       -1
-1          7       -1
*/
bool IsBinarySearchTree(int cur)
{
	if (cur == -1 )     //
		return true;

	if (lefts[cur] != -1 && keys[cur]<keys[lefts[cur]])
		return false;

	if (rights[cur] != -1 && keys[cur]>keys[rights[cur]])
		return false;

	bool ret = true;

	if(lefts[cur])      //	if(lefts[cur]) != -1
        ret &= IsBinarySearchTree(lefts[cur]);
    if(rights[cur])
        ret &= IsBinarySearchTree(rights[cur]);

    return ret;
}


int main()
{
    int nodes;
	cin >> nodes;

	for (int i = 0; i < nodes; ++i)
	{
		int key, left, right;
		cin >> key >> left >> right;
		keys.push_back(key);
		lefts.push_back(left);
		rights.push_back(right);
	}

	//case 6
    //         0   1    2    3
	//keys  :  4   2    1    5
	//lefts :  1   2   -1   -1
	//rights: -1   3   -1   -1

	if (nodes==0 || IsBinarySearchTree(0))
		cout << "CORRECT" << endl;
	else
		cout << "INCORRECT" << endl;

	return 0;
}
