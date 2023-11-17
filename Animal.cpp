// CSCI 1300 Fall 2022
// Author: Danielle Swen
// Recitation: 202 – Christopher Ebuka Ojukwu
// Project 3 Animal.cpp

#include "Animal.h"
#include "Menu.h"
using namespace std; 

/*randomNumbers()
uses rand() and outputs a randome number in between the min and max value
Parameters: int minimum value, int maximum value
Returns: random number int*/
int randomNumbers(int min, int max);

/*
when game object is created, it will make a new map using startGame()
*/
Animal::Animal()//default constructor
{
    startGame();
}


/*startGame()
randomly generate 5 rooms and 2 npcs on the map
if the space is already taken (addRoom or addNPC returns false), it will generate a new random one until it returns true
12X12 map (0-11)
Parameters: none
Returns: none
*/
void Animal::startGame()
{
    srand(time(0));


    for(int i=0; i<5;i++)//addRoom
    {
        int ran_row=randomNumbers(0,11);
        int ran_col=randomNumbers(0,11);
        bool pass=MENU.MAP.addRoom(ran_row,ran_col);

        while(pass==false||ran_row==0&&ran_col==0)
        {
            ran_row=randomNumbers(0,11);
            ran_col=randomNumbers(0,11);
            MENU.MAP.addRoom(ran_row,ran_col);
        }
    }

    for(int i=0; i<2;i++)//addNPC
    {
        int ran_row1=randomNumbers(0,11);
        int ran_col1=randomNumbers(0,11);
        bool pass1=MENU.MAP.addNPC(ran_row1,ran_col1);

        while(pass1==false||ran_row1==0&&ran_col1==0)
        {
            ran_row1=randomNumbers(0,11);
            ran_col1=randomNumbers(0,11);
            MENU.MAP.addNPC(ran_row1,ran_col1);
        }
    }
}