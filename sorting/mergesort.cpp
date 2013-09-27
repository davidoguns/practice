//mergesort.cpp
//familiarization with O(n log n), data seeded from std in
//David Oguns

#include <list>
#include <vector>
#include <iostream>
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

//actual algorithm
template <class T>
vector<T> mergesort(const vector<T> &items, unsigned int start, unsigned int end)
{
  const unsigned int size = end - start;
  vector<T> merged(size); //reserve capacity of what we're returning

  if(size == 1)
  {
    merged[0] = items[start];
  }
  else
  {
    unsigned int mid = (end + start) / 2;
    vector<T> left = mergesort(items, start, mid);
    vector<T> right = mergesort(items, mid, end);
    //now merge and return
    unsigned int lIdx = 0;
    unsigned int rIdx = 0;
    for(unsigned int pIdx = 0; pIdx < size; ++pIdx)
    {
      if(lIdx != left.size() && rIdx != right.size() && left[lIdx] < right[rIdx])
      {
        merged[pIdx] = left[lIdx++];
      }
      else if(rIdx != right.size())
      {
        merged[pIdx] = right[rIdx++];
      }
      else
      {
        merged[pIdx] = left[lIdx++];
      }
    }
  }
  return std::move(merged);
}

int main(int argc, char ** argv)
{
  istream_iterator<unsigned long long> eos;
  istream_iterator<unsigned long long> input_it(cin);
  vector<unsigned long long> input {input_it, eos};
  
  cerr << "Sorting " << input.size() << " items." << endl;
  
  vector<unsigned long long> sorted = mergesort<unsigned long long>(input, 0, input.size());
  
  cerr << "Sorted list: "; printList(sorted); cerr << endl;

  return 0;
}
