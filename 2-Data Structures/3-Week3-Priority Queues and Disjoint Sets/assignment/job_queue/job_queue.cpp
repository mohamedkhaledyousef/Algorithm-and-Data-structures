//sol
#include <bits/stdc++.h>

using namespace std;

struct Node
{
    Node(): priority(0), workerIndex(0){}

    Node( int p, int w ): priority(p), workerIndex( w ){}

    long long priority;
    int workerIndex;

    friend bool operator<( const Node &first, const Node &second );
    friend bool operator==( const Node &first, const Node &second );
    friend bool operator>( const Node &first, const Node &second );
    friend bool operator!=( const Node &first, const Node &second );
};

bool operator<(const Node &first,const Node &second)
{
    if (first.priority<second.priority)
        return true;
    else if (first.priority==second.priority)
        {
        if (first.workerIndex<second.workerIndex)
            return true;
        else
            return false;
        }

    return false;
}

bool operator==(const Node &first,const Node &second)
    {
    return first.priority==second.priority;
    }

bool operator>(const Node &first,const Node &second)
    {
    return !(first<second) && !(first==second);
    }

bool operator!=(const Node &first,const Node &second)
    {
    return !(first==second);

    }
class Heap
{
public:
    explicit Heap(int size):size_(size),maxSize_(size+10),data_(maxSize_)
    {
    for (int i=0; i<size_; ++i)
        data_[i]=Node(0,i);
    }

private:
    int size_;
    int maxSize_;
    vector<Node> data_;

    int LeftChild(int i) {return 2*i+1;}
    int RightChild(int i) {return 2*i+2;}

    int Parent(int i)
    {
        if (i==0)
            return 0;
        else
            return (i-1)/2;
    }

    void SiftUp(int i)
    {
        int c=i;

        while (c>0 && data_[Parent(c)]>data_[c])
        {
            swap(data_[Parent(c)],data_[c]);
                c=Parent(c);
        }
    }

  void SiftDown(int i)
  {
        int maxIndex=i;
        int left=LeftChild(i);
        if (left<size_ && data_[left]<data_[maxIndex])
            maxIndex=left;

        int right=RightChild(i);
        if (right<size_ && data_[right]<data_[maxIndex])
            maxIndex=right;

        if (i!=maxIndex)
        {
          swap(data_[i],data_[maxIndex]);
                SiftDown(maxIndex);
        }
  }

public:
    void BuildHeap()
    {
        int mid=size_ /2;
        for (int i=mid; i>=0 ;--i)
            SiftDown(i);
    }

    Node GetMax()
    {
        const Node &r=data_[0];
        return r;
    }

    void ChangePriority(int i,long long priority)
    {
        Node &r=data_[i];
        long long oldp=r.priority;
        r.priority=priority;
        if (priority> oldp )
            SiftDown(i);
        else
            SiftUp(i);
    }

    void Insert(const Node &n)
    {
        if (size_==maxSize_)
            throw runtime_error("Exceeds max size");
        size_+=1;
        data_[size_-1]=n;

        SiftUp(size_-1);
    }
};

class JobQueue
{
private:
    int num_workers_;
    vector< int > jobs_;
    vector< int > assigned_workers_;
    vector< long long > start_times_;

    vector< Node > data_;

    void WriteResponse() const
    {
        for ( size_t i = 0; i < jobs_.size(); ++i )
        {
        cout << assigned_workers_[ i ] << " " << start_times_[ i ] << "\n";
        }
    }

    void ReadData()
    {
        int m;
        cin >> num_workers_ >> m;
        jobs_.resize( m );
        for ( int i = 0; i < m; ++i )
        cin >> jobs_[ i ];
    }

    void AssignJobs()
    {
        // TODO: replace this code with a faster algorithm.
        assigned_workers_.resize( jobs_.size() );
        start_times_.resize( jobs_.size() );
        vector< long long > next_free_time( num_workers_, 0 );
        Heap heap( num_workers_ );

        for ( size_t i = 0; i < jobs_.size(); ++i )
            {
            int duration = jobs_[ i ];

            Node node = heap.GetMax(); // log n
            assigned_workers_[ i ] = node.workerIndex;
            start_times_[ i ] = next_free_time[ node.workerIndex ];
            next_free_time[ node.workerIndex ] += duration;
            // heap.Insert( Node( node.prio + duration, node.worker_id ) ); // log n
            heap.ChangePriority( 0, node.priority + ( long long )duration );
            }
    }

    
public:
    void Solve()
    {
        ReadData();
        AssignJobs();
        WriteResponse();
    }
};

