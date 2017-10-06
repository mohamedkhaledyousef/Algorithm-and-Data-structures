#include <bits/stdc++.h>

using namespace std;

struct Data
{
  string type, s;
  size_t in;
};

class readInput
{
    int bucketCount;
    vector<deque<string>> data;
    vector<string> results;

    size_t hashing(const string& s )const
    {
        static const size_t multiplier = 263;
        static const size_t prime = 1000000007;
        unsigned long long hash = 0;
        for (int i=static_cast<int>( s.size())-1; i>=0 ;--i)
            hash=(hash*multiplier+s[i])% prime;

        return hash%bucketCount;
    }

public:
  explicit readInput(int bucketCount): bucketCount(bucketCount),data(bucketCount),results()
  {}

  Data readData() const
  {
    Data query;
    cin >>query.type;
    if (query.type !="check")
      cin >>query.s;
    else
      cin >>query.in;

    return query;
  }

  void printing(bool found)
  {
    string result=found ?"yes":"no";
    results.push_back(result);

  }

  void insert(const string &str)
  {
    int bc=hashing(str);
    auto &q=data[bc];
    if (std::find(q.begin(),q.end(),str) ==q.end())
      q.push_front(str);

  }

  string check(int in)
  {
    stringstream ss;
    const auto &q=data[in];
    if (q.empty())
    {
      ss <<" ";
      return ss.str();
    }

    for (auto it=q.begin(); it!=q.end() ;++it)
    {
      ss <<*it<<" ";
    }

    return ss.str();
  }

  bool find(const string &str)
  {
    int bc=hashing(str);
    const auto &q=data[bc];
    auto it=std::find(q.begin(),q.end(),str);

    return it!=q.end();

  }

  void del(const string &str)
  {
    int bc=hashing(str);
    auto &q=data[bc];
    auto it=std::find(q.begin(),q.end(),str);

    if (it!=q.end())
      q.erase(it);

  }

  void processQuery(const Data& query)
    {
    if (query.type=="check")
        {
        auto es=check(query.in);
        results.push_back(es);
        }
    else
        {
      if (query.type=="find")
        printing(find(query.s));
      else if(query.type=="add")
            insert(query.s);
      else if(query.type=="del")
            del(query.s);
        }
    }

  void processQueries()
    {
    int n;
    cin >>n;
    for (int i=0; i<n ;++i)
        processQuery(readData());

    for (const auto& r : results)
        cout <<r<<endl;
    }

};

int main()
{
    int bucketCount;
    cin >>bucketCount;

    readInput proc(bucketCount);
    proc.processQueries();

    return 0;
}

