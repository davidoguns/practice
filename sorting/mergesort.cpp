//mergesort.cpp
//familiarization with O(n log n), data seeded from std in
//David Oguns

#include <list>
#include <vector>
#include <iostream>

using namespace std;

void printList(const vector<unsigned long long> &vec)
{
  for(const unsigned long long &i:vec)
  {
    cout << i << " ";
  }
}

//actual algorithm
vector<unsigned long long> mergesort(vector<unsigned long long> &items, unsigned int start, unsigned int end)
{
  const unsigned int size = end - start;
  vector<unsigned long long> merged(size); //reserve capacity of what we're returning

  if(size == 1)
  {
    merged[0] = items[start];
  }
  else
  {
    unsigned int mid = (end + start) / 2;
    vector<unsigned long long> left = mergesort(items, start, mid);
    vector<unsigned long long> right = mergesort(items, mid, end);
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
  vector<unsigned long long> input;
  unsigned long long item;
  while(cin >> item)
  {
    input.push_back(item);
  }
  
  cout << "Sorting " << input.size() << " items." << endl;
  
  vector<unsigned long long> sorted = mergesort(input, 0, input.size());
  
  cout << "Sorted list:" << endl;
  for(unsigned long long item:sorted)
  {
    cout << item << " ";
  }

  return 0;
}
