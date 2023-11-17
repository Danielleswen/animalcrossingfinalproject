// CSCI 1300 Fall 2022
// Author: Danielle Swen
// Recitation: 202 – Christopher Ebuka Ojukwu
// Project 3 Stats.cpp

#include <iostream> // have after #define
#include <cstdlib>
#include <array>
#include <fstream>
#include <vector>
#include <string>
#include "Stats.h"
#include "Items.h"

using namespace std;

/*randomNumbers()
uses rand() and outputs a randome number in between the min and max value
Parameters: int minimum value, int maximum value
Returns: random number int*/
int randomNumbers(int min, int max)
{
    return (rand() % (max - min + 1)) + min;
}

/*randomFruit()
chooses a random numbers 1-5, assigns a fruit and emoji
sets fruit plural, fruit capital, and fruit plural capital as well
Parameters- none
Returns- none
*/
void Stats::randomFruit()
{
    srand(time(0));
    int rand_fruit=0;
    rand_fruit=randomNumbers(1,5);
    if (rand_fruit==1)
    {
        fruit_="apple";
        fruit_emoticon_="🍎";
    }
    if (rand_fruit==2)
    {
        fruit_="cherry";
        fruit_emoticon_="🍒";
    }
    if (rand_fruit==3)
    {
        fruit_="orange";
        fruit_emoticon_="🍊";
    }
    if (rand_fruit==4)
    {
        fruit_="peach";
        fruit_emoticon_="🍑";
    }
    if (rand_fruit==5)
    {
        fruit_="pear";
        fruit_emoticon_="🍐";
    }

    if (fruit_== "cherry")
    {
        fruit_plural_= "cherries";
        fruit_plural_capital_="Cherries";
        fruit_name_capital_="Cherry";
    }   
    if (fruit_== "peach")
    {
        fruit_plural_= "peaches";
        fruit_plural_capital_="Peaches";
        fruit_name_capital_="Peach";
    }  
    if (fruit_== "apple")
    {
        fruit_plural_= "apples";
        fruit_plural_capital_="Apples";
        fruit_name_capital_="Apple";
    }  
    if (fruit_=="pear" )
    {
        fruit_plural_="pears";
        fruit_plural_capital_="Pears";
        fruit_name_capital_="Pear";
    }  
    if (fruit_== "orange")
    {
        fruit_plural_="oranges";
        fruit_plural_capital_="Oranges";
        fruit_name_capital_="Orange";
    }  
}


Stats::Stats()//default constructor
{
    num_bells_ = 300;
    tom_patience_ = 100;
    fullness_ = 100;
    fruit_count_ = 0;
    shell_count_ = 0;
    flower_count_ = 0;
    bug_count_ = 0;
    fish_count_ = 0;
    username_ = "";
    fruit_="";
    fruit_emoticon_ = "";
    fruit_plural_="";
    discount_=0;
    debt_=0;
    fruit_plural_capital_="";
    fruit_name_capital_="";
    fruit_count_final_=0;
    shell_count_final_=0;
    flower_count_final_=0;
    bug_count_final_=0;
    fish_count_final_=0; 
    randomFruit();// choose a random fruit
}

Stats::Stats(int num_bells, int tom_patience, int fullness, int fruit_count, int shell_count, int flower_count, int bug_count, int fish_count, string username, string fruit,string fruit_emoticon, string fruit_plural, int discount, int debt, string fruit_plural_capital, string fruit_name_capital, int fruit_count_final, int shell_count_final, int flower_count_final, int bug_count_final, int fish_count_final)//parameterized constructor
{
    num_bells_ = num_bells;
    tom_patience_ = tom_patience;
    fullness_ = fullness;
    fruit_count_ = fruit_count;
    shell_count_ = shell_count;
    flower_count_ = flower_count;
    bug_count_ = bug_count;
    fish_count_ = fish_count;
    username_ = username;
    fruit_ = fruit;
    fruit_emoticon_=fruit_emoticon;
    fruit_plural_=fruit_plural;
    discount_=discount;
    debt_=debt;
    fruit_plural_capital_=fruit_plural_capital;
    fruit_name_capital_=fruit_name_capital;
    fruit_count_final_=fruit_count_final;
    shell_count_final_=shell_count_final;
    flower_count_final_=flower_count_final;
    bug_count_final_=bug_count_final;
    fish_count_final_=fish_count_final; 
}

