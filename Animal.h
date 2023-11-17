// CSCI 1300 Fall 2022
// Author: Danielle Swen
// Recitation: 202 – Christopher Ebuka Ojukwu
// Project 3 Animal.h

#ifndef ANIMAL_H  // match name of class
#define ANIMAL_H  // internally to access class
#include <iostream> // have after #define
#include "Menu.h"


using namespace std; 

/*Animal is top file that runs the whole game
The order is Animal -> Menu -> Map -> Areas -> Stats -> Items -> Tools
Created an object of one class in the class higher (in public), so the higher classes can access the lower ones, can go from Animal -> Tools, but not Tools -> Animal
Can access menu, map, areas, stats, items, tools.
*/
class Animal {

public: 
Animal();//default constructor

//set game
void startGame();


/*INHERITANCE*/
Menu MENU= Menu();

private:
};
#endif