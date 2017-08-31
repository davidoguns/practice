
#include <iostream>
#include <random>
#include <fstream>
#include <sstream>

using namespace std;

int main(int argc, const char ** argv)
{
  default_random_engine dre;
  unsigned long long num = 0;
  unsigned long long low = 0;
  unsigned long long high = 0;
  istringstream(argv[1]) >> num;
  istringstream(argv[2]) >> low;
  istringstream(argv[3]) >> high;

  uniform_int_distribution<unsigned long long> distribution(low, high);
  
  for(unsigned long long i = 0; i < num; ++i)
  {
    cout << distribution(dre) << " ";
  }
  return 0;
}
