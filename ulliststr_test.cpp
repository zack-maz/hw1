/* Write your test code for the ULListStr in this file */

#include <iostream>
#include <cstddef>
#include <cstdlib>
#include "ulliststr.h"
using namespace std;


int main(int argc, char* argv[])
{
  ULListStr ull;

  //random size of ULListStr initialized
  //testing back functions here
  size_t pbRand = rand() % 10 + 40;
  cout << "TESTING BACK FUNCTIONS" << endl;
  cout << "# of values: " << pbRand << endl;
  for (size_t i = 0; i < pbRand; i++)
  {
    ull.push_back(std::to_string(i));
  }
  cout << "SIZE: " << ull.size() << endl;
  cout << "last value: " << ull.get(pbRand-1) << endl;
  cout << "first value: " << ull.get(0) << endl;
  cout << "-------" << endl;

  for(size_t i = 0; i < pbRand; i++)
  {
    cout << "pop back " << ull.get(pbRand-i-1) << endl;
    ull.pop_back();
  }
  cout << "SIZE: " << ull.size() << endl;
  cout << "================" << endl;







  //random size of ULListStr initialized
  //testing front functions here
  pbRand = rand() % 10 + 40;
  cout << "TESTING FRONT FUNCTIONS" << endl;
  cout << "# of values: " << pbRand << endl;
  for (size_t i = 0; i < pbRand; i++)
  {
    ull.push_front(std::to_string(i));
  }
  cout << "SIZE: " << ull.size() << endl;
  cout << "last value: " << ull.get(pbRand-1) << endl;
  cout << "first value: " << ull.get(0) << endl;
  cout << "-------" << endl;

  for(size_t i = 0; i < pbRand; i++)
  {
    cout << "pop front " << ull.get(0) << endl;
    ull.pop_front();
  }
  cout << "SIZE: " << ull.size() << endl;
  cout << "================" << endl;








  //random size of ULListStr initialized
  //alternating between push_back and push_front
  //size is 6 here, but it makes sense
  pbRand = rand() % 10 + 40;
  cout << "TESTING MIXED" << endl;
  cout << "# of values: " << pbRand << endl;
  for (size_t i = 0; i < pbRand; i++)
  {
    if (i % 2 == 0) ull.push_front(std::to_string(i));
    else ull.push_back(std::to_string(i));
  }
  cout << "SIZE: " << ull.size() << endl;
  cout << "last value: " << ull.get(pbRand-1) << endl;
  cout << "first value: " << ull.get(0) << endl;
  cout << "-------" << endl;

  for(size_t i = 0; i < pbRand; i++)
  {
    if (i % 2 == 0) 
    {
      cout << "pop back " << ull.get(pbRand-i-1) << endl;
      ull.pop_back();
    }
    else 
    {
      cout << "pop front " << ull.get(0) << endl;
      ull.pop_front();
    }
  }
  cout << "SIZE: " << ull.size() << endl;


  return 0;
}
