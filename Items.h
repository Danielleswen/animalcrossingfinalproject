// CSCI 1300 Fall 2022
// Author: Danielle Swen
// Recitation: 202 – Christopher Ebuka Ojukwu
// Project 3 Items.h

#ifndef ITEMS_H  // match name of class
#define ITEMS_H  // internally to access class
#include <iostream> // have after #define
#include <vector>
#include <cstdlib>
#include <fstream>
#include "Tools.h"

using namespace std; 

/*Items class holds a vector of all the items the player collects. It hold the name of the object, the type (bug, fish, flower, shell), and how much it is worth 
Can access tools.
*/

class Items {

public: 
Items();//default constructor
Items(string item_name, string item_type, int item_worth);//parameterized constructor

//set get item name
void setItemName(string item_name);
string getItemName();

//set get item type
void setItemType(string item_type);
string getItemType();

//set get item worth
void setItemWorth(int item_worth);
int getItemWorth();

//add/remove item from inventory
void setItemInventory(Items new_);
int removeItem(string item_name, string item_type);

//different inventory displays
string displaySpecificInventory(string type);
int displayEnd(string end);
void displayInventory();


/*INHERITANCE*/
Tools TOOLS;

private:
string item_name_;
string item_type_;
int item_worth_;
vector <Items> inventory_;

};
#endif