// CSCI 1300 Fall 2022
// Author: Danielle Swen
// Recitation: 202 – Christopher Ebuka Ojukwu
// Project 3 Tools.cpp

#include <iostream> 
#include "Tools.h"

using namespace std;

Tools::Tools()//default constructor
{
    string tool_1_="";
    string tool_2_="";
}

Tools::Tools(string tool_1, string tool_2)//parameterized constructor
{
    tool_1_=tool_1;
    tool_2_=tool_2;
}

/*setTool()
if the first position in the array is full, put the tool in the other position, else put it in the first position
Parameters- string tool
Returns- none
*/
void Tools::setTool(string tool)
{
    if (tools_bar_[0].length()!=0)
    {
        tools_bar_[1]=tool;
    }
    else
    {
        tools_bar_[0]=tool;
    }
}

/*getTools()
check how many tools are in the array, if only one, cout "net" or "rod", if no tools, cout "none", if both cout "both"
Parameters- none
Returns- string which_tools
*/
string Tools::getTools()
{
    int count=0;
    for (int i=0;i<2;i++)
    {
        if (tools_bar_[i].length()!=0)
        {
            count++;
        }
    }
    
    if (count==1)
    {
        return tools_bar_[0];
    }
    
    if (count==0)
    {
        return "none";
    }

    if (count==2)
    {
        return "both";
    }

    return "null";
}

/*netCondition()
go through array and if loop finds "net" return true, else return false
Parameters-none
Returns- bool true false whether has net or not
*/
bool Tools::netCondition()
{
    for (int i=0; i<2; i++)
    {
        if (tools_bar_[i]=="net")
        {
            return true;
        }
    }
    return false;
}

/*rodCondition()
go through array and if loop finds "rod" return true, else return false
Parameters-none
Returns- bool true false whether has rod or not
*/
bool Tools::rodCondition()
{
    for (int i=0; i<2; i++)
    {
        if (tools_bar_[i]=="rod")
        {
            return true;
        }
    }
    return false;
}

