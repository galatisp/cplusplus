// cin with strings
#include <iostream>
#include <string>
using namespace std;

int main ()
{
  char line[256];
  string mystr;
  cout << "What's your name? ";
  fgets(line, sizeof(line), stdin);
//   getline (cin, mystr);
//  cin >> mystr;
  cout << "Hello " << line << ".\n";
  cout << "What is your favorite team? ";
  getline (cin, mystr);
  cout << "I like " << mystr << " too!\n";
  return 0;
}