// CSCI 1300 Fall 2022
// Author: Danielle Swen
// Recitation: 202 – Christopher Ebuka Ojukwu
// Project 3 Menu.cpp

#include <iostream> // have after #define
#include "Menu.h"
#include "Map.h"

using namespace std;

Menu::Menu()//default constructor
{
    end_=false;
}

/*randomNumbers()
uses rand() and outputs a randome number in between the min and max value
Parameters: int minimum value, int maximum value
Returns: random number int*/
int randomNumbers(int min, int max);

//getter for end value (true or false)
bool Menu::getEndValue()
{
    return end_;
}

/*DefaultMenu()
switch case for default menu
appears when no npc and no areas
player can move, find a villager, explore, shake a tree, eat or quit
Parameters- none
Returns- none
*/
void Menu::DefaultMenu()
{
    char choice;
    cout << "" << endl;
    cout << "===========Menu===========" << endl;
    cout << "(w,a,s,d) Move" << endl;
    cout << "2. Find a Villager" << endl;
    cout << "3. Explore" << endl;
    cout << "4. Shake a Tree" << endl;
    cout << "5. Eat" << endl;
    cout << "6. Quit" << endl;
    cin >> choice;

    switch(choice)// choose which
    {
        case('W'):
        case('A'):
        case('S'):
        case('D'):
        case('w'):
        case('a'):
        case('s'):
        case('d')://move, 20% chance of losing fullness
        {
            
            int rand_hunger=0;
            MAP.move(choice);
            rand_hunger=randomNumbers(1,5);
            if (rand_hunger==3)
            {
                MAP.AREAS.STATS.setFullness(0);
                cout << "Your fullness decreased by 10%." << endl;
                getchar();
            }
            break;
        }
        case('2')://find a villager queue villager game, if lose no money, if win, different chances of different money wins, 50% chance fullness decreases
        {
            int outcome=MAP.AREAS.Villager_game();
            int money=0;

            if(outcome==-2)
            {
                cout << "You recieved 0 bells." << endl; 
            }

            if(outcome==2)
            {
                int rod_bells=randomNumbers(1,10);
                if(rod_bells==2)
                {
                    money=250;// amnount for a rod
                    MAP.AREAS.STATS.setNumBells(money);
                    cout << "You recieved " << money << " bells!" << endl;
                    getchar();
                }

                int other_bells=randomNumbers(1,3);
                if(other_bells==1)
                {
                    MAP.AREAS.STATS.setNumBells(50);
                    cout << "You recieved 50 bells!" << endl;
                    getchar();
                }
                if(other_bells==2)
                {
                    MAP.AREAS.STATS.setNumBells(25);
                    cout << "You recieved 25 bells!" << endl;
                    getchar();
                }
                if(other_bells==3)
                {
                    MAP.AREAS.STATS.setNumBells(100);
                    cout << "You recieved 100 bells!" << endl;
                    getchar();
                }

                int health=randomNumbers(1,2);
                if (health==2)
                {
                    MAP.AREAS.STATS.setFullness(0);
                    cout << "Your fullness decreased by 10%" << endl;
                    getchar();
                }
            }
            break;
        }
        case('3')://explore
        {
            if (  MAP.isExplored(  MAP.getPlayerRow(),  MAP.getPlayerCol())==false)//check if its already explored
            {
                MAP.exploreSpace(  MAP.getPlayerRow(),  MAP.getPlayerCol());// if not explore
                int rand_explore=0;
                rand_explore=randomNumbers(1,10);//10% chance of making bank
                if (rand_explore==5)
                {
                    MAP.AREAS.STATS.setNumBells(175);
                    cout << "You found 175 bells!" << endl;
                    getchar();
                }

                rand_explore=randomNumbers(1,5);//20% chance of villager game
                if (rand_explore=4)
                {
                    int outcome=  MAP.AREAS.Villager_game();// queue villager game
                    int money=0;

                    if(outcome==-2)
                    {
                        cout << "You recieved 0 bells." << endl; 
                    }

                    if(outcome==2)
                    {
                        int rod_bells=randomNumbers(1,10);
                        if(rod_bells==2)
                        {
                            money=250;// amnount for a rod
                            MAP.AREAS.STATS.setNumBells(money);
                            cout << "You recieved " << money << " bells!" << endl;
                            getchar();
                        }

                        if(rod_bells<=10 && rod_bells>=5)
                        {
                        money=75;
                        MAP.AREAS.STATS.setNumBells(money);
                        cout << "You recieved " << money << " bells!" << endl;
                        getchar();   
                        }

                        if (rod_bells==3 || rod_bells==4)
                        {
                        money=100;
                        MAP.AREAS.STATS.setNumBells(money);
                        cout << "You recieved " << money << " bells!" << endl;
                        getchar();   
                        }

                        if(rod_bells==1)
                        {
                        money=25;
                        MAP.AREAS.STATS.setNumBells(money);
                        cout << "You recieved " << money << " bells!" << endl;
                        getchar();   
                       }
                    }   
                }
                else
                {
                    cout << "Nothing happened." << endl;
                    getchar();
                }
                rand_explore=randomNumbers(1,2);//50% chance fullness decrease
                if (rand_explore==2)
                {
                    MAP.AREAS.STATS.setFullness(0);
                    cout << "Your fullness decreased by 10%" << endl;
                    getchar();
                }
            }

            else
            {
                cout << "This area has already been explored." << endl;
                getchar();
            }
            break; 
        }
        case('4')://shake a tree random amount of fruit dropped
        {
            cout << "You walk over to the nearest tree and shake it." << endl;
            getchar();
            int random_fruit=randomNumbers(1,20);
            if (random_fruit>=1 &&random_fruit<=15)
            {
                MAP.AREAS.STATS.setFruitCount(3);
                cout << "You recieved 3 " <<   MAP.AREAS.STATS.getFruitNamePlural() << "!" <<endl;
                getchar();
            }
            if (random_fruit>=16&&random_fruit<=19)
            {
                MAP.AREAS.STATS.setFruitCount(2);
                cout << "You recieved 2 " <<   MAP.AREAS.STATS.getFruitNamePlural() << "!" <<endl;
                getchar();
            }
            if(random_fruit==20)
            {
                MAP.AREAS.STATS.setFruitCount(1);
                cout << "You recieved 1 " <<   MAP.AREAS.STATS.getFruitNamePlural() << "!" <<endl;
                getchar();  
            }

        break;              
        }
        case('5')://eat a fruit
        {
            int num_fruit=0;
            cout << "Each fruit increases your fullness by 5%" << endl;
            getchar();
            cout << "You are at " <<   MAP.AREAS.STATS.getFullness() << "% fullness and you have " << MAP.AREAS.STATS.getFruitCount() << " " << MAP.AREAS.STATS.getFruitNamePlural() << endl;
            getchar();
            cout << "How many " << MAP.AREAS.STATS.getFruitNamePlural() << " would you like to eat?" << endl;
            cin >> num_fruit;

            //valid value
            while (num_fruit<0)
            {
                cout << "Please enter a valid value." << endl;
                cin >> num_fruit;
            }

            //valid value not enough fruit
            while (num_fruit>  MAP.AREAS.STATS.getFruitCount())
            {
                cout << "You do not have enough " <<   MAP.AREAS.STATS.getFruitNamePlural() << endl;
                getchar();
                cout << "Please enter a valid value." << endl;
                cin >> num_fruit;
            }

            //add fullness
            MAP.AREAS.STATS.setFullness(num_fruit);
            cout << "Your fullness has been increased to " <<   MAP.AREAS.STATS.getFullness() << "%!" << endl;
            getchar();
            break;
        }
        case('6')://exit game
        {
            end_=true;
            break; 
        }
    }

if (choice!='6'&& MAP.AREAS.getAreasCompleted()!=5 && choice!='5')//decrease tom's patience besides when quit, he's already been beaten, or the player is eating
{
MAP.AREAS.STATS.setTomPatience();
cout << "Tom's patience decreased by 1%." << endl;
getchar();
}
}

