//
//  List.h
//  CS260-Project1
//
//  Jake Romer
//  PCC Summer 2014
//  CS 260. Data Structures
//  Assignment 1: Inventory
//

#ifndef __List__List__
#define __List__List__

#include "Item.h"
#include "ListException.h"
#include "ListindexOutOfRangeException.h"
#include <iostream>
typedef Item dataType;

// disable VC++ warning about exceptions
#pragma warning(disable: 4290)

class List {
public:
  List();
  ~List();

  bool isEmpty() const;
  int  length()  const;
  void inspect() const;
  void print() const;
  int  find(dataType itemToFind) const;
  int  findAlphaPosn(dataType itemToInsert) const;
  bool includes(dataType itemToFind) const;

  void insert(int index, dataType& newItem) throw (ListIndexOutOfRangeException, ListException);
  void operator << (dataType& newItem);
  void operator <= (dataType& newItem);
  void unshift(dataType& newItem);
  void remove(int index) throw (ListIndexOutOfRangeException, ListException);
  void empty();

  dataType retrieve(int index) const throw (ListIndexOutOfRangeException, ListException);
  dataType& get(int index) const throw (ListIndexOutOfRangeException, ListException);
  dataType& operator[] (int index) const throw (ListIndexOutOfRangeException, ListException);

private:
  struct Node {
    dataType item;
    Node*    next;
  };
  int   size;
  Node* head;
  Node* find(int index) const;
};

#endif /* defined(__List__List__) */
