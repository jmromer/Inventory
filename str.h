//
//  str.h
//  CS260-Project1
//
//  Jake Romer
//  PCC Summer 2014
//  CS 260. Data Structures
//  Assignment 1: Inventory
//

#ifndef __str__str__
#define __str__str__

#include <iostream>
#include <string>
#include <locale>

using namespace std;

class str {
public:
  str();
  str(const string original);
  str(const str &original);
  ~str();

  str  downcased() const;
  str& downcase();
  str& operator = (const str &original);

  int    operator || (const str other);
  bool   operator == (const str other);
  bool   operator <  (const str other);
  bool   operator >  (const str other);
  friend ostream& operator << (ostream& os, const str& sstring);

private:
  string text;
  locale loc;
};

#endif /* defined(__str__str__) */
