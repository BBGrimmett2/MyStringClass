// This is the implementation of the MyString Class

#include "MyString.h"

#include <iostream>
using namespace std;

#define NEWLINE '\n'
#define EOS '\0'
#define SPACE ' '
#define TAB '\t'

// default constructor
// PRE:
// POST: theString = '\0' (CI is satisfied)
//       strLength = 0
//       arraySize = 1
MyString::MyString() {
  strLength = 0;
  // ASSERT: This object = 0
  arraySize = 1;
  // ASSERT: This object = 1

  theString = new char[arraySize];
  // ASSERT: The allocated memory for theString is equal to one

  theString[0] = '\0';
  // ASSERT: This object = '\0'. Thus, CI is satisfied
}

// copy constructor
// PRE: pString equals the string being copied
// POST: RV is a MyString with values copied from pString
MyString::MyString(const MyString & pString){
  strLength = pString.strLength;
  // ASSERT: strLength is equal to the length of pString

  arraySize = pString.arraySize;
  // ASSERT: arraySize is equal to the size allocated for the string

  theString = new char[strLength + 1];

  for (int index = 0; index <= strLength; index++) {
    theString[index] = pString.theString[index];
  }
  // ASSERT: theString has been copied
}

// ============================
// accessor functions
// ============================

// PRE:
// POST:
void MyString::copyString (MyString original, MyString copy){
  cout << "strLength or orignial = "  << original.strLength << endl;

  copy.strLength = original.strLength;

  cout << "arraySize of original = " << original.arraySize << endl;

  copy.arraySize = original.arraySize;

  for (int indexString = 0; indexString < original.strLength; indexString++) {
    copy.theString[indexString] = original.theString[indexString];
  }

}

// PRE: Locaiton is the index where the value of theString is targeted
// POST: OS contains the value at location in theString of pString
void MyString::printLocation (int location){
  cout << theString[location] << endl;
  // ASSERT: OS contains the value at location in theString
}

// PRE: string and pString are MyString objects
// POST: RV is true iff the string is a subset of the pString.
bool MyString::subString (const MyString & pString) {
  bool result = true;

  for (int indexStr = 0; indexStr < strLength; indexStr++) {
    if (theString[indexStr] != pString.theString[indexStr]) {
      if (theString[indexStr] != '*') {
        result = false;
      }
      // ASSERT: the characters are equal and the character is not an '*'
    }
  }

  return result;
}

// PRE: character is the object being searched for in MyString
// POST: RV is true iff character exists in theString
bool MyString::inString (char character) {
  bool exists = false; // holds the result if a character exists in theString

  for (int indexStr = 0; indexStr < strLength; indexStr++) {
    if (theString[indexStr] == character) {
      // ASSERT: character exists in theString
      exists = true;
    }
  }

  return exists;
}

// PRE: MyString object is defined
// POST: RV is the array of chars;
char * MyString::string () {
  char * charArray = new char[strLength];

  for (int indexStr = 0; indexStr < strLength; indexStr++) {
    charArray[indexStr] = theString[indexStr];
  }

  return charArray;
}

// ============================
// modifier functions
// ============================

// PRE: newChar is the character being added to theString
// POST: theString is updated and if needed it's memory allocation has been doubled iff
//       the strLength equals arraySize
void MyString::addCharacter (char newChar){
  strLength++; // increase string length because newChar is being added to theString

  // test to see if array is neeed of change
  if (strLength == arraySize) {
    // ASSERT: strLength equals arraySize
    //         will need to double array size

    char * temp = theString;
    // ASSERT: temp is an alias for theString

    arraySize = arraySize * 2;
    // ASSERT: the arraySize has been doubled

    theString = new char[arraySize];
    // ASSERT: theString's memory allocation has doubled

    for (int indexString = 0; indexString < (strLength - 1); indexString++) {
      theString[indexString] = temp[indexString];
    }

    // ASSERT: all values have been copied to theString

    delete [] temp;
    // ASSERT: temp is deleted off the heap
  }

  theString[strLength - 1] = newChar;
  // ASSERT: the new character has been added

  theString[strLength] = EOS;
  // ASSERT: the end of the string equals EOS
}

// PRE: newChar is the character to insert at the index equal to location
// POST: theString now contains newChar at the index location will all original values copied
//       around newChar
void MyString::insertCharacter (char newChar, int location) {
  strLength ++;

  for (int index = strLength; index > location; index--) {
    theString[index] = theString[index-1];
  }
  // ASSERT: theString's values were copied over one from location to strLength

  theString[location] = newChar;
  // ASSERT: theString[location] is equal to the newChar
}

// PRE:
// POST: RV is theString without the first character
void MyString::removeFirstCharacter (){
  strLength--;
  // ASSERT: the strLength has been shortned by one

  for (int indexString = 0; indexString < strLength; indexString++) {
    theString[indexString] = theString[indexString + 1];
  }
  // ASSERT: theString has been copied except for the first character

  theString[strLength] = EOS;
  // ASSERT: after the last character EOS is added
}

