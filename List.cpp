//
//  List.cpp
//  CS260-Project1
//
//  Jake Romer
//  PCC Summer 2014
//  CS 260. Data Structures
//  Assignment 1: Inventory
//

#include "List.h"
#include <cstddef>
#include <new>

using namespace std;

List::List() : size(0), head(NULL) {};
List::~List(){ empty(); }

void List::empty(){
  while (!isEmpty()) remove(0);
}

bool List::isEmpty() const {
  return size == 0;
}

int List::length() const {
  return size;
}

// For debugging. Traverses list printing data items in an array-like format
void List::inspect() const {
  Node *cur = head;
  cout << "[ ";
  while(cur){
    cout << &cur->item;
    if (cur->next) {
      cout << ", ";
    }
    cur = cur->next;
  }
  cout << " ]" << endl;
}

// Traverses list printing data items
void List::print() const {
  Node *cur = head;
  while(cur){
    cout << cur->item;
    cur = cur->next;
  }
}

void List::insert(int index, dataType& newItem) throw (ListIndexOutOfRangeException, ListException){
  int newLength = length() + 1;

  if (index < 0 || index >= newLength)
    throw ListIndexOutOfRangeException("insert index is out of range");

  try {
    Node *newNode = new Node;
    size = newLength;
    newNode->item = newItem;

    // Special case: Attach new node to list
    if (index == 0) {
      newNode->next = head;
      head = newNode;
    }
    else {
      Node *prev = find(index - 1);
      newNode->next = prev->next;
      prev->next = newNode;
    }
  }
  catch (bad_alloc e) {
    throw ListException("insert cannot allocate memory.");
  }
}

void List::operator << (dataType& newItem){
  insert(length(), newItem);
}

void List::operator <= (dataType& newItem){
  int alphaPosn = findAlphaPosn(newItem);
  insert(alphaPosn, newItem);
}

void List::unshift(dataType& newItem){
  insert(0, newItem);
}

void List::remove(int index) throw (ListIndexOutOfRangeException, ListException){
  if (index < 0 || index >= length())
    throw ListIndexOutOfRangeException("remove index is out of range");

  Node *cur;
  --size;

  if (index == 0) {
    cur  = head;
    head = head->next;
  }
  else {
    Node *prev = find(index-1);
    cur = prev->next;
    prev->next = cur->next;
  }

  // return node to system
  cur->next = NULL;
  delete cur;
  cur = NULL;
}

List::Node *List::find(int index) const {
  if (index < 0 || index >= length())
    return NULL;

  Node *cur = head;
  for (int i = 0; i < index; ++i)
    cur = cur->next;
  return cur;
}

int List::find(dataType itemToFind) const {
  Node *cur = head;
  int currIdx = 0; // 0

  while (cur && itemToFind != cur->item) {
    currIdx++;
    cur = cur->next;
  }
  return (cur == NULL) ? -1 : currIdx;
}

int List::findAlphaPosn(dataType itemToInsert) const {
  if (isEmpty()) return 0;

  Node *cur = head;
  int index = 0;

  while (cur && itemToInsert > cur->item) {
    index++;
    cur = cur->next;
  }
  return index;
}

bool List::includes(dataType itemToFind) const {
  return find(itemToFind) != -1;
}

dataType List::retrieve(int index) const throw (ListIndexOutOfRangeException, ListException){
  if (index < 0 || index > length())
    throw ListIndexOutOfRangeException("retrieve index is out of range");
  Node *cur = find(index);
  return cur->item;
}

dataType& List::get(int index) const throw (ListIndexOutOfRangeException, ListException){
  if (index < 0 || index > length())
    throw ListIndexOutOfRangeException("retrieve index is out of range");
  Node *cur = find(index);
  return cur->item;
}

dataType& List::operator[] (int index) const throw (ListIndexOutOfRangeException, ListException){
  return get(index);
}
