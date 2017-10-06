#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <stack>
#include <vector>

using namespace std;

class Node
{
public:
  Node( int v ): val( v ), children(){}

  Node( const Node &n ) : val( n.val ), children( n.children ){}

  void add_child( int v ) { children.push_back( v ); }

  int size() const { return children.size(); }

  int val;
  vector< int > children;
};

class TreeHeight
{
  int n;
  vector< int > parent;
  map< int, Node * > ns;

  Node *node;

public:
  ~TreeHeight()
  {
    for ( const auto &n : ns )
    {
      delete n.second;
    }
  }

  void read()
  {
    cin >> n;
    parent.resize(n);
    for ( int i=0; i<n; i++)
        cin >>parent[i];
  }

  int computeHeight()
  {
    constructTree();
    return max_depth(node);
  }

private:
  int max_depth(Node*n)
  {
    if (n==nullptr)
      return 0;

    if (n->size()==0)
      return 1;

    int m=0;
    for (int i=0; i<n->size() ;++i)
    {
      int d=max_depth(ns[n->children[i]]);
      if (d>m)
        m=d;
    }
    return m+1;
  }

  void constructTree()
  {
    for ( int i=0; i<n ;++i)
    {
      ns[i]=new Node(i);
    }

    for (int i=0; i<n; ++i)
    {
      int p=parent[i];

      if (p!=-1)
      {
        ns[p]->add_child(i);
      }
      else
      {
        node=ns[i];
      }
    }
  }
};

int main()
{
    std::ios_base::sync_with_stdio(0);

    TreeHeight tree;
    tree.read();
    cout <<tree.computeHeight()<<endl;

  return 0;
}