/*NPCMenu()
either move, speak to npc, or quit
switch statement
npc queues villager game, npc puzzle and merchant
Parameters- none
Returns- none
*/
void Menu::NPCMenu()
{
    char choice;
    cout << "" << endl;
    cout << "===========Menu===========" << endl;
    cout << "(w,a,s,d) Move" << endl;
    cout << "2. Speak to NPC" << endl;
    cout << "3. Quit" << endl;
    cin >> choice;

    switch(choice)
    {
        case('W'):
        case('A'):
        case('S'):
        case('D'):
        case('w'):
        case('a'):
        case('s'):
        case('d'):// move, 20% chance of losing fullness
        {
            int rand_hunger=0;
            MAP.move(choice);
            rand_hunger=randomNumbers(1,5);
            if (rand_hunger==3)
            {
                MAP.AREAS.STATS.setFullness(0);
                cout << "Your fullness decreased by 10%." << endl;
                getchar();
            }
            break;
        }
        case('2')://npc queue puzzle, if they win puzzle queue merchant, if they lose, villager game is called, 50% chance health decrease
        {
            bool outcome=MAP.AREAS.NPC_puzzle();
            if (outcome==true)
            {
                MAP.AREAS.Merchant();
            }
            else
            {
                int outcome1=MAP.AREAS.Villager_game();
                int money=0;

                if(outcome1==-2)
                {
                    cout << "You recieved 0 bells." << endl; 
                }

                if(outcome==2)
                {
                    int rod_bells=randomNumbers(1,10);
                    if(rod_bells==2)
                    {
                        money=250;// amnount for a rod
                        MAP.AREAS.STATS.setNumBells(money);
                        cout << "You recieved " << money << " bells!" << endl;
                        getchar();
                    }

                    if(rod_bells<=10 && rod_bells>=5)
                    {
                        money=75;// amnount for a rod
                        MAP.AREAS.STATS.setNumBells(money);
                        cout << "You recieved " << money << " bells!" << endl;
                        getchar();   
                    }

                    if (rod_bells==3 || rod_bells==4)
                    {
                        money=100;// amnount for a rod
                        MAP.AREAS.STATS.setNumBells(money);
                        cout << "You recieved " << money << " bells!" << endl;
                        getchar();   
                    }

                    if(rod_bells==1)
                    {
                        money=25;// amnount for a rod
                        MAP.AREAS.STATS.setNumBells(money);
                        cout << "You recieved " << money << " bells!" << endl;
                        getchar();   
                    }
        
                }
               
                int health=randomNumbers(1,2);
                if (health==2)
                {
                    MAP.AREAS.STATS.setFullness(0);
                    cout << "Your fullness decreased by 10%" << endl;
                    getchar();
                }
            }
            MAP.removeNPC(  MAP.getPlayerRow(),  MAP.getPlayerCol());//remove npc if he's been talked to
            MAP.exploreSpace(  MAP.getPlayerRow(),  MAP.getPlayerCol());//mark space as explored
            break;
        }
        case('3')://quit game
        {
            end_=true;
            break;
        }
    }
if (choice!='3' && MAP.AREAS.getAreasCompleted()!=5)// decrease toms patience if the player is not quitting and if the player hasnt defeated him yet
{
MAP.AREAS.STATS.setTomPatience();
cout << "Tom's patience decreased by 1%." << endl;
getchar();
}
}

