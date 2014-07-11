//
//  Item.h
//  CS260-Project1
//
//  Jake Romer
//  PCC Summer 2014
//  CS 260. Data Structures
//  Assignment 1: Inventory
//

#ifndef __CS260_Project1__Item__
#define __CS260_Project1__Item__

#include "str.h"
#include <iostream>

class Item {
public:
  Item();
  Item(char* name, double wt = 0);
  ~Item();

  int    getQty() const;
  double getWeight() const;
  str    getName() const;

  Item& operator++();
  Item& operator--();
  bool  operator == (Item other);
  bool  operator != (Item other);
  int   operator || (Item other);
  bool  operator >  (Item other);

  friend ostream& operator << (ostream& os, const Item& itemToPrint);

private:
  str    name;
  int    qty;
  double weight;
};


#endif /* defined(__CS260_Project1__Item__) */