/*split1() 
takes in a string and splits it up based off of a seperator character and puts the different segments into an array
***ran into problems with split and whitespace in files, works the same as split(), except the files have the seperator at the end of the line, rather than split(where it doesn't)
Parameters: string input_string to seperate, char separator for the function to find, string arr[] to put the segments in, int arr_size to make sure the array isn't overfilled
Returns: int number of splits
*/
int split1(string input_string, char separator, string arr[], int arr_size)
{
    string curString = ""; // set an empty string
    int num_of_splits = 0; // counter for splits

    if (input_string == "") // if there's no string
    {
        return 0; // return 0
    }

    for (int i = 0; i < input_string.length(); i++) // for loop for running through the string
    {

        if (input_string[i] != separator) // if the character is not the separator
        {
            curString = curString + input_string[i]; // add the character to the empty string
        }

        if (input_string[i] == separator) // if the character is the separator
        {
            arr[num_of_splits] = {curString}; // put the string in the array
            curString = "";                   // make the string empty again
            num_of_splits += 1;               // add one to position in array
        }
    }

    if (num_of_splits >= arr_size) // if the number of times seperated is greater than the array, return -1
    {
        return -1;
    }
    if (num_of_splits == 0) // if the string was never seperated, put the whole string in position 0 in array and return 1
    {
        arr[0] = input_string;
        return 1;
    }

    // arr[num_of_splits] = curString; // put the rest of the string in the array
    // num_of_splits++;                // add to position in array

    return num_of_splits; // return the number of splits/positions
}

//setter for number of bells
void Stats::setNumBells(int bells)
{
    num_bells_ = num_bells_ + bells;
}

//getter for number of bells
int Stats::getNumBells()
{
    return num_bells_;
}

//setter for toms patience no parameter!
bool Stats::setTomPatience() // automatic amount (1% at a time)
{
    if (tom_patience_ > 0)// no negatives
    {
        tom_patience_ = tom_patience_ - 1;
        return true;
    }
    else
    {
        return false;
    }
}

//setter/adds tom patience vs other with no parameter(automatic)
void Stats::addTomPatience(int how_much)
{
    tom_patience_=tom_patience_+how_much;// add however much
}

//get tom patience
int Stats::getTomPatience()
{
    return tom_patience_;
}

//set debt beginning of game, depending on how big the house
void Stats::setDebt(int choice_)
{    
    srand(time(0));

    if (choice_==1)
    {
        debt_=randomNumbers(1000,2500);
    }
    else if (choice_==2)
    {
        debt_=randomNumbers(3000,4000);
    }
    else if(choice_==3)
    {
        debt_=randomNumbers(4000,5000);
    }
}

//get debt
int Stats::getDebt()
{
    return debt_;
}

//set fullness, if 0 fruit eaten, the fullness decreases, if more than 0 were eaten it increases 5% for each fruit
void Stats::setFullness(int how_many_fruit_eaten)
{
    if (how_many_fruit_eaten == 0)
    {
        fullness_ = fullness_ - 10; // percentage
    }

    if (how_many_fruit_eaten > 0)
    {
        fullness_ = fullness_ + (how_many_fruit_eaten * 5);
    }

    fruit_count_ = fruit_count_ - how_many_fruit_eaten;
}

//get fullness
int Stats::getFullness()
{
    return fullness_;
}

//set fruit count- add
void Stats::setFruitCount(int fruit_count) // add to object
{
    fruit_count_ = fruit_count_ + fruit_count;
}

//get fruit count
int Stats::getFruitCount()
{
    return fruit_count_;
}

/*setShellCount()
adds how many shells recieved to shell count
opens shell file and assigns random shells to each shell collected
Parameter- int how many shells
Returns- none 
*/
void Stats::setShellCount(int how_many_shells) // add item get random shells
{
    srand(time(0));
    shell_count_ = shell_count_ + how_many_shells;

    if (how_many_shells > 0)
    {
        for (int i = 0; i < shell_count_; i++)
        {
            ifstream fin1;          // like cin for files
            string line1;           // create a string for the line within the file
            string array1[100000];  // big array
            fin1.open("shell.txt"); // open the file

            int rand1 = randomNumbers(1, 6);//6 possible shell options

            while (getline(fin1, line1))
            {
                if (stoi(line1.substr(0, 1)) == rand1)
                {
                    split1(line1, ',', array1, 3);
                    ITEMS.setItemInventory(Items(array1[1], "shell", stoi(array1[2])));
                }
            }
            fin1.close(); // close the file
        }
    }
}

