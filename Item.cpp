//
//  item.cpp
//  CS260-Project1
//
//  Jake Romer
//  PCC Summer 2014
//  CS 260. Data Structures
//  Assignment 1: Inventory
//

#include "Item.h"

Item::Item() : name(str()), weight(0), qty(0){}
Item::Item(char* name, double wt) : name(str(name).downcase()), weight(wt), qty(0){}
Item::~Item(){}

// Increments the quantity for the given item
Item& Item::operator++() {
  qty++;
  return *this;
}

// Decrements the quantity for the given item
Item& Item::operator--() {
  qty--;
  return *this;
}

// Checks for name-based equality. Names are stored downcased.
bool Item::operator == (Item other) {
  return name == other.name;
}

// Checks for name-based inequality. Names are stored downcased.
bool Item::operator != (Item other) {
  return !(name == other.name);
}

// Name-based alphabetical-order comparison.
// Returns -1 if LHS comes first, 1 if RHS comes first, 0 if equal
int Item::operator || (Item other) {
  return name || other.name;
}

// Name-based alphabetical-order comparison.
// Returns true if RHS comes first in order
bool Item::operator > (Item other) {
  return name > other.name;
}

// Defines how items are printed to standard output
ostream& operator << (ostream& os, const Item& itemToPrint){
  os << "\t[" << itemToPrint.qty << "] " << itemToPrint.name << endl;
  return os;
}

int Item::getQty() const {
  return qty;
}

double Item::getWeight() const {
  return weight;
}

str Item::getName() const {
  return name;
}
