//
//  ListExceptionOutOfRangeException.h
//  CS260-Project1
//
//  Jake Romer
//  PCC Summer 2014
//  CS 260. Data Structures
//  Assignment 1: Inventory
//

#ifndef List_ListIndexOutOfRangeException_h
#define List_ListIndexOutOfRangeException_h

#include <stdexcept>
#include <string>

using namespace std;

class ListIndexOutOfRangeException : public out_of_range {
public:
  ListIndexOutOfRangeException(const string &message = "") : out_of_range(message.c_str()) {
  }
};

#endif