//get shell count
int Stats::getShellCount()
{
    return shell_count_;
}

/*setFlowerCount()
adds how many flowers recieved to flower count
opens flower file and assigns random flowers to each flower collected
Parameter- int how many flowers
Returns- none 
*/
void Stats::setFlowerCount(int how_many_flowers) // add item get random shells
{
    srand(time(0));
    flower_count_ = flower_count_ + how_many_flowers;

    if (how_many_flowers > 0)
    {

        for (int i = 0; i < flower_count_; i++)
        {
            ifstream fin2;           // like cin for files
            string line2;            // create a string for the line within the file
            string array2[100000];   // big array
            fin2.open("flower.txt"); // open the file
            
            int rand2 = randomNumbers(1, 8);// 8 possible flower options

            while (getline(fin2, line2))
            {
                if (stoi(line2.substr(0, 1)) == rand2)
                {
                    split1(line2, ',', array2, 3);
                    ITEMS.setItemInventory(Items(array2[1], "flower", stoi(array2[2])));
                }
            }
         fin2.close(); // close the file
        }
    }
}

//get flower count
int Stats::getFlowerCount()
{
    return flower_count_;
}

/*setBugCount()
adds how many bugs recieved to bug count
opens bug file and assigns random bugs to each bug collected
Parameter- int how many bugs
Returns- none 
*/
void Stats::setBugCount(int how_many_bugs) // add item get random BUGD
{
    srand(time(0));
    bug_count_ = bug_count_ + how_many_bugs;

    if (how_many_bugs > 0)
    {
        for (int i = 0; i < bug_count_; i++)
        {
            ifstream fin3;         // like cin for files
            string line3;          // create a string for the line within the file
            string array3[100000]; // big array
            fin3.open("bug.txt");  // open the file

            int rand3 = randomNumbers(1, 28);// 28 possible bug options

            while (getline(fin3, line3))
            {
                if (stoi(line3.substr(0, 2)) == rand3)
                {
                    split1(line3, ',', array3, 3);
                    ITEMS.setItemInventory(Items(array3[1], "bug", stoi(array3[2])));
                }
            }
            fin3.close();
        }
    }
}

//get bug count
int Stats::getBugCount()
{
    return bug_count_;
}

/*setFishCount()
adds how many fish recieved to fish count
opens fish file and assigns random fish to each fish collected
Parameter- int how many fish
Returns- none 
*/
void Stats::setFishCount(int how_many_fish) // add item get random shells
{
    srand(time(0));
    fish_count_ = fish_count_ + how_many_fish;

    if (how_many_fish > 0)
    {

        for (int i = 0; i < fish_count_; i++)
        {   
            ifstream fin4;         // like cin for files
            string line4;          // create a string for the line within the file
            string array4[100000]; // big array
            fin4.open("fish.txt");  // open the file
            
            int rand4 = randomNumbers(1, 23);//23 possible fish options

            while (getline(fin4, line4))
            {
                if (stoi(line4.substr(0, 2)) == rand4)
                {
                    split1(line4, ',', array4, 3);
                    ITEMS.setItemInventory(Items(array4[1], "fish", stoi(array4[2])));
                }
            }
            fin4.close();
        }
    }
}

//get fish count
int Stats::getFishCount()
{
    return fish_count_;
}

//set username
void Stats::setUsername(string username)
{
    username_ = username;
}

//get username
string Stats::getUsername()
{
    return username_;
}

//get fruit name
string Stats::getFruitName()
{
    return fruit_;
}

//get fruit emoji
string Stats::getFruitEmoticon()
{
    return fruit_emoticon_;
}

