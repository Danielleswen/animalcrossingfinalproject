// CSCI 1300 Fall 2022
// Author: Danielle Swen
// Recitation: 202 – Christopher Ebuka Ojukwu
// Project 3 Items.cpp

#include <iostream> // have after #
#include <vector>
#include <cstdlib>
#include <fstream>
#include "Tools.h"
#include "Items.h"


using namespace std;


Items::Items()//default constructor
{
    item_name_="";
    item_type_="";
    item_worth_=0;
}

Items::Items(string item_name, string item_type, int item_worth)//parameterized constructor
{
    item_name_=item_name;
    item_type_=item_type;
    item_worth_=item_worth;
}


/*split()
takes in a string and splits it up based off of a seperator character and puts the different segments into an array
Parameters: string input_string to seperate, char separator for the function to find, string arr[] to put the segments in, int arr_size to make sure the array isn't overfilled
Returns: int number of splits
*/
int split(string input_string, char separator, string arr[], int arr_size)
{
    string curString="";// set an empty string
    int num_of_splits=0;// counter for splits

    if (input_string=="")// if there's no string
    {
        return 0;// return 0
    }   

    for (int i=0; i<input_string.length(); i++)// for loop for running through the string
    {

        if(input_string[i] != separator)// if the character is not the separator
        {
            curString= curString + input_string[i];// add the character to the empty string
        }

        if(input_string[i]== separator)// if the character is the separator
        {
            arr[num_of_splits]={curString};// put the string in the array
            curString="";// make the string empty again
            num_of_splits+=1;// add one to position in array
        }
    }

if (num_of_splits>=arr_size)// if the number of times seperated is greater than the array, return -1
{
    return -1;
}
if (num_of_splits==0)// if the string was never seperated, put the whole string in position 0 in array and return 1
{
    arr[0]=input_string;
    return 1;
}

arr[num_of_splits]=curString;// put the rest of the string in the array
num_of_splits++;// add to position in array

return num_of_splits;// return the number of splits/positions
}

//add item to inventory vector
void Items::setItemInventory(Items new_)
{
    inventory_.push_back(new_);
}

/*removeItem()
goes through the inventory and matches up the item to be removed
removes the item
returns the worth of it
Parameters: string item_name, string item_type
Returns: worth of the item
*/
int Items::removeItem(string item_name, string item_type)
{
    for (int i=0; i<inventory_.size();i++)
    {
        if (inventory_[i].getItemType()==item_type&&inventory_[i].getItemName()==item_name)
        {
            int worth=inventory_[i].getItemWorth();
            inventory_.erase(inventory_.begin() + i);
            return worth;
        }
    }
    return 0;
}

/*displaySpecificInventory()
takes in a type and prints out every item of that type in a list to be used for merchant
takes in the players option for which they'd like to sell and returns the name of that item
(the merchant will then use the name of the item to find it in the vector and get the worth and erase it)
Parameters: string item type
Returns: string name of item
*/
string Items::displaySpecificInventory(string type)
{

    int choice=0;
    int counter=1;
    int array[100];
    int array_count=0;
    int inventory_pos=0;
    
    //list all of the items of that type
    for (int i=0; i<inventory_.size();i++)
    {
        if (inventory_[i].getItemType()==type)
        {
            cout << counter << ". " << inventory_[i].getItemName() << ": " << inventory_[i].getItemWorth() << " bells" << endl;
            array[array_count]=i;
            counter++;
            array_count++;
        }
    }
    
    //let player choose which to sell
    cout << (counter+1) << ". Exit" << endl;//exit option
    cin >> choice;

    //valid value
    while (choice<1||choice>counter+1)
    {
        cout << "Please enter a valid value." << endl;
        cin >> choice;
    }

    if (choice!=(counter+1))
    {
        inventory_pos=array[choice-1];
        return inventory_[inventory_pos].getItemName();
    }

    
    return "";

}

/*displayInventory()
tester function
couts every item in inventory vector
Parameters: none
Returns: none
*/
void Items::displayInventory()
{
    for (int i=0; i<inventory_.size(); i++)
    {
        cout << inventory_[i].getItemName() << ": " << inventory_[i].getItemWorth() << " bells" << endl;
    }
}

/*displayEnd()
takes in the type and displays each item of that type without the list of numbers in front
used for Nooks_Crannyend()
removes items from inventory after theyve been cout, add up all the money they're making
Parameters- string item type
Returns- int total money
*/
int Items::displayEnd(string type)
{
    int total_money=0;
    for (int i=0; i<inventory_.size();i++)
    {
        if (inventory_[i].getItemType()==type)
        {
            cout << inventory_[i].getItemName() << ": " << inventory_[i].getItemWorth() << " bells" << endl;
            total_money=total_money+inventory_[i].getItemWorth();
            inventory_[i].removeItem(inventory_[i].getItemName(),inventory_[i].getItemType());
        }
    }

    return total_money;

}

//set item name
void Items::setItemName(string item_name)
{
    item_name_=item_name;
}

//get item name
string Items::getItemName()
{
    return item_name_;
}

//set item type
void Items::setItemType(string item_type)
{
    item_type_=item_type;
}

//get item type
string Items::getItemType()
{
    return item_type_;
}

//set item worth
void Items::setItemWorth(int item_worth)
{
    item_worth_=item_worth;
}

//get item worth
int Items::getItemWorth()
{
    return item_worth_;
}