int main()
{
    std::ios_base::sync_with_stdio( false );

    JobQueue job_queue;
    job_queue.Solve();

    return 0;

}

//-------------------------------------------------------------------------------------------------------------------------------------------

#include <bits/stdc++.h>

using namespace std;

struct Node
{
    Node(): priority(0), workerIndex(0){}

    Node( int p, int w ): priority(p), workerIndex( w ){}

    long long priority;
    int workerIndex;

    friend bool operator<( const Node &first, const Node &second );
    friend bool operator==( const Node &first, const Node &second );
    friend bool operator>( const Node &first, const Node &second );
    friend bool operator!=( const Node &first, const Node &second );
};

bool operator<(const Node &first,const Node &second)
{
    if (first.priority<second.priority)
        return true;
    else if (first.priority==second.priority)
        {
        if (first.workerIndex<second.workerIndex)
            return true;
        else
            return false;
        }

    return false;
}

bool operator==(const Node &first,const Node &second)
    {
    return first.priority==second.priority;
    }

bool operator>(const Node &first,const Node &second)
    {
    return !(first<second) && !(first==second);
    }

bool operator!=(const Node &first,const Node &second)
    {
    return !(first==second);

    }
class Heap
{
public:
    explicit Heap(int size):size_(size),maxSize_(size+10),data_(maxSize_)
    {
    for (int i=0; i<size_; ++i)
        data_[i]=Node(0,i);
    }

private:
    int size_;
    int maxSize_;
    vector<Node> data_;

    int LeftChild(int i) {return 2*i+1;}
    int RightChild(int i) {return 2*i+2;}

    int Parent(int i)
    {
        if (i==0)
            return 0;
        else
            return (i-1)/2;
    }

    void SiftUp(int i)
    {
        int c=i;

        while (c>0 && data_[Parent(c)]>data_[c])
        {
            swap(data_[Parent(c)],data_[c]);
                c=Parent(c);
        }
    }

  void SiftDown(int i)
  {
        int maxIndex=i;
        int left=LeftChild(i);
        if (left<size_ && data_[left]<data_[maxIndex])
            maxIndex=left;

        int right=RightChild(i);
        if (right<size_ && data_[right]<data_[maxIndex])
            maxIndex=right;

        if (i!=maxIndex)
        {
          swap(data_[i],data_[maxIndex]);
                SiftDown(maxIndex);
        }
  }

public:
    void BuildHeap()
    {
        int mid=size_ /2;
        for (int i=mid; i>=0 ;--i)
            SiftDown(i);
    }

    Node GetMax()
    {
        const Node &r=data_[0];
        return r;
    }

    void ChangePriority(int i,long long priority)
    {
        Node &r=data_[i];
        long long oldp=r.priority;
        r.priority=priority;
        if (priority> oldp )
            SiftDown(i);
        else
            SiftUp(i);
    }

    void Insert(const Node &n)
    {
        if (size_==maxSize_)
            throw runtime_error("Exceeds max size");
        size_+=1;
        data_[size_-1]=n;

        SiftUp(size_-1);
    }
};

class JobQueue
{
private:
    int num_workers_;
    vector< int > jobs_;
    vector< int > assigned_workers_;
    vector< long long > start_times_;

    vector< Node > data_;

    void WriteResponse() const
    {
        for ( size_t i = 0; i < jobs_.size(); ++i )
        {
        cout << assigned_workers_[ i ] << " " << start_times_[ i ] << "\n";
        }
    }

    void ReadData()
    {
        int m;
        cin >> num_workers_ >> m;
        jobs_.resize( m );
        for ( int i = 0; i < m; ++i )
        cin >> jobs_[ i ];
    }

    void AssignJobs()
    {
// TODO: replace this code with a faster algorithm.
    assigned_workers_.resize(jobs_.size());
    start_times_.resize(jobs_.size());
    vector<long long> next_free_time(num_workers_, 0);
    for (int i = 0; i < jobs_.size(); ++i) {
      int duration = jobs_[i];
      int next_worker = 0;
      for (int j = 0; j < num_workers_; ++j) {
        if (next_free_time[j] < next_free_time[next_worker])
          next_worker = j;
      }
      assigned_workers_[i] = next_worker;
      start_times_[i] = next_free_time[next_worker];
      next_free_time[next_worker] += duration;
    }
  }

public:
    void Solve()
    {
        ReadData();
        AssignJobs();
        WriteResponse();
    }
};

int main()
{
    std::ios_base::sync_with_stdio( false );

    JobQueue job_queue;
    job_queue.Solve();

    return 0;

}






