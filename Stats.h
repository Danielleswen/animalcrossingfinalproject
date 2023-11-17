// CSCI 1300 Fall 2022
// Author: Danielle Swen
// Recitation: 202 – Christopher Ebuka Ojukwu
// Project 3 Stats.h

#ifndef STATS_H  // match name of class
#define STATS_H  // internally to access class
#include <iostream> // have after #define
#include <vector>
#include <cstdlib>
#include <fstream>
#include "Items.h"

using namespace std; 

/*keeps track of all of the players statistics. Number of bells/fish/hunger/bugs/shells/fruit/toms patience/flowers, their debt, username, fruit type
chooses a random fruit at the beginning of the game
Can access items, tools
*/

class Stats {

public:
Stats();//default constructor
Stats(int num_bells, int tom_patience, int fullness, int fruit_count, int shell_count, int flower_count, int bug_count, int fish_count, string username, string fruit,string fruit_emoticon, string fruit_plural, int discount, int debt,string fruit_plural_capital,string fruit_name_capital, int fruit_count_final, int shell_count_final, int flower_count_final, int bug_count_final, int fish_count_final);//parameterized constructor

//set get number of bells
void setNumBells(int bells); // - or + bells
int getNumBells();

//set get the debt
void setDebt(int choice);
int getDebt();

//set get, add tom patience(tom relaxer merchant())
bool setTomPatience();
int getTomPatience();
void addTomPatience(int how_much);

//set get fullness
void setFullness(int how_many_fruit_eaten);
int getFullness();

//set get fruit count
int getFruitCount();
void setFruitCount(int fruit_count);

//set get fruit count
int getShellCount();
void setShellCount(int shell_count);

//set get fruit count
int getFlowerCount();
void setFlowerCount(int flower_count);

//set get fruit count
int getBugCount();
void setBugCount(int bug_count);

//set get fruit count
int getFishCount();
void setFishCount(int fruit_count);

//set get username
void setUsername(string username);
string getUsername();

//choose random fruit set fruit name
void randomFruit();

//get fruitname
string getFruitName();

//get fruit emoji
string getFruitEmoticon();

//get fruit name in plural
string getFruitNamePlural();

//set fruit name plural
void setFruitNamePlural();

//get capital fruit name plural
string getFruitNamePluralCapital();

//get singular fruit name capital
string getFruitNameCapital();

//set get discount(manipulates debt_)
void setDiscount(int discount);
int getDiscount();

//display stats every turn
void DisplayStats();

//save stats(before phase 3 of game) display scoreboard at end of game
void SaveStats();
void displayScoreboard();


/*INHERITANCE*/
Items ITEMS= Items();

private:
int num_bells_;
int tom_patience_;
int fullness_;
int fruit_count_;
int shell_count_;
int flower_count_;
int bug_count_;
int fish_count_;
string username_;
string fruit_;
string fruit_emoticon_;
string fruit_plural_;
int discount_;
int debt_;
string fruit_plural_capital_;
string fruit_name_capital_;
int fruit_count_final_;
int shell_count_final_;
int flower_count_final_;
int bug_count_final_;
int fish_count_final_;
};
#endif