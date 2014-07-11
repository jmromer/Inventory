//
//  ListException.h
//  CS260-Project1
//
//  Jake Romer
//  PCC Summer 2014
//  CS 260. Data Structures
//  Assignment 1: Inventory
//

#ifndef List_ListException_h
#define List_ListException_h

#include <stdexcept>
#include <string>

using namespace std;

class ListException : public logic_error {
public:
  ListException(const string &message = "") : logic_error(message.c_str()) {
  }
};

#endif
