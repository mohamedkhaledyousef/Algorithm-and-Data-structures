#include <iostream>
#include <algorithm>

using namespace std;
bool check(vector<vector<int>> &adj,int v,vector<bool> &visited,vector<bool> &order )
{
    if (visited[v]==false)
    {
        visited[v]=true;
        order[v]=true;

        for (size_t i=0 ;i<adj[v].size(); ++i)
        {
            if (!visited[adj[v][i]] && check(adj,adj[v][i],visited,order))
                return true;
            else if (order[adj[v][i]])
                return true;
        }
    }

  order[v]=false;
  return false;

}

int acyclic( vector< vector< int > > &adj )
{
    // write your code here
    if (adj.empty())
        return 0;

    vector<bool>visited(adj.size(),false);
    vector<bool>order(adj.size(),false);

    for (size_t i=0; i<adj.size() ;++i)
        {
        if (check(adj,i,visited,order))
            return 1;
        }

    return 0;
}

int main()
{
  size_t n, m;
  cin >> n >> m;
  vector< vector< int > > adj( n, vector< int >() );
  for ( size_t i = 0; i < m; i++ ){
    int x, y;
    cin >> x >> y;
    adj[ x - 1 ].push_back( y - 1 );
  }
  cout << acyclic( adj );

  return 0;
}

