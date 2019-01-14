#include <iostream>
#include <string>

using namespace std;

int main() {

  //C++ uses the << operator to print to stdout.
  //You can easily take input from stdin using the >> operator.
  char c;
  int d;
  float f;
  string s;
  cout << "Type a character, decimal, float, and string. I will add commas.\n";
  cin >> c >> d >> f >> s;
  cout << c << ", " << d << ", " << f << ", " << s << '\n';

}
