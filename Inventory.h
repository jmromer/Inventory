//
//  Inventory.h
//  CS260-Project1
//
//  Jake Romer
//  PCC Summer 2014
//  CS 260. Data Structures
//  Assignment 1: Inventory
//

#ifndef __CS260_Project1__Inventory__
#define __CS260_Project1__Inventory__

#include "Item.h"
#include "List.h"
#include <iostream>
#include <math.h>

class Inventory {
public:
  Inventory(int max = 100);
  ~Inventory();

  void   AddItem(Item newItem);
  void   RemoveItem(char* name);
  double GetWeight() const;
  int    GetCount()  const;
  void   PrintInventory() const;

private:
  double curWeight;
  int    maxWeight;
  int    count;
  List   items;

  bool noWeightMismatchFor(Item newItem) const;
  bool isWithinCarryingCapacity(Item newItem) const;
  void addDuplicateItem(Item newItem);
  void addNewItem(Item newItem);
  bool areEqual(double a, double b) const;
  bool lessThanOrEqTo(double a, double b) const;
};

#endif /* defined(__CS260_Project1__Inventory__) */
