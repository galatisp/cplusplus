// function example
#include <iostream>
using namespace std;

void mypower (int b, int e)
{
  int r=1.0;
  for (int i =0; i < e; i++)
    r *= b;
  cout << r;
}

int main ()
{
//   int z;
//   z = addition (5,3);
  
  mypower(5,3);
}