// PRE: location is equal to the index of the character in theString to be remvoed
// POST: RV is theString without the character at the location given
void MyString::removeLocationCharacter (int location){
  if (location < strLength) {
    strLength--;
    // ASSERT: the strLength has been shortened by one

    for (int indexString = location; indexString < strLength; indexString++) {
      theString[indexString] = theString[indexString + 1];
    }
    // ASSERT: all characters from location < strLength have been moved down one index

    theString[strLength] = EOS;
    // ASSERT: after the last character EOS is added

  }
}

// PRE:
// POST: RV is theString with the last character removed
void MyString::removeLastCharacter (){
  strLength--;
  // ASSERT: the strLength has been shortned by one

  for (int indexString = 1; indexString < strLength; indexString++) {
    theString[indexString] = theString[indexString];
  }
  // the string has been copied for all values except the last character

  theString[strLength] = EOS;
  // ASSERT: after the last character EOS is added
}

// ============================
// operations
// ============================

// <, >, ==, <=, >=

// PRE: pString is the object that a deep copy is being made of
// POST: RV is the object that is a deep copy of pString
MyString & MyString::operator = (const MyString & pString) {
  strLength = pString.strLength;
  // ASSERT: a copy of the strLength is made

  arraySize = pString.arraySize;
  // ASSERT: a copy of the arraySize is made

  for (int indexStr = 0; indexStr < strLength; indexStr++) {
    theString[indexStr] = pString.theString[indexStr];
  }
  // ASSERT: a copy of all values of theString is made

  return (*this);
}

// PRE: pString is the object containing the strings
// POST: RV is two strings appended together
MyString MyString::operator + (const MyString & pString) const {
  MyString answer;

  answer.strLength = (strLength + pString.strLength);
  // ASSERT: theString of answer is the length of the two strings added
  //         together
  answer.arraySize = (answer.strLength + 1);
  // ASSERT: the arraySize needs to be one more than the strLength of answer

  for (int indexStr = 0; indexStr < strLength; indexStr++) {
    answer.theString[indexStr] = theString[indexStr];
  }
  for (int indexStr = 0; indexStr < pString.strLength; indexStr++) {
    answer.theString[indexStr + strLength] = pString.theString[indexStr];
  }
  // ASSERT: all values from the two strings are copied to theString of the
  //         answer object

  return answer;
}

// PRE: pStrng is a MyString object where it is defined
// POST: RV is true iff pString has more characters or if
//       the characters are equal pString contains comes after
//       the other string
bool MyString::operator < (const MyString pString) const {
  bool result = true;

  if (strLength == pString.strLength) {
    // ASSERT: both string lengths are equal, test if all values in the strings
    //         are equal

    for (int indexStr = 0; indexStr < strLength; indexStr++) {
      char stringChar = theString[indexStr]; // holds test value from theString
      char pStringChar = pString.theString[indexStr]; // holds test value from
                                                      // pString

      if (stringChar != pStringChar) {
        // ASSERT: the values of the characters being test are not equal
        result = false;
      }
    }
    // ASSERT: Result equals true iff all values in strings are equal
    if (result = true) {
      result = false;
      // ASSERT: result equals false because if all values are equal then the
      //         string cannot be less than pString
    }
  }

  else if (strLength < pString.strLength) {
    // ASSERT: pString contains more letters than theString thus theString is
    //         less than pString
    result = true;
  }

  else {
    // ASSERT: theStrings are not equal and pString does not contain more values
    //         then theString
    int indexStr = 0; // holds index of string being tested in loop

    while (indexStr != strLength) {
      char stringChar = theString[indexStr]; // holds test value from theString
      char pStringChar = pString.theString[indexStr]; // holds test value from
                                                      // pString

      if (int(stringChar) > int(pStringChar)) {
        // ASSERT: the character in theString is greater than the character in
        //         pString
        result = false;
      }
      indexStr++;
    }
  }

  return result;
}

// PRE: pStrng is a MyString object where it is defined
// POST: RV is true iff pString is less than the other string
bool MyString::operator > (const MyString pString) const{
  bool result = true;

  if (strLength == pString.strLength) {
    // ASSERT: both string lengths are equal, test if all values in the strings
    //         are equal

    for (int indexStr = 0; indexStr < strLength; indexStr++) {
      char stringChar = theString[indexStr]; // holds test value from theString
      char pStringChar = pString.theString[indexStr]; // holds test value from
                                                      // pString

      if (stringChar != pStringChar) {
        // ASSERT: the values of the characters being test are not equal
        result = false;
      }
    }
    // ASSERT: Result equals true iff all values in strings are equal
    if (result = true) {
      result = false;
      // ASSERT: result equals false because if all values are equal then the
      //         string cannot be less than pString
    }
  }

  else if (strLength < pString.strLength) {
    // ASSERT: pString contains more letters than theString thus theString is
    //         less than pString
    result = false;
  }

  else {
    // ASSERT: theStrings are not equal and pString does not contain more values
    //         then theString
    int indexStr = 0; // holds index of string being tested in loop

    while (indexStr != strLength) {
      char stringChar = theString[indexStr]; // holds test value from theString
      char pStringChar = pString.theString[indexStr]; // holds test value from
                                                      // pString

      if (int(stringChar) < int(pStringChar)) {
        // ASSERT: the character in theString is greater than the character in
        //         pString
        result = false;
      }
      indexStr++;
    }
  }

  return result;
}