/*AreaMenu()
prompt move, enter area, quit
switch statement
Parameters-none
Returns- none
*/
void Menu::AreaMenu()
{
    char choice;
    cout << "" << endl;
    cout << "===========Menu===========" << endl;
    cout << "(w,a,s,d) Move" << endl;
    cout << "2. Enter Area" << endl;
    cout << "3. Quit" << endl;
    cin >> choice;

    switch(choice)
    {
        case('W'):
        case('A'):
        case('S'):
        case('D'):
        case('w'):
        case('a'):
        case('s'):
        case('d')://move, 20% chance fullness decrease
        {
            int rand_hunger=0;
            MAP.move(choice);
            rand_hunger=randomNumbers(1,5);
            if (rand_hunger==3)
            {
                MAP.AREAS.STATS.setFullness(0);
                cout << "Your fullness decreased by 10%." << endl;
                getchar();
            }
            break;
        }
        case('2'):// enter area, starts up area queue to see which game to play, if the player beats the room ,remove the area
        {
            bool resultarea=MAP.AREAS.area_queue();
           if (resultarea==true)
           {
            if(MAP.isRoomLocation(MAP.getPlayerRow(),MAP.getPlayerCol())==true)
            {
              MAP.removeRoom( MAP.getPlayerRow(), MAP.getPlayerCol());
            }
           }
            break;
        }
        case('3'):// end game
        {
            end_=true;
            break;
        }   
    }
if (choice!='3' && MAP.AREAS.getAreasCompleted()!=5)// decrease toms patience if the player doesnt quit and hasn't beaten tom
{
MAP.AREAS.STATS.setTomPatience();
cout << "Tom's patience decreased by 1%." << endl;
getchar();
}
}

/*checkMenuType()
sees which menu type to output based off of the map
if its a room location, it calls the area menu
if its not a room or NPC it calls the default menu
it its an NPC room, it calls the NPC menu
Parameters- none
Returns- none
*/
void Menu::checkMenuType()
{

    if (MAP.isRoomLocation(MAP.getPlayerRow(),MAP.getPlayerCol())==true)
    {
        AreaMenu();
    }

    else if ((MAP.isRoomLocation(MAP.getPlayerRow(),MAP.getPlayerCol())==false)&&(MAP.isNPCLocation(MAP.getPlayerRow(),MAP.getPlayerCol())==false))
    {
        DefaultMenu();
    }

    else if (MAP.isNPCLocation(MAP.getPlayerRow(),MAP.getPlayerCol())==true)
    {
        NPCMenu(); 
    }
}