//set fruit name plural
void Stats::setFruitNamePlural()
{
    if (fruit_== "cherry")
    {
        fruit_plural_= "cherries";
    }   
    if (fruit_== "peach")
    {
        fruit_plural_= "peaches";
    }  
    if (fruit_== "apple")
    {
        fruit_plural_= "apples";
    }  
    if (fruit_=="pear" )
    {
        fruit_plural_="pears";
    }  
    if (fruit_== "orange")
    {
        fruit_plural_="oranges";
    }  
}

//get fruit name plural
string Stats::getFruitNamePlural()
{
    return fruit_plural_;
}

//get fruit name capital
string Stats::getFruitNameCapital()
{
    return fruit_name_capital_;
}

//get fruit name plural capital
string Stats::getFruitNamePluralCapital()
{
    return fruit_plural_capital_;
}

//set discount- modify debt
void Stats::setDiscount(int discount)
{
    discount_=discount;
    debt_=debt_-discount_;
}

//get discount
int Stats::getDiscount()
{
    return discount_;
}

//display the discount each turn
void Stats::DisplayStats()
{
    cout << "" << endl;
    cout << "🌱~🌱~🌱~🌱~🌱~🌱~🌱~🌱~🌱~🌱~🌱~🌱" << endl;
    cout << "" << endl;
    cout << username_ << "'s stats: " << endl;
    cout << "" << endl;
    cout << "=========================================" << endl;
    cout << "Number of Bells: " << num_bells_ << " 💰" << endl;
    //cout << "" << endl;
    cout << "Tom's Level of Patience: " << tom_patience_ << " 💥" << endl;
    //cout << "" << endl;
    cout << "Level of Fullness: " << fullness_ << " 🍴" <<  endl;
    //cout << "" << endl;
    cout << "Number of " << fruit_plural_capital_ << " Collected: " << fruit_count_ << " " << fruit_emoticon_ << endl;
    //cout << "" << endl;
    cout << "Number of Shells Collected: " << shell_count_ << " 🐚" << endl;
    //cout << "" << endl;
    cout << "Number of Flowers Picked: " << flower_count_ << " 🌷" << endl;
    //cout << "" << endl;
    cout << "Number of Bugs Caught: " << bug_count_ << " 🦋" << endl;
    //cout << "" << endl;
    cout << "Number of Fish Caught: " << fish_count_ << " 🐟" << endl;
    //cout << "" << endl;
    cout << "=========================================" << endl;
    cout << "" << endl;
    cout << "🌱~🌱~🌱~🌱~🌱~🌱~🌱~🌱~🌱~🌱~🌱~🌱" << endl;
    cout << "" << endl;
}

//saveStats() sets/saves the final items of the player
void Stats::SaveStats()
{
    fruit_count_final_=fruit_count_;
    shell_count_final_=shell_count_;
    flower_count_final_=flower_count_;
    bug_count_final_=bug_count_;
    fish_count_final_=fish_count_;   
}


/*displayScoreboard()
opens the scoreboard file and writes players stats to it
closes file
opens scoreboard file to read and displays scoreboard and then all of the stats from the file
*/
void Stats::displayScoreboard()
{
    ofstream fout;
    fout.open("scoreboard.txt", ios::app);
    //string input= username_ + "'s stats~ Debt: " + str(debt_) + " Final Bell Count: " + str(num_bells_) + " # of Fruit: " + str(fruit_count_final_) + " # of Shells: " + str(shell_count_final_) + " # of Flowers: " + str(flower_count_final_) + " # of Bugs: " + str(bug_count_final_) + " # of Fish: " + str(fish_count_final_);
    fout << username_ <<  "'s stats~ Debt: " << debt_ << "| Final Bell Count: " << num_bells_ << "| # of Fruit: " << fruit_count_final_ << "| # of Shells: " << shell_count_final_ << "| # of Flowers: " << flower_count_final_ << "| # of Bugs: " << bug_count_final_ << "| # of Fish: " << fish_count_final_ << endl;
    fout.close();

    cout << "" << endl;
    cout << "====SCOREBOARD====" << endl;

    ifstream fin5;         // like cin for files
    string line5;          // create a string for the line within the file
    fin5.open("scoreboard.txt");  // open the file
    while (getline(fin5, line5))
    {
        cout << line5 << endl;
    }
    fin5.close();
    cout << "" << endl;
}