// PRE: pStrng is a MyString object where it is defined
// POST: RV is true iff pString is greater than the other
//       string
bool MyString::operator <= (const MyString pString) const{
  bool result = true;

  if (strLength == pString.strLength) {
    // ASSERT: both string lengths are equal, test if all values in the strings
    //         are equal

    for (int indexStr = 0; indexStr < strLength; indexStr++) {
      char stringChar = theString[indexStr]; // holds test value from theString
      char pStringChar = pString.theString[indexStr]; // holds test value from
                                                      // pString

      if (stringChar != pStringChar) {
        // ASSERT: the values of the characters being test are not equal
        result = false;
      }
    }
    // ASSERT: Result equals true iff all values in strings are equal
  }

  else if (strLength < pString.strLength) {
    // ASSERT: pString contains more letters than theString thus theString is
    //         less than pString
    result = true;
  }

  else {
    // ASSERT: theStrings are not equal and pString does not contain more values
    //         then theString
    int indexStr = 0; // holds index of string being tested in loop

    while (indexStr != strLength) {
      char stringChar = theString[indexStr]; // holds test value from theString
      char pStringChar = pString.theString[indexStr]; // holds test value from
                                                      // pString

      if (int(stringChar) > int(pStringChar)) {
        // ASSERT: the character in theString is greater than the character in
        //         pString
        result = false;
      }
      indexStr++;
    }
  }

  return result;
}


// PRE: pStrng is a MyString object where it is defined
// POST: RV is ture if the strings are the same or if the
//       first one is greater than pString
bool MyString::operator >= (const MyString pString) const{
  bool result = true;

  if (strLength == pString.strLength) {
    // ASSERT: both string lengths are equal, test if all values in the strings
    //         are equal

    for (int indexStr = 0; indexStr < strLength; indexStr++) {
      char stringChar = theString[indexStr]; // holds test value from theString
      char pStringChar = pString.theString[indexStr]; // holds test value from
                                                      // pString

      if (stringChar != pStringChar) {
        // ASSERT: the values of the characters being test are not equal
        result = false;
      }
    }
    // ASSERT: Result equals true iff all values in strings are equal
  }

  else if (strLength < pString.strLength) {
    // ASSERT: pString contains more letters than theString thus theString is
    //         less than pString
    result = false;
  }

  else {
    // ASSERT: theStrings are not equal and pString does not contain more values
    //         then theString
    int indexStr = 0; // holds index of string being tested in loop

    while (indexStr != strLength) {
      char stringChar = theString[indexStr]; // holds test value from theString
      char pStringChar = pString.theString[indexStr]; // holds test value from
                                                      // pString

      if (int(stringChar) < int(pStringChar)) {
        // ASSERT: the character in theString is greater than the character in
        //         pString
        result = false;
      }
      indexStr++;
    }
  }

  return result;
}

// PRE: pStrng is a MyString object where it is defined
// POST: RV is true iff both strings are the same
bool MyString::operator == (const MyString pString) const{
  bool result = true;

  if (strLength != pString.strLength) {
    // ASSERT: both string lengths are  not equal
    result = false;
  }

  else {
    // ASSERT: both string lengths are equal, test if all values in the strings
    //         are equal

    for (int indexStr = 0; indexStr < strLength; indexStr++) {
      char stringChar = theString[indexStr]; // holds test value from theString
      char pStringChar = pString.theString[indexStr]; // holds test value from
                                                      // pString

      if (stringChar != pStringChar) {
        // ASSERT: the values of the characters being test are not equal
        result = false;
      }
    }
    // ASSERT: Result equals true iff all values in strings are equal
  }

  return result;
}

// ============================
// Input/Output
// ============================

// PRE: stream is the kind of stream that theString of pString will be put into
// POST: RV is theString in the OS stream
ostream & operator << (ostream & stream, const MyString & pString) {
  for (int indexString = 0; indexString < pString.strLength; indexString++) {
    stream << pString.theString[indexString];
    // ASSERT: stream contains pString.theString[indexString]
  }

  return stream;
}

// PRE: stream is the kind of stream that theString of pString will be put into
// POST: RV is theString inputted with values from IS
istream & operator >> (istream & stream, MyString & pString){
  char character = stream.get();
  // ASSERT: character is defined

  while ((character != NEWLINE) && (!stream.eof())) { // ADD EOF
    pString.addCharacter(character);
    // ASSERT: the character is added to theString in pString

    character = stream.get();
    // ASSERT: character is inputted from IS
  }

  return stream;
}

// ============================
// destructors
// ============================

// PRE: This object is defined
// POST: This object is destroyed
MyString::~MyString () {
  // cout << "Destructor called for object at address " << hex << this << dec << endl;

  delete [] theString;
  // ASSERT: theString is now deleted fromm the heap
}
