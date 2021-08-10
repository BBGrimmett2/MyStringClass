#include <iostream>
#include <fstream>
#include "MyString.h"

using namespace std;

int main () {
  MyString s0;
  cin >> s0;

  // ============================
  // constructors
  // ============================

  MyString s0; // testing default constructor
  cin >> s0;

  // MyString s1(s0); // testing copy constructor

  // ============================
  // accessor functions
  // ============================

  s0.printLocation(0); // testing print location

  // ============================
  // modifier functions
  // ============================

  s0.addCharacter('a'); // testing add character modifier function

  s0.insertCharacter('z', 2); // testing insert character at a location

  s0.removeFirstCharacter(); // testing remove first character modifier function

  s0.removeLocationCharacter(4); // testing remove location character modifier function

  s0.removeLastCharacter(); // testing remove last character modifier function

  // ============================
  // operations
  // ============================

  MyString s1;
  cin >> s1;

  s1 = s0; // testing equal operator

  MyString s3;
  s3 = (s0 + s1); // testing adding operator

  s0 < s1; // testing less than operator

  s0 > s1; // testing greater than operator

  s0 <= s1; // testing less than equal to operator

  s0 >= s1; // testing greater than equal to operator

  s0 == s1; // testing equal equals operator

  // ============================
  // Input/Output
  // ============================

  cin >> s0; // testing >> operator

  cout << s0 << endl; // testing << operator

  return 0;
}
