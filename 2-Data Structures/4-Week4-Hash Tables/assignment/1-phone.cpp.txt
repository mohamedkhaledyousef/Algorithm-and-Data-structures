#include <bits/stdc++.h>

using namespace std;

template<size_t N,size_t L=16> class Map
{
public:
  Map(): data_(N,nullptr){}
  ~Map()
  {
    for (size_t i=0; i<data_.size() ;++i)
        {
        if (auto addData=data_[i])
            delete[] addData;
        }
  }

  void insert(int mykey,const string& value)
  {
    char* input=data_[mykey];

    if (input==nullptr)
        {
        input=new char[L];
        }

    memset(input,'\0',L);

    for (size_t i=0; i<value.size() ;++i)
        {
        input[i]=value[i];
        }

    data_[mykey]=input;
  }

  string find(int mykey)
  {
    char* input=data_[mykey];

    if (input==nullptr)
      return "not found";
    else
      return string(input);
  }

  void Delete(int mykey)
  {
    char* input=data_[mykey];
    if (input != nullptr)
        {
        delete[] input;
        input=nullptr;
        }

    data_[mykey]=nullptr;
  }

private:
  vector<char*> data_;
};

struct myQuery
{
  string type,name;
  int number;
};

vector<myQuery> readQueries()
{
  int x;
  cin >>x;
  vector<myQuery> queries(x);

  for (int i=0; i<x ;++i)
    {
    cin >>queries[i].type;
    if (queries[i].type=="add")
      cin >>queries[i].number>>queries[i].name;
    else
      cin >>queries[i].number;
    }

  return queries;
}

void printing(const vector<string> &result)
{
  for(size_t i=0; i<result.size() ;++i)
    cout <<result[i]<<endl;

}

vector<string> validQueries(const vector<myQuery> &valids)
{
  vector<string> result;
  map<int,string> m;

  for(size_t i=0; i<valids.size() ;++i)
    {
    const auto&q=valids[i];
    if (q.type=="add")
        {
        m[q.number]=q.name;
        }
    else if(q.type=="del")
        {
        m.erase(q.number);
        }
    else
        {
        if (m.find(q.number)!= m.end())
            {
            result.push_back(m[q.number]);
            }
      else
        {
        result.emplace_back("not found");
        }
    }

  }
  return result;

}

vector<string> loopingQueries(const vector<myQuery> &queries)
{
  vector<string> result;
  // Keep list of all existing (i.e. not deleted yet) contacts.

  Map<10000000> m;
  for (size_t i=0; i<queries.size() ;++i)
    {
    const auto& q=queries[i];
    if (q.type=="add")
        {
        m.insert(q.number,q.name);
        }
    else if(q.type=="del")
        {
        m.Delete(q.number);
        }
    else
        {
      result.push_back(m.find(q.number));
        }
    }

  return result;
}

int main()
{

  printing(loopingQueries(readQueries()));

  return 0;

}


//-------------------------------------------------------------------------------------------------------------------------------------------
