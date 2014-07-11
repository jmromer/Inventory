//
//  Inventory.cpp
//  CS260-Project1
//
//  Jake Romer
//  PCC Summer 2014
//  CS 260. Data Structures
//  Assignment 1: Inventory
//

#include "Inventory.h"

// default constructor
Inventory::Inventory(int max) : maxWeight(max), curWeight(0), count(0) {}

// destructor empties the list
Inventory::~Inventory(){ items.empty(); }

// ------ PUBLIC API --------

// Adds an item as a new node or as a duplicate, if within carrying capacity
// Checks for weight mismatches and rejects if weights don't match
void Inventory::AddItem(Item newItem){
  bool isDuplicate   = items.includes(newItem);
  bool isLightEnough = isWithinCarryingCapacity(newItem);

  if (isLightEnough && isDuplicate) {
    if (noWeightMismatchFor(newItem)) addDuplicateItem(newItem);
  }
  else if (isLightEnough){
    addNewItem(newItem);
  }
}

// Removes or decrements item as appropriate
void Inventory::RemoveItem(char* name){
  int indexToRemove = items.find(Item(name));

  if (indexToRemove == -1)
    cout << "You don't have a " << name << " in your inventory." << endl;
  else {
    Item   foundItem  = --items[indexToRemove];
    double itemWeight = foundItem.getWeight();

    if (foundItem.getQty() == 0)
      items.remove(indexToRemove);

    count--;
    curWeight -= itemWeight;
    cout << "You dropped a " << name << "." << endl;
  }
}

int Inventory::GetCount() const{
  return count;
}

double Inventory::GetWeight() const{
  return curWeight;
}

void Inventory::PrintInventory() const {
  cout << "\nCurrent inventory:" << endl;

  if (items.length() == 0){
    cout << "\t(no items)\n" << endl;
  }
  else {
    items.print();
    cout.precision(5);
    cout << "Total items: "  << GetCount()  << endl;
    cout << "Total weight: " << GetWeight() << endl << endl;
  }
}

// ------ PRIVATE HELPER METHODS --------

// Returns true if the already-existing item has equal weight
bool Inventory::noWeightMismatchFor(Item newItem) const {
  Item foundItem = items[items.find(newItem)];
  if ( !areEqual(newItem.getWeight(), foundItem.getWeight()) ) {
    cout << "ERROR: tried to add a duplicate item with wrong weight!";
    return false;
  }
  else return true;
}

// Returns true if adding the newItem won't exceed carrying capacity
bool Inventory::isWithinCarryingCapacity(Item newItem) const {
  double prospectiveWeight = curWeight + newItem.getWeight();

  if (lessThanOrEqTo(prospectiveWeight, maxWeight))
    return true;
  else {
    cout << "You're not strong enough to pick up the "
         << newItem.getName()
         << " with everything else you're carrying." << endl;
    return false;
  }
}

// Increments the quantity for an already-existing item
void Inventory::addDuplicateItem(Item newItem) {
  Item& existingItem = items[items.find(newItem)];
  ++existingItem;
  count++;
  curWeight += existingItem.getWeight();
  cout << "You picked up a " << newItem.getName() << "." << endl;
}

// Adds a new item in alphabetical order
void Inventory::addNewItem(Item newItem) {
  items <= ++newItem;  // "<=" overloaded for 'pushing' into alpha-sorted position
  count++;
  curWeight += newItem.getWeight();
  cout << "You picked up a " << newItem.getName() << "." << endl;
}

// Epsilon-equality checkers for floats
bool Inventory::areEqual(double a, double b) const {
  return fabs(a - b) < 0.001;
}

bool Inventory::lessThanOrEqTo(double a, double b) const {
  return (a - b) < 0.001;
}

