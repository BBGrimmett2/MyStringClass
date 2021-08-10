MyStr: MyString.o useMyString.o
	g++ MyString.o useMyString.o -o MyStr

useMyString: MyString.h useMyString.cc
	g++ -c useMyString.cc

MyString: MyString.h MyString.cc
	g++ -c MyString.cc
