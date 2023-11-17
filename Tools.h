// CSCI 1300 Fall 2022
// Author: Danielle Swen
// Recitation: 202 – Christopher Ebuka Ojukwu
// Project 3 Tools.h

#ifndef TOOLS_H  // match name of class
#define TOOLS_H  // internally to access class
#include <iostream> // have after #define


using namespace std; 


/*Hold fishing rod and bug net in array
Cannot access any other class
*/

class Tools {

public: 
Tools();//default constructor
Tools(string tool_1, string tool_2);//parameterized constructor

//set get tools
string getTools();
void setTool(string tool);

//check the net condition
bool netCondition();

//check the rod condition
bool rodCondition();


private:
string tool_1_;
string tool_2_;
string tools_bar_[2];
};
#endif