// CSCI 1300 Fall 2022
// Author: Danielle Swen
// Recitation: 202 – Christopher Ebuka Ojukwu
// Project 3 Menu.h

#ifndef MENU_H  // match name of class
#define MENU_H  // internally to access class
#include <iostream> // have after #define
#include "Map.h"

using namespace std; 

/*Second highest class in the game, triggers every event (from areas). Uses map class to prompt different menu options. 
Can access maps, areas, stats, items, tools. 
*/

class Menu {

public: 
Menu();

//different menu types
void AreaMenu();
void NPCMenu();
void DefaultMenu();

//menu queue
void checkMenuType(); 

//value for player choosing quit
bool getEndValue();

/*INHERITANCE*/
Map MAP= Map();

private:
bool end_;
};
#endif