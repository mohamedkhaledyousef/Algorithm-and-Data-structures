//solution

#include <bits/stdc++.h>

using namespace std;

class TreeOrders
{
  int n;
  vector< int > key;
  vector< int > left;
  vector< int > right;

public:
  void read()
  {
    cin >> n;
    key.resize( n );
    left.resize( n );
    right.resize( n );
    for ( int i = 0; i < n; i++ )
    {
      cin >> key[ i ] >> left[ i ] >> right[ i ];
    }
  }

  struct Node
  {
    int key;
    int left;
    int right;

  };

  void inOrderTraverse(vector<int> &result,int nodeIndex)
  {
    if (nodeIndex==-1)  //if tree = null
      return;

    int k=key[nodeIndex];
    int l=left[nodeIndex];
    int r=right[nodeIndex];

    inOrderTraverse(result,l);      //InOrderTraversal(tree.left)
    result.push_back(k);
    inOrderTraverse(result,r);      //InOrderTraversal(tree.right)

  }

  vector< int > inOrder()
  {
    if (key.empty())
      return vector<int>();

    vector<int> result;

    // Finish the implementation
    inOrderTraverse(result,0);
    return result;
  }

  void preOrderTraverse(vector <int> &result,int nodeIndex)
  {
    if (nodeIndex==-1)
      return;

    result.push_back(key[nodeIndex]);               //Print(tree.key)
    preOrderTraverse(result,left[nodeIndex]);       //PreOrderTraversal(tree.left)
    preOrderTraverse(result,right[nodeIndex]);      //PreOrderTraversal(tree.right)
  }

  vector< int > preOrder()
  {
    if (key.empty())
      return vector<int>();

    vector< int > result;

    // Finish the implementation
    // You may need to add a new recursive method to do that
    preOrderTraverse(result,0);
    return result;

  }

  void postOrderTraverse(vector<int> &result,int nodeIndex)
  {
    if (nodeIndex==-1)
      return;

    postOrderTraverse(result,left[nodeIndex]);      //PostOrderTraversal(tree.left)
    postOrderTraverse(result,right[nodeIndex]);     //PostOrderTraversal(tree.right)

    result.push_back(key[nodeIndex]);               //Print(tree.key)

  }

  vector< int > postOrder()
  {
    if (key.empty())
      return vector< int >();

    vector< int > result;

    // Finish the implementation
    // You may need to add a new recursive method to do that
    postOrderTraverse(result,0);
    return result;
  }

};

void printing(vector<int>a)
{
  for (size_t i=0; i<a.size() ;++i)
    {
    if (i>0)
        {
        cout <<" ";
        }

    cout<<a[i];
    }

  cout<<endl;
}

int main()
{
    TreeOrders t;
    t.read();

    printing(t.inOrder());
    printing(t.preOrder());
    printing(t.postOrder());

  return 0;
}



