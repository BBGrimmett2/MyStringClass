#ifndef INCLUDED_MYSTRING
#define INCLUDED_MYSTRING

#include <iostream>
using namespace std;

class MyString {
  /* Class Invariant (CI): arraySize = S > 0
                           theString has S locations allocated to it.
                           strLength = L, where 0 <= L < arraySize.
                           theString[0]..theString[L-1] are the
                             characters of this MyString object.
                           theString[L] = '\0'
   */

 private:
  char * theString;   // holds the characters for this MyString object.
  int strLength;      // holds the number of characters (not including
		      // the end of string character) in this
		      // MyString object
  int arraySize;      // holds the current size (number of locations)
		      // allocated for theString.

 public:
  // ============================
  // constructors
  // ============================

  // default constructor
  // PRE:
  // POST: theString = '\0' (CI is satisfied)
  //       strLength = 0
  //       arraySize = 1
  MyString();

  // copy constructor
  // PRE: pString equals the string being copied
  // POST: RV is a MyString with values copied from pString
  MyString(const MyString & pString);

  // ============================
  // accessor functions
  // ============================

  // PRE:
  // POST:
  void copyString (MyString original, MyString copy);

  // PRE: pString is the object containing theString, locaiton is the index
  //      where the value of theString is targeted
  // POST: OS contains the value at location in theString of pString
  void printLocation (int location);

  // PRE: character is the object being searched for in MyString
  // POST: RV is true iff character exists in theString
  bool inString (char character);

  // PRE: MyString object is defined
  // POST: RV is the array of chars;
  char * string ();

  // ============================
  // modifier functions
  // ============================

  // PRE: newChar is the character being added to theString
  // POST: theString is updated and if needed it's memory allocation has been doubled iff
  //       the strLength equals arraySize
  void addCharacter (char newChar);

  // PRE: newChar is the character to insert at the index equal to location
  // POST: theString now contains newChar at the index location will all original values copied
  //       around newChar
  void insertCharacter (char newChar, int locationChar);

  // PRE:
  // POST: RV is theString without the first character
  void removeFirstCharacter ();

  // PRE: location is equal to the index of the character in theString to be remvoed
  // POST: RV is theString without the character at the location given
  void removeLocationCharacter (int location);

  // PRE:
  // POST: RV is theString with the last character removed
  void removeLastCharacter ();

  bool subString (const MyString & pString);

  // ============================
  // operations
  // ============================

  // PRE: pString is the object that a deep copy is being made of
  // POST: RV is the object that is a deep copy of pString
  MyString & operator = (const MyString & pString);

  // PRE: pString is the object containing the strings
  // POST: RV is two strings appended together
  MyString operator + (const MyString & pString) const;

  // PRE: pStrng is a MyString object where it is defined
  // POST: RV is true iff pString has more characters or if
  //       the characters are equal pString contains comes after
  //       the other string
  bool operator < (const MyString pString) const;


  // PRE: pStrng is a MyString object where it is defined
  // POST: RV is true iff pString is less than the other string
  bool operator > (const MyString pString) const;


  // PRE: pStrng is a MyString object where it is defined
  // POST: RV is true iff pString is greater than the other
  //       string
  bool operator <= (const MyString pString) const;

  // PRE: pStrng is a MyString object where it is defined
  // POST: RV is ture if the strings are the same or if the
  //       first one is greater than pString
  bool operator >= (const MyString pString) const;

  // PRE: pStrng is a MyString object where it is defined
  // POST: RV is true iff both strings are the same
  bool operator == (const MyString pString) const;

  // ============================
  // Input/Output
  // ============================

  // PRE: stream is the kind of stream that theString of pString will be put into
  // POST: RV is theString in the OS stream
  friend ostream & operator << (ostream & stream, const MyString & string);

  // PRE: stream is the kind of stream that theString of pString will be put into
  // POST: RV is theString inputted with values from IS
  friend istream & operator >> (istream & stream, MyString & string);

  // ============================
  // destructors
  // ============================

  // PRE: These objects are defined
  // POST: These objects are destroyed
  ~MyString ();
};

#endif
