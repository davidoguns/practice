
#include <iostream>
#include <random>
#include <fstream>
#include <sstream>

using namespace std;

int main(int argc, const char ** argv)
{
  default_random_engine dre;
  unsigned int num = 0;
  unsigned int low = 0;
  unsigned int high = 0;
  istringstream(argv[1]) >> num;
  istringstream(argv[2]) >> low;
  istringstream(argv[3]) >> high;

  uniform_int_distribution<int> distribution(low, high);
  
  for(unsigned int i = 0; i < num; ++i)
  {
    cout << distribution(dre) << " ";
  }
  return 0;
}
