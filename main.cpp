//
//  main.cpp
//  CS260-Project1
//
//  Jake Romer
//  PCC Summer 2014
//  CS 260. Data Structures
//  Assignment 1: Inventory
//

#include "Item.h"
#include "Inventory.h"
#include <iostream>

#ifdef _WIN32
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#endif

using namespace std;

void doTestBadData();
void doTestAdvanced();
void doTestBasic();
void AddItem(Inventory& inv,char* name,double weight);
void RemoveItem(Inventory& inv,char* name);
void keepConsoleOpen(){ cin.get(); }  // keeps console open in VC++

int main() {
	doTestBasic();
	doTestAdvanced();
	doTestBadData();

	#ifdef _WIN32
		if (_CrtDumpMemoryLeaks())
			cout << "Memory leaks!" << endl;
	  keepConsoleOpen();
	#endif

	return 0;
}


void AddItem(Inventory& inv,char* name,double weight){
	cout << "Adding " << name << " with a weight of " << weight << "." << endl;
	inv.AddItem(Item(name, weight));
}

void RemoveItem(Inventory& inv,char* name){
	cout << "Removing " << name << "." << endl;
	inv.RemoveItem(name);
}

void doTestBasic(){
	Inventory inv;

	// Make sure printing an empty inventory works
	inv.PrintInventory();

	// Make sure adding the first one works
	AddItem(inv,"helmet",5);
	inv.PrintInventory();

	// Add some more items
	AddItem(inv,"bracelet of power",1);
	AddItem(inv,"red potion",2);
	inv.PrintInventory();

	// Add some duplicates
	AddItem(inv,"bracelet of power",1);
	AddItem(inv,"red potion",2);
	inv.PrintInventory();

	// Add some heavy stuff
	AddItem(inv,"bag of gold coins",50);
	AddItem(inv,"bag of gold coins",50);

	// Now some removes
	RemoveItem(inv,"short sword");
	RemoveItem(inv,"helmet");
	RemoveItem(inv,"bracelet of power");
	inv.PrintInventory();
}

void doTestAdvanced(){
	Inventory inv;

	// Add items in reverse order
	AddItem(inv,"yellow potion",0.5);
	AddItem(inv,"trident",1.0);
	AddItem(inv,"helmet",1.0);
	AddItem(inv,"amulet",1.0);
	inv.PrintInventory();

	// Add items at the beginning, middle, end
	AddItem(inv,"aardvark skin",5.0);
	AddItem(inv,"newt's eye",0.1);
	AddItem(inv,"zebra feather",0.1);
	inv.PrintInventory();

	// Remove items at the beginning, middle, end
	RemoveItem(inv,"aardvark skin");
	RemoveItem(inv,"newt's eye");
	RemoveItem(inv,"zebra feather");
	inv.PrintInventory();

	// Add items with different case
	AddItem(inv,"helmet",1.0);
	AddItem(inv,"Helmet",1.0);
	AddItem(inv,"HELMET",1.0);
	inv.PrintInventory();

	// Remove items with case insensitivity
	RemoveItem(inv,"HELMET");
	inv.PrintInventory();
}

void doTestBadData(){
	Inventory inv(50);

	// Adding too much
	AddItem(inv,"bag of gold coins",50);	// should work
	AddItem(inv,"feather",0.1);						// should fail
	inv.PrintInventory();
	RemoveItem(inv,"bag of gold coins");	// should work
	inv.PrintInventory();

	// Using long strings
	AddItem(inv,"this is such a long item and nothing should have a name thing long but we have no guarantee that some crazy person wouldn't make such an item and then we need to make sure our program doesn't break.  Hint: don't use char[] to store data.  Only use char*.",1.0);
	inv.PrintInventory();

	// Same item with wrong weight
	AddItem(inv,"helmet",1.0);
	AddItem(inv,"helmet",10.0);
	inv.PrintInventory();
}
