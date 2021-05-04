// passing parameters by reference
#include <iostream>
using namespace std;

int  duplicate (const int& a, const int& b, const int& c)
{
  return 2*(a+b+c); 
}

void swap (int& a, int& b)
{
  int temp;
  temp= a;
  a = b;
  b = temp;

}

int main ()
{
  int x=1, y=3, z=7;
  cout << duplicate (x, y, z) << endl;
//   cout << "x=" << x << ", y=" << y << ", z=" << z <<endl;

  swap (x, y);
  cout << "x=" << x << ", y=" << y << endl;
  return 0;
}