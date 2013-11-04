//David Oguns
//Red-Black Tree implementation and demo

#include <iostream>
#include <functional>
#include "rb_tree.h"


using namespace std;

typedef bool LessThanFuncType(int const &, int const &);

bool lessThanInt(int const &a, int const &b) { return a < b; }

int main(int argc, const char **argv)
{
  std::function<bool(int const &, int const &)> lt = lessThanInt;

  cout << "Hello trees..." << endl;

  RbTree<int> tree;

  if(lt(7, 5))
  {
    cout << "This works..." << endl;
  }

  return 0;
}
