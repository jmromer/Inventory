//
//  str.cpp
//  CS260-Project1
//
//  Jake Romer
//  PCC Summer 2014
//  CS 260. Data Structures
//  Assignment 1: Inventory
//

#include "str.h"

// Constructor sets data member to the empty string
str::str() : text("") {}

// Copy constructor takes a string literal
str::str(const string original) : text(original) {}

// Copy constructor takes a str
str::str(const str &original) : text(original.text) {}

// Destructor
str::~str(){}

// str#downcased() - Downcases the string, without mutating the original
str str::downcased() const{
  string newstring = text;
  for (unsigned int i = 0; i < newstring.length(); i++) {
    if (islower(newstring[i], loc)) continue;
    else newstring[i] = tolower(newstring[i], loc);
  }
  return str(newstring);
}

// str#downcase() - Downcases the string, mutating the original
str& str::downcase(){
  for (unsigned int i = 0; i < text.length(); i++) {
    if (islower(text[i], loc)) continue;
    else text[i] = tolower(text[i], loc);
  }
  return *this;
}

// str#= - Overloads the assignment operator
str& str::operator=(const str &original){
  this->text = original.text;
  return *this;
}

// str#|| - Overloads the OR operator for string comparison
int str::operator || (const str other) {
  string otherString = other.downcased().text;
  int comparison = downcased().text.compare(otherString);

  if (comparison < 0)
    comparison = -1;
  else if (comparison > 0)
    comparison =  1;

  return comparison;
}

bool str::operator == (const str other) {
  return 0 == (*this || other);
}

bool str::operator < (const str other) {
  return -1 == (*this || other);
}

bool str::operator > (const str other) {
  return 1 == (*this || other);
}

// str#<< - Overloads the output stream operator
ostream& operator<<(ostream& os, const str& sstring){
  os << sstring.text;
  return os;
}


