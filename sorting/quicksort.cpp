//quicksort.cpp
//familiarization with O(n log n), data seeded from std in
//David Oguns

#include <vector>
#include <iostream>
#include <stdexcept>
#include <iterator>

using namespace std;

template <class T>
void printList(const vector<T> &vec)
{
  for(const T &i:vec)
  {
    cout << i << endl;
  }
}

//pivot picker - basic version will just use the end, could refine and use some heuristic for a better pivot
template <class T>
typename vector<T>::const_iterator pickPivot(const vector<T> &items)
{ //we're picking 1 minus the end since we're doing in place, and don't want to move around pIdx more than we have to
  return (items.end()-1);
}

//actual algorithm
//vector to sort, index of pivot, start of partition to sort, end of partition to sort
//pre: pIdex must be between start and end, might want to bounds check
template <class T>
vector<T> quicksort(const vector<T> &items)
{ 
  if(items.size() <= 1)
  {
    return items;
  }
  
  vector<T> less;
  vector<T> greater;
  typename vector<T>::const_iterator pivot = pickPivot(items);
  for(typename vector<T>::const_iterator itr = items.begin(); itr != items.end(); ++itr)
  {
    if(itr == pivot)
    { //handle pivot explicitly
      continue;
    }
    if(*itr < *pivot)
    {
      less.push_back(*itr);
    }
    else
    {
      greater.push_back(*itr);
    }
  }
  if(greater.empty())
  {
    greater.push_back(*pivot);
  }
  else
  {
    less.push_back(*pivot);
  }

  vector<T> lsort = quicksort(less);
  vector<T> gsort = quicksort(greater);
  for(T g:gsort)
  {
    lsort.push_back(g);
  }

  return lsort;
}

int main(int argc, char ** argv)
{
  istream_iterator<unsigned long long> eos;
  istream_iterator<unsigned long long> input_it(cin);
  vector<unsigned long long> input {input_it, eos};

  cerr << "Sorting " << input.size() << " items." << endl;
  
  vector<unsigned long long> sorted = quicksort<unsigned long long>(input);
  
  cerr << "Sorted list: "; printList(sorted); cerr << endl;

  return 0;
}
