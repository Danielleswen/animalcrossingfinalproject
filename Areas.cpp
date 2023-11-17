// CSCI 1300 Fall 2022
// Author: Danielle Swen
// Recitation: 202 – Christopher Ebuka Ojukwu
// Project 3 Areas.cpp

#include <iostream>
#include <fstream>
#include <string>
#include <array>
#include <cstdlib> // have after #define
#include "Areas.h"
#include "Stats.h"

using namespace std;

Areas::Areas()// default constructor
{
    areas_completed_=0;
    npc_completed_=0;
    flick_answer_="";
    cj_answer_="";
    flick_riddle_="";
    cj_riddle_="";
    villager_name_="";
    villager_emote_="";
}

Areas::Areas(int areas_completed, int npc_completed, string flick_answer, string cj_answer, string flick_riddle, string cj_riddle, string villager_name, string villager_emote) // parameterized constructor
{
    areas_completed_=areas_completed;
    npc_completed_=npc_completed;
    flick_answer_=flick_answer;
    cj_answer_=cj_answer;
    flick_riddle_=flick_riddle;
    cj_riddle_=cj_riddle;
    villager_name_=villager_name;
    villager_emote_=villager_emote;
}

/*randomNumbers()
uses rand() and outputs a randome number in between the min and max value
Parameters: int minimum value, int maximum value
Returns: random number int*/
int randomNumbers(int min, int max);

//setter for areas_completed_
void Areas::setAreasCompleted(int previous_completed)
{
    areas_completed_++;
}

//getter for areas_completed
int Areas::getAreasCompleted()
{
    return areas_completed_;
}

//setter for npc_completed_
void Areas::setNPCCompleted(int how_many)
{
    npc_completed_=how_many;
}

//getter for npc_completed_
int Areas::getNPCCompleted()
{
    return npc_completed_;
}

/*split()
takes in a string and splits it up based off of a seperator character and puts the different segments into an array
Parameters: string input_string to seperate, char separator for the function to find, string arr[] to put the segments in, int arr_size to make sure the array isn't overfilled
Returns: int number of splits
*/
int split(string input_string, char separator, string arr[], int arr_size);


/*split1() 
takes in a string and splits it up based off of a seperator character and puts the different segments into an array
***ran into problems with split and whitespace in files, works the same as split(), except the files have the seperator at the end of the line, rather than split(where it doesn't)
Parameters: string input_string to seperate, char separator for the function to find, string arr[] to put the segments in, int arr_size to make sure the array isn't overfilled
Returns: int number of splits
*/
int split1(string input_string, char separator, string arr[], int arr_size);


/*Leif()
called when the player doesn't have what they need to get into an area
generates 3 random numbers in between 1 and 200
player has to guess which one is correct
if they get it right, Leif() returns true, if not returns false
Parameters: none
Returns: bool true or false whether they got it right or not
*/
bool Leif()
{
    srand(time(0));
    char choice;
    int true1=randomNumbers(1,200);// only 1 is right
    int false1=randomNumbers(1,200);//false
    int false2=randomNumbers(1,200);//false
    int guess=0;
    int smallest=0;
    int middle=0;
    int big=0;


    cout << "" << endl;
    getchar();
    cout << "You hear a rustle to your left..." << endl;
    getchar();
    cout << "..." << endl;
    getchar();
    cout << "Leif 🦥: 'Woah there, what're you doing? You don't have what you need to get in there!'" << endl;
    getchar();
    cout << "Leif 🦥: 'But...'" << endl;
    getchar();
    cout << "Leif 🦥: '...if you can win my game I can let it slide and let you in.'" << endl;
    getchar();
    cout << "Leif 🦥: 'Do you wanna play?' Y/N " << endl;
    cin >> choice;
    
    //they do want to play
    if(choice=='Y'||choice=='y')
    {
        getchar();
        cout << "Leif 🦥: 'Oh goody. We'll play Guess How Many Weeds Leif Has Pulled In The Past Hour'"<< endl;
        getchar();
        cout << "Leif 🦥: 'You've heard of it right?'" << endl;
        getchar();
        cout << "Leif 🦥: 'I'll give you three options and you have to guess which one is the actual number.'" << endl;
        getchar();


        //in case any of the numbers are the same- generate until they aren't
        while(true1==false1)
        {
           true1=randomNumbers(1,200); 
        }
        while(true1==false2)
        {
            true1=randomNumbers(1,200); 
        }
        while(false1==false2)
        {
            false2=randomNumbers(1, 200);
        }


        //rank the 3 numbers from smallest to biggest
        if(true1>false1&&true1>false2)
        {
            if(false1>false2)
            {
                smallest=false2;
                middle=false1;
                big=true1;
            }

            if(false2>false1)
            {
                smallest=false1;
                middle=false2;
                big=true1;
            }
        }

        if(false1>true1&&false1>false2)
        {
            if(true1>false2)
            {
                smallest=false2;
                middle=true1;
                big=false1;
            }

            if(false2>true1)
            {
                smallest=true1;
                middle=false2;
                big=false1;
            }
        }

        if(false2>false1&&false2>true1)
        {
            if(false1>true1)
            {
                smallest=true1;
                middle=false1;
                big=false2;
            }

            if(true1>false1)
            {
                smallest=false1;
                middle=true1;
                big=false2;
            }
        }

        if(true1!=false1 && true1!=false2 && false1!=false2)
        {
            //output smallest to largest to add randomness (correct one isn't in the same position every time)
            cout << "Leif 🦥: 'I pulled "<< smallest << ", " << middle << ", or "<< big << ". Which one?'" << endl;
            cin >> guess;

            //valid input
            while(guess!=true1 && guess!=false1 && guess!=false2)
            {
                cout << "Please enter a valid value" << endl;
                cin >> guess;
            }

            //if their guess is correct
            if (guess==true1)
            {
                getchar();
                cout << "Leif 🦥: 'Congrats! You did it! I pulled " <<  true1 << " weeds!'" << endl;
                getchar();
                cout << "Leif 🦥: 'Lemme let you in!'" << endl;
                getchar();
                return true; 
            }

            //they lose
            else
            {
                getchar();
                cout << "Leif 🦥: 'Aww, too bad. I actually pulled " << true1 << " weeds.'" << endl;
                getchar();
                cout << "Leif 🦥: 'Better luck next time!'" << endl;
                getchar();
                cout << "You returned to your previous path." << endl;
                getchar();
                return false;
            }
        }
        return false;
    }

    //they don't want to play
    if (choice=='N'||choice=='n')
    {
        cout << "Leif 🦥: 'Well good luck out there!'" << endl;
        getchar();
        return false;
    }

    return false;
}

/*Beach()
first area the player enters
depending on how many fruit they have, a number is randomly generated for how many seashells they get
if the player doesn't have the key (3 fruits) the leif function is called
if they win leif or have the key they get to enter
gulliver asks the player if they'll help him find his radio parts
if y- continue if n- he takes bells from him and return false
if y- run through game and gulliver gives them shells and increment areas_completed and return true
add number of shells to inventory 
Parameters - int how_many_fruit the player has
Returns- bool true or false finish area or not
*/
bool Areas::Beach(int how_many_fruit)
{
    srand(time(0));
    char choice;
    int how_many_seashells=0;
    string next="";
    bool let_in;

    if (how_many_fruit>=6)
    {
        how_many_seashells= rand() % 10 + 5;
    }
    else if (how_many_fruit>=3&& how_many_fruit<6)
    {
        how_many_seashells= rand() % 5 + 1;
    }
    else if(how_many_fruit<3)
    {
        how_many_seashells=rand() % 3 + 1;
    }


    if (how_many_fruit<3)
    {
        let_in=Leif();
    }

    if (how_many_fruit>=3||let_in==true)//they have enough fruit or won the leif game
    {   
        cout << "You reach the beach and look out at the beautiful shoreline and see a ..." << endl;
        getchar();
        cout << "... pelican pirate laying in the sand?" << endl;
        getchar();
        cout << "You approach the pirate and nudge him with your foot." << endl;
        getchar();
        cout << "Gulliver 🦢: '...'" << endl;
        getchar();
        cout << "You nudge again." << endl;
        getchar();
        cout << "Gulliver 🦢: '... hello?'" << endl;
        getchar();
        cout << "Gulliver 🦢: 'WOAH!!! I seemed to have fell off me ship again.'" << endl;
        getchar();
        cout << "Gulliver 🦢: 'Will ye help me find me radio pieces so I can call me mateys?'" << endl;
        getchar();
        cout << "Gulliver 🦢: 'If you do I'll give ye a reward'" << endl;
        getchar();
        cout << "Gulliver 🦢: 'Will ye help me?' (Y/N)" << endl;
        cin >> choice;

        if (choice=='N'||choice=='n')//take bells
        {
            cout << "Gulliver 🦢: 'Arrrr blast ye.'" << endl;
            getchar();
            cout << "Well, ye might as well give me some of yer bells then so I can buy a new one." << endl;//mod bells
            getchar();
            if ( STATS.getNumBells()<=20)//if they don't have enough bells
            {
                cout << "Gulliver 🦢: 'Well.. er.. that's embarrassing. Even I have a couple more bells but err that's okay.' " << endl;
                getchar();
            }
            else
            {
                cout << "Gulliver 🦢: 'I'll just take 20 from ye. Thanks, matey.'" << endl;
                getchar();
                STATS.setNumBells(-20);
                cout << "You now have " << STATS.getNumBells() << " bells." << endl;
                getchar();
            }

            cout << "Gulliver 🦢: 'Well, come help me soon.'" << endl;
            getchar();
            return false;
        }
        else if (choice=='Y'||choice=='y')//they choose yes
        {
            getchar();
            cout << "Gulliver 🦢: 'Why thank ye, matey'" << endl;
            getchar();
            cout << "You and Gulliver walk through the sand searching for his radio parts." << endl;
            getchar();
            cout << "He paces back and forth methodically until he kicks something with his foot." << endl;
            getchar();
            cout << "He reaches down..." << endl;
            getchar();
            cout << "Gulliver 🦢: 'I FOUND ONE!!!'" << endl;
            getchar();
            cout << "Gulliver 🦢: 'Only four more, matey'" << endl;
            getchar();
            cout << "This continues for the next hour until all the parts are found." << endl;
            getchar();
            cout << "Gulliver 🦢: 'Thank ye for yer help'" << endl;
            getchar();
            cout << "Gulliver 🦢: 'Here, have " << how_many_seashells << " of me most prized seashells'" << endl;
            getchar();
            cout << "You got " << how_many_seashells << " seashells!" << endl;
            getchar();
            cout << "You continue on your way." << endl;
            getchar();

            STATS.setShellCount(how_many_seashells);
            areas_completed_++;
            return true;
        }

    }
    return false;
}

/*Meadow()
second area the player enters
if the player doesn't have the key (100 bells) the leif function is called 
if they win leif or have the key they get to enter
game queues (picking petals he loves me he loves me not)- a random number is chosen either 4 or 5
if 4- player loses flower- cout each he loves me he loves me not
if 5- player wins flower- cout each he loves me he loves me not increment number of flowers
add number of flowers to inventory increment areas completed return true
Parameters - int how_many_bells the player has
Returns- bool true or false finish area or not (only false if they lose leif)
*/
bool Areas::Meadow(int how_many_bells)
{
    srand(time(0));
    int how_many_flowers=0;
    bool let_in;

if (how_many_bells<100)
{
    let_in=Leif();
}

if (how_many_bells>=100||let_in==true)
{
    cout << "" << endl;
    cout << "You cross a wooden bridge and a grand meadow appears." << endl;
    getchar();
    cout << "There are hills of flowers as far as the eye can see!" << endl;
    getchar();
    cout << "You look to your left and see Fauna the Deer waving you over!" << endl;
    getchar();
    cout << "Fauna 🦌: 'Over here, deery!'" << endl;
    getchar();
    cout << "Fauna 🦌: 'Let's play a game! 'He loves me, he loves me not.' You have ten tries to win.'" << endl;
    getchar();
    cout << "Fauna 🦌: 'I'm gonna give you a flower and you pick the petals and alternate 'he loves me, he loves me not' and if it ends on 'he loves me' I'll give you one of my flowers!'" << endl;
    getchar();
    cout << "Fauna 🦌: 'Ready, deery?'" << endl;
    getchar();

    for (int i=1; i<11; i++)// display the flower number the player is on
    {
        cout << "Fauna 🦌: 'Flower number " << i << "!'" << endl;
        getchar();

        int rand=randomNumbers(4,5);

        if (rand==5)
        {
            for (int i=rand; i>0; i--)// start at 5 and go down and cout the correct number
            {
                if(i%2==1)
                {
                    cout << "He loves me!" << endl;
                    getchar(); 
                }
                if (i%2==0)
                {
                    cout << "He loves me not." << endl;
                    getchar(); 
                }        
            }
            cout << "Fauna 🦌: 'You win this flower, deery!'" << endl;
            getchar();
            how_many_flowers++;
        }

        if (rand==4)
        {
            for (int i=rand; i>0; i--)// start at 4 and go down and cout the correct number
            {
                if(i%2==0)
                {
                    cout << "He loves me!" << endl;
                    getchar(); 
                }
                if (i%2==1)
                {
                    cout << "He loves me not." << endl;
                    getchar(); 
                }        
            }
            cout << "Fauna 🦌: 'Aww, I win this flower.'" << endl;
            getchar();
        }
    }

cout << "Fauna 🦌: 'Congratulations, deery! You won " << how_many_flowers << " flowers!'" << endl;
STATS.setFlowerCount(how_many_flowers);
areas_completed_++;
return true;
}
return false;
}

/*Forest()
third area the player enters
if the player doesn't have the key (the net condition returns true (they have a net)) the leif function is called 
if they win leif or have the key they get to enter
game queues (catching bugs)- a random number is chosen either 1 or 2
if 1- the direction is left
if 2- the direction is right
if the player chooses the correct option increment bugs caught
add number of bugs to inventory increment areas completed return true
Parameters - bool net_condition the player has a net or not
Returns- bool true or false finish area or not (only false if they lose leif)
*/
bool Areas::Forest(bool net_condition)//catch bugs 
{
srand(time(0));
int correct_direction=0;
char choice;
bool let_in;
int bug_count=0;

if (net_condition==false)
{
    let_in=Leif();
}

if (net_condition==true ||let_in==true)
{
cout << "You hear 'Welcome to the forest!' from behind a tree." << endl;
getchar();
cout << "You look around it and see Lily the Frog!" << endl;
getchar();
cout << "Lily 🐸: 'Hey, toady! I'm Lily!'" << endl;
getchar();
cout << "Lily 🐸: 'Come catch some bugs with me!'" << endl;
getchar();
cout << "Lily 🐸: 'All you have to do is swat your net where you think the bug is going and hope you catch it!'" << endl;

for (int i=0; i<10; i++)// repeat ten times with ten tries to catch a bug
{
    correct_direction=randomNumbers(1,2); 
    getchar();
    cout << "Lily 🐸: 'Swat either left or right!!' L/R" << endl;
    cin >> choice;
    
    while (choice!='L'&& choice!='R'&& choice!='l' && choice!='r')// valid value
    {
        cout << "Please enter a valid value." << endl;
        cin >> choice;
    }

    if (correct_direction==1)//bug is to the left
    {
        if(choice=='L'||choice=='l')//they guess correctly
        {
            bug_count++;
            cout << "Lily 🐸: 'Yay! You got it, toady!'" << endl;
            getchar();
        }
        else
        {
            cout << "Lily 🐸: 'You missed, toady!'" << endl;
            getchar();
        }

    }

    if (correct_direction==2)// bug is to the right
    {
        if(choice=='R'||choice=='r')//they guess correctly
        {
            bug_count++;
            cout << "Lily 🐸: 'Yay! You got it, toady!'" << endl;
            getchar();
        }
        else
        {
            cout << "Lily 🐸: 'You missed, toady!'" << endl;
            getchar();
        }
    }
}

getchar();
cout<< "Lily 🐸: 'You caught " << bug_count << " bug(s), toady!'" << endl;
getchar();
STATS.setBugCount(bug_count);
areas_completed_++;
return true;
}
return false;
}

/*River()
fourth area the player enters
if the player doesn't have the key (the rod condition returns true (they have a rod)) the leif function is called 
if they win leif or have the key they get to enter
game queues (fish size competition)
player inputs a positive integer for their size of fish in between 1-100 
random number is chosen either 1 or 2
if 1- comparing who has the bigger fish 
if 2- comparing who has the smaller fish
randomly generate the competitors fish size and then compare them
if the fish size= the players size- regenerate
if the player wins the comparison increment number of fish
add number of fish to inventory increment areas completed return true
Parameters - bool rod_condition the player has a rod or not
Returns- bool true or false finish area or not (only false if they lose leif)
*/
bool Areas::River(bool rod_condition)
{
    srand(time(0));
    bool let_in;
    int fish_size=0;
    int big_o_small=0;
    int contestant=0;
    int fish_count=0;

if (rod_condition==false)
{
    let_in=Leif();
}

if (rod_condition==true ||let_in==true)// cant have else here or it won't run if they win leif 
{
    cout << "Welcome to the Annual Paradise Island Fishing Tournament!" << endl;
    getchar();
    cout << "Molly 🦆: 'I'm Molly the Duck and I'll be your host today!'" << endl;
    getchar();
    cout << "Molly 🦆: 'We'll now go ahead and randomly compare sizes of fish! If you win the comparison you'll get a fish!'" << endl;
    getchar();
    cout << "Molly 🦆: 'Be aware, because your fish might have to be bigger OR smaller than someone else's'" << endl;
    getchar();
    cout << "Molly 🦆: 'Now what size fish did you catch?' integer between 1-100 (inches)" << endl;
    cin >> fish_size;
    
    while (fish_size<1 || fish_size>100)// valid value
    {
        cout << "Please enter a valid value." << endl;
        cin >> fish_size;
    }

    cout << "Molly 🦆: 'Let the games begin!'" << endl;
    getchar();

    for (int i=1; i<11; i++)//repeat for 10 fish
    {
        big_o_small=randomNumbers(1,2);
        getchar();
        cout << "Molly 🦆: 'Contestant " << i << "!'" << endl;
        getchar();

        if (big_o_small==1)//bigger fish
        {
            cout << "Molly 🦆: 'This round is seeing who has the bigger fish.'" << endl;
            getchar();
            contestant=randomNumbers(1,100);//generate competitors
           
            while (contestant==fish_size)// make sure not equal
            {
                contestant=randomNumbers(1,100);
            }
           
            cout << "Molly 🦆: 'Contestant " << i << "'s fish is " << contestant << " inches long and yours is " << fish_size << " inches long.'" << endl;
            getchar();

            //who wins
            if (contestant>fish_size)
            {
                cout << "Molly 🦆: 'Contestant " << i << "'s fish wins!" << endl;
            }

            else
            {
                cout << "Molly 🦆: 'Your fish wins!'" << endl;
                fish_count++;
            }
        }

        if (big_o_small==2)//smaller fish
        {
            cout << "Molly 🦆: 'This round is seeing who has the smaller fish.'" << endl;
            getchar();
            
            contestant=randomNumbers(1,100);//competitors fish
            
            while (contestant==fish_size)// not equal
            {
                contestant=randomNumbers(1,100);
            }

            cout << "Molly 🦆: 'Contestant " << i << "'s fish is " << contestant << " inches long and yours is " << fish_size << " inches long.'" << endl;
            getchar();

            //who wins
            if (contestant<fish_size)
            {
                cout << "Molly 🦆: 'Contestant " << i << "'s fish wins!" << endl;
            }

            else
            {
                cout << "Molly 🦆: 'Your fish wins!'" << endl;
                fish_count++;
            }

        }
    }
    getchar();
    cout<< "Molly 🦆: 'Congrats! You won " << fish_count << " fish at our tournament today!'" << endl;
    STATS.setFishCount(fish_count);
    areas_completed_++;
    return true;
}
    return false;
}

/*Tom_challenge() ***boss battle***
no key to enter - no leif
calculation competition
lvl 1 - 2 digit multiplication 
lvl 2 - 3 digit multiplication
lvl 3- 3 digit multiplication and subtraction
lvl 4 - 4 digit multiplication and subtraction and addition
each level generates random numbers to be used
if the player gets the answer right, increment wins, number of wins affects debt discount
set new discount
Parameters - none
Returns- bool true
*/
bool Areas::Tom_challenge()
{
    srand(time(0));
    int wins=0;
    int discount=0;
    cout << "Tom Nook 🦝: 'So you think you've got enough to pay off your debt?'" << endl;
    getchar();
    cout << "Tom Nook 🦝: 'We'll see about that. If you can calculate some equations correctly, maybe I'll give you a discount.'" << endl;
    getchar();
    cout << "Tom Nook 🦝: 'Well let's get to it.'" << endl;
    getchar();

    //lvl 1
    int lvl1num=randomNumbers(2,20);
    int lvl1num2=randomNumbers(1,20);
    int lvl1cin=0;

    cout << "Tom Nook 🦝: 'How much will it cost if you buy " << lvl1num << " pairs of sunglasses at " << lvl1num2 << " bells each?'" << endl;
    cin>>lvl1cin;
    getchar();

    if(lvl1cin!=(lvl1num*lvl1num2))// player incorrect
    {

        cout << "Tom Nook 🦝: '... well, all I can say is... the correct answer is " << (lvl1num*lvl1num2) <<  "'" << endl;
        getchar();
        cout << "Tom Nook 🦝: '...good luck with the next one.'" << endl;
        getchar();
    }
    else//player correct
    {
        wins++;
        cout << "Tom Nook 🦝: 'My eyes decieve me. You got it right?'" << endl;
        getchar();
        cout << "Tom Nook 🦝: 'It's probably just luck. The next one will be harder.'" << endl;
        getchar();
    }


    //lvl 2
    int lvl2num=randomNumbers(30,100);
    int lvl2num2=randomNumbers(30,100);
    int lvl2cin=0;

    cout << "Tom Nook 🦝: 'Let's try this now. How many apples are there in... " << lvl2num << " baskets of " << lvl2num2 << " apples?'" << endl;
    cin >> lvl2cin;
    getchar();

    if(lvl2cin!=(lvl2num*lvl2num2))//player incorrect
    {
        cout << "Tom Nook 🦝: 'HA! You really thought you'd out-wit me. Nice try, nice try.'" << endl;
        getchar();
        cout << "Tom Nook 🦝: The correct answer is " << (lvl2num*lvl2num2) << "'" << endl;
        getchar();
    }
    else//player win
    {
        wins++;
        cout << "Tom Nook 🦝: 'Good luck with that one, I-'" << endl;
        getchar();
        cout << "Tom Nook 🦝: 'oh... well... well... how about this.'" << endl;
        getchar();
    }
    
    //lvl3
    int lvl3num=randomNumbers(30,100);
    int lvl3num2=randomNumbers(30,100);
    int lvl3num3=randomNumbers(500,100);
    int lvl3cin=0;

    cout << "Tom Nook 🦝: What is' " << lvl3num << " times " << lvl3num2 << " minus " << lvl3num3 << "?'" << endl;
    cin >> lvl3cin;
    getchar();

    if(lvl3cin!=((lvl3num*lvl3num2)-lvl3num3))//player incorrect
    {
        cout << "Tom Nook 🦝: 'Fantastic news, fantastic. Oh I mean, I'm sorry, you'll definitely get the next one.'" << endl;
        getchar();
        cout << "Tom Nook 🦝: The correct answer is " << ((lvl3num*lvl3num2)-lvl3num3) << "'" << endl;
        getchar();

    }
    else//player wins
    {
        wins++;
        cout << "Tom Nook 🦝: 'Well, I applaud you. There's still one more challenge you have to pass though.'" << endl;
        getchar();
    }

    //lvl 4
    int lvl4num=randomNumbers(500,1000);
    int lvl4num2=randomNumbers(500,1000);
    int lvl4num3=randomNumbers(1000,5000);
    int lvl4num4=randomNumbers(0,5000);
    int lvl4cin=0;

    cout << "Tom Nook 🦝: 'My last question. What is the total of " << lvl4num << " times " << lvl4num2 << " minus " << lvl4num3 << " plus " << lvl4num4 << "?'" << endl;
    cin >> lvl4cin;
    getchar();

    if(lvl4cin!=((lvl4num*lvl4num2)-lvl4num3+lvl4num4))//player incorrect
    {
        cout << "Tom Nook 🦝: 'Tsk tsk tsk, that is too bad. I guess you aren't cut out for the full discount.'" << endl;
        getchar();
        cout << "Tom Nook 🦝: The correct answer is " << ((lvl4num*lvl4num2)-lvl4num3+lvl4num4) << "'" << endl;
        getchar();
    }
    else//player wins
    {   
      wins++;
      cout << "Tom Nook 🦝: 'Alrighty then, maybe you do have some skill. Let's calculate your discount now'" << endl; 
      getchar();      
    }

    //calculate debt reduction
    if (wins==0)
    {
        discount=0;
    }
    if(wins==1)
    {
        discount=100;
    }
    if(wins==2)
    {
        discount=200;
    }
    if(wins==3)
    {
        discount=300;
    }
    if(wins==4)
    {
        discount=400;
    }

    cout << "Tom Nook 🦝: 'You answered " << wins << " out of 4 questions correctly. You qualify for a " << discount << " bell reduction of your debt.'" << endl;
    getchar();
    STATS.setDiscount(discount);
    areas_completed_++;
    return true;
}

/*area_queue()
find the correct area to queue in gameplay by accessing the number of areas the player has completed
set result equal to the different functions and return that
Parameters - not
Returns- bool true or false whether the area queued was finished or not
*/
bool Areas::area_queue()
{
    bool result;
    if (areas_completed_==0)
    {
        result=Beach(STATS.getFruitCount());
        return result;
    }
    else if (areas_completed_==1)
    {
        result=Meadow(STATS.getNumBells());
        return result;
    }
    else if (areas_completed_==2)
    {
        result=Forest(STATS.ITEMS.TOOLS.netCondition());
        return result;
    }
    else if (areas_completed_==3)
    {
        result=River(STATS.ITEMS.TOOLS.rodCondition());
        return result;
    }
    else if (areas_completed_==4)
    {
        result=Tom_challenge();
        return result;
    }

    return false;
}



/*NPC_puzzle()
if the npc completed is 0 queue flick if the player has already seen an npc it will queue cj
choose random number between 1 and 5 to choose riddle from file
cout riddle and take in player answer
if answer is wrong return false
if answer is correct return true
Parameters - none
Returns- bool true or false if they win or not
*/
bool Areas::NPC_puzzle()
{
srand(time(0));
int rand= randomNumbers(1,5);

if (npc_completed_==0)
{
    ifstream fin;// like cin for files
    string line;// create a string for the line within the file
    string array[100000];// big array
    string guess="";
    fin.open("flick.txt");// open the file

    cout << "Flick 🦎: 'Hey, I'm Flick. I LOVE bugs! I'll sell ya some things and buy some from you if you can answer my riddle!'" << endl;
    getchar();


    while(getline(fin, line))
    {
        if (stoi(line.substr(0,1))==rand)
        {
            split1(line, '~', array, 3);
            flick_riddle_=array[2];
            flick_answer_=array[1];
        }
    }

    cout << "Flick 🦎: 'Here it is:'" << endl;
    getchar();

    cout << "Flick 🦎: '" << flick_riddle_ << " '(all lowercase, no plural words)"<<endl;

    
    cin >> guess;

    if (flick_answer_==guess)
    {
        cout << "Flick 🦎: 'You got it!'" << endl;
        return true;
    }

    else
    {
        getchar();
        cout << "Flick 🦎: 'Oh too bad. The correct answer is: " << flick_answer_ << "'" <<endl;
        getchar();
        cout << "Flick 🦎: 'Better luck next time!'" << endl;
        getchar();
        return false;
    }
    npc_completed_++;
    fin.close();//close the file
}

else if (npc_completed_==1)
{
    ifstream fin1;// like cin for files
    string line1;// create a string for the line within the file
    string array1[100000];// big array
    string guess1="";
    fin1.open("cj.txt");// open the file

    cout << "CJ 🦦: 'Hey, I'm CJ. I LOVE fish! I'll sell ya some things and buy some from you if you can answer my riddle!'" << endl;
    getchar();


    while(getline(fin1, line1))
    {
        int stoif=stoi(line1.substr(0,1));
        if (stoif==rand)
        {
            split1(line1, ',', array1, 3);
            cj_riddle_=array1[2];
            cj_answer_=array1[1];
        }
    }

    cout << "CJ 🦦: 'Here it is:'" << endl;
    getchar();

    cout << "CJ  🦦: '" << cj_riddle_;
    cout << "' (all lowercase, no plural words)" <<endl;
    cin >> guess1;

    if (guess1==cj_answer_)
    {
        cout << "CJ 🦦: 'You got it!'" << endl;
        return true;
    }

    else
    {
        cout << "CJ 🦦: 'Oh too bad. The correct answer was: " << cj_answer_ << "'" << endl;
        getchar();
        cout << "CJ 🦦: 'Better luck next time!'" << endl;
        getchar();
        return false;
    }
    npc_completed_++;
    fin1.close();//close the file
}

return false;
}

/*Villager_game()
generate a random number either one or two, if one queue high-card low-card game, if two queue black card red card game
generate a random number between 1-20 to choose a villager from the file
take villager name and emoji and put it into a villager title variable
high card low card- randomly generate an original card- cout to user cin their guess either higher or lower
generate the next card and if they win return 2 and if they lose return -2
black card red card generate random number 1 or 2 if 1 card is red if 2 the card is black
get user guess and if they guess correctly return 2 if incorrectly return -2
Parameters-none
Return- int -2 if they lose the game 2 if they win
*/
int Areas::Villager_game()
{
    srand(time(0));
    int rand=randomNumbers(1,2);
    int villager_rand=randomNumbers(1,20);
    ifstream fin;// like cin for files
    string line;// create a string for the line within the file
    string array[100000];// big array
    fin.open("villager.txt");// open the file
    string villager_title="";

    //getting the villager name and emoji
    while(getline(fin, line))
    {
        if (stoi(line.substr(0,2))==villager_rand)
        {
            split1(line, ',', array, 3);
            
            if (array[1]==villager_array_[villager_rand-1])
            {
                villager_rand=randomNumbers(1,2);
            }
            else
            {            
            villager_array_[villager_rand-1]=array[1];
            villager_name_=array[1];
            villager_emote_=array[2];
            }
        }
    }
    //create villager title variable 
    villager_title= villager_name_ + " " + villager_emote_ + ":"; //FIX
    getchar();
    cout << villager_title <<" 'Hey! Let's play a game!'" << endl; 

    //high card low card game
    if (rand==1)
    {
        char choice;
        getchar();
        cout << villager_title;
        cout << " 'We'll play a game of High-Card Low-Card.'" << endl;
        getchar();
        cout << villager_title;
        cout << " 'I'll pick a card and you have to guess whether the next card drawn will be higher or lower.'" << endl;
        getchar();

        int org_card=randomNumbers(2,8);

        cout << villager_title;
        cout << " 'The card we'll play with is " << org_card;
        cout << "'" << endl;
        getchar();
        
        int first_card=randomNumbers(1,9);

        //make sure cards arent equal
        while(org_card==first_card)
        {
            first_card=randomNumbers(1,9);
        }

        cout << villager_title;
        cout << " 'Will the next card I draw be higher or lower than " << org_card;
        cout << "?' H/L" << endl;
        cin >> choice;

        while(choice!='H'&&choice!='L'&&choice!='h'&&choice!='l')
        {
            cout << "Please enter a valid value." << endl;
            cin >> choice;
        }

        if ((first_card>org_card&&(choice=='H'||choice=='h'))||(first_card<org_card&&(choice=='L'||choice=='l')))
        {
            cout << villager_title;
            cout << " 'The next card was " << first_card << "! You won!'" << endl;
            getchar();
            return 2;
        }
        else
        {
            cout << villager_title;
            cout << " 'The next card was " << first_card << "! You lost.'" << endl;
            getchar();
            return -2;
        }

    }
    //black or red card game
    if (rand==2)
    {
        char choice;
        getchar();
        cout << villager_title;
        cout << " 'We'll play a game of Red-Card Black-Card.'" << endl;
        getchar();

        cout << villager_title;
        cout << " 'You have to guess whether the card I'm going to draw is a black card or a red card.'" << endl;
        getchar();

        cout << villager_title;
        cout << " 'Black or Red?' B/R" << endl;
        cin >> choice;

        while(choice!='R'&&choice!='r'&&choice!='B'&&choice!='b')
        {
            cout << "Please enter a valid value." << endl;
            cin >> choice;
        }

        int rand_card=randomNumbers(1,2);

        if (rand_card==1)//red
        {
            if (choice=='R'||choice=='r')
            {
                cout << villager_title;
                cout << " 'The card is red! You won!'" << endl;
                getchar();
                return 2;
            }
            else
            {
                cout << villager_title;
                cout << " 'The card is red! You lost.'" << endl;
                getchar();
                return -2;
            }
        }

        if (rand_card==2)//black 
        {
            if (choice=='R'||choice=='r')
            {
                cout << villager_title;
                cout << " 'The card is black! You lost.'" << endl;
                getchar();
                return -2;
            }
            else
            {
                cout << villager_title;
                cout << " 'The card is black! You won!'" << endl;
                getchar();
                return 2;
            }
        }
    }
    fin.close();
    return 0; 
}

/*Merchant()
NPC merchant function
check to see which merchant it is
prompt buy or sell options
display buy options check if they have enough money
display sell options check if they have enough items
update the number of bells, if sell get rid of items
Parameters: none
Returns: none
*/
void Areas::Merchant()
{
   
string dude="";
char npc_choice;

//see which npc
if(npc_completed_==0)
{
    dude="Flick 🦎: '";
}

if(npc_completed_==1)
{
    dude="CJ 🦦: '";
}

cout << dude <<"Welcome to my shop! You can either buy or sell items.'" << endl;
getchar();
cout << dude <<"Would you like to see the buy or sell options?' B/S" << endl;
cin >> npc_choice;

//valid value
while (npc_choice!='B' && npc_choice!='S' && npc_choice!='b' && npc_choice!='s')
{
    cout << "Please enter a valid value." << endl;
    cin >> npc_choice;
}

//loop sell menu
do{

if(npc_choice=='S'||npc_choice=='s')
{
    int enter_choice1=0;
    cout << "====SELL MENU====" << endl;
    cout << "1. " << STATS.getFruitNamePluralCapital() << ": 40 bells" << endl;
    cout << "2. Shells: various prices" << endl; 
    cout << "3. Flowers: various prices" << endl;
    cout << "4. Bugs: various prices" << endl;
    cout << "5. Fish: various prices" << endl;
    cout << "6. Switch to Buy Menu" << endl;
    cout << "7. Exit" << endl;
    cin >> enter_choice1;

    while (enter_choice1<1||enter_choice1>7)
    {
        cout << "Please enter a valid value." << endl;
        cin >> enter_choice1;
    }

    switch(enter_choice1)
    {
        case(1)://sell fruit
        {   
            //check if enough items
            if (STATS.getFruitCount()==0)
            {
                cout << "You have 0 " << STATS.getFruitNamePlural() << endl;
            }
            else 
            {
            int number=0;
            cout << "You have " << STATS.getFruitCount() << " " << STATS.getFruitNamePlural() << endl;
            getchar();
            cout << dude << "How many " << STATS.getFruitNamePlural() << " would you like to sell?'" << endl;
            cin >> number;

            //valid value
            while (number>STATS.getFruitCount()||number<0)
            {
                cout << "Please enter a valid value." << endl;
                cin >> number;
            }

            STATS.setFruitCount(-1*number);
            STATS.setNumBells(number*40);
            
            cout << "You now have " << STATS.getNumBells() << " bells." << endl;
            }
            npc_choice='S';
            continue;
        }
        case(2)://sell shells
        {
            if (STATS.getShellCount()==0)
            {
                cout << "You have 0 shells" << endl;
            }
            else
            {
            string name="";
            cout << "====SHELLS====" << endl;
            name=STATS.ITEMS.displaySpecificInventory("shell");
            STATS.setNumBells(STATS.ITEMS.removeItem(name,"shell"));
            cout << "You now have " << STATS.getNumBells() << " bells." << endl;
            }
            npc_choice='S';
            continue;
        }
        case(3)://sell flowers
        {
            if (STATS.getFlowerCount()==0)
            {
                cout << "You have 0 flowers" << endl;
            }
            else
            {
            string name="";
            cout << "====FLOWERS====" << endl;
            name=STATS.ITEMS.displaySpecificInventory("flower");
            STATS.setNumBells(STATS.ITEMS.removeItem(name,"flower"));
            cout << "You now have " << STATS.getNumBells() << " bells." << endl;
            }
            npc_choice='S';
            continue;
        }
        case(4)://sell bugs
        {
            if (STATS.getBugCount()==0)
            {
                cout << "You have 0 bugs" << endl;
            }
            else
            {
            string name="";
            cout << "====BUGS====" << endl;
            name=STATS.ITEMS.displaySpecificInventory("bug");
            STATS.setNumBells(STATS.ITEMS.removeItem(name,"bug"));
            cout << "You now have " << STATS.getNumBells() << " bells." << endl;
            }
            npc_choice='S';
            continue;
        }
        case(5)://sell fish
        {
            if (STATS.getFishCount()==0)
            {
                cout << "You have 0 fish" << endl;
            }
            else
            {
            string name="";
            cout << "====FISH====" << endl;
            name=STATS.ITEMS.displaySpecificInventory("fish");
            STATS.setNumBells(STATS.ITEMS.removeItem(name,"fish"));
            cout << "You now have " << STATS.getNumBells() << " bells." << endl;
            }
            npc_choice='S';
            continue;
        }
        case(6)://switch the buy menu
        {
            npc_choice='B';
            continue;
        }
        case(7)://exit menu
        {
            npc_choice='E';
            continue;
        }
    }
}


if(npc_choice=='B'||npc_choice=='b')//buy menu
{
    int enter_choice=0;
    cout << "====BUY MENU====" << endl;
    cout << "1. Fishing Rod: 250 bells" << endl;
    cout << "2. Bug Net: 225 bells" << endl;
    cout << "3. " << STATS.getFruitNameCapital() << ": 50 bells" << endl;
    cout << "4. Tom Nook Relaxer: 70 bells" << endl; 
    cout << "5. Switch to Sell Menu" << endl;
    cout << "6. Exit" << endl;
    cin >> enter_choice;

    //valid value
    while (enter_choice<1||enter_choice>6)
    {
        cout << "Please enter a valid value." << endl;
        cin >> enter_choice; 
    }

    switch(enter_choice)
    {
        case(1)://buy a fishing rod
        {
            //have enough money
            if(STATS.getNumBells()<250)
            {
                cout << dude << "You do not have enough bells to purchase that.'" << endl;
                getchar();
            }
            if(STATS.ITEMS.TOOLS.rodCondition()==true)
            {
                cout << "You already have this item!" << endl;
                getchar();
            }
            else
            {
                STATS.setNumBells(-250);
                STATS.ITEMS.TOOLS.setTool("rod");
                cout << "You now have " << STATS.getNumBells() << " bells." << endl;
            }
            npc_choice='B';
            continue;
        }
        case(2):// buy a bug net
        {
            if(STATS.getNumBells()<225)
            {
                cout << dude << "You do not have enough bells to purchase that.'" << endl;
                getchar();
            }
            if(STATS.ITEMS.TOOLS.netCondition()==true)
            {
                cout << "You already have this item!" << endl;
                getchar();
            }
            else
            {
                STATS.setNumBells(-225);
                STATS.ITEMS.TOOLS.setTool("net");
                cout << "You now have " << STATS.getNumBells() << " bells." << endl;
            }
            npc_choice='B';
            continue;
        }
        case(3):// buy a fruit
        {
            int number_fr=0;
            cout << dude << "How many would you like to purchase?'" << endl;
            cin >> number_fr;

            while(number_fr<0)
            {
                cout << "Please enter a valid value." << endl;
                cin >> number_fr;
            }

            if(STATS.getNumBells()<(50*number_fr))
            {
                cout << dude << "You do not have enough bells to purchase that.'" << endl;
                getchar();
            }
            else
            {
                STATS.setNumBells(-50*number_fr);
                STATS.setFruitCount(1*number_fr);
                cout << "You now have " << STATS.getNumBells() << " bells." << endl;
            }
            npc_choice='B';
            continue;
        }
        case(4):// buy a tom relaxer
        {
            char tom;
            cout << dude << "The Tom Nook Relaxer is a best seller. Tom's patience level increases by 10%!'" << endl;
            getchar();
            cout << dude << "Would you like to purchase one?' (Y/N)" << endl;
            cin >> tom;

            while(tom!='n'&&tom!='N'&&tom!='Y'&&tom!='y')
            {
                cout << "Please enter a valid value." << endl;
                cin >> tom;
            }

            if (tom=='n'||tom=='N')
            {
                continue;
            }
            else
            {
                if (STATS.getNumBells()<70)
                {
                    cout << "You don't have enough bells to purchase." << endl;
                    getchar();
                }
                else
                {
                    STATS.addTomPatience(10);
                    STATS.setNumBells(-70);
                    cout << "You now have " << STATS.getNumBells() << " bells." << endl;
                    getchar();
                }
            }
            npc_choice='B';
            continue;
        }
        case(5)://switch to sell menu
        {
            npc_choice='S';
            continue;
        }
        case(6)://exit game
        {
            npc_choice='E';
            continue;
        }
    }

}

}while(npc_choice=='B'||npc_choice=='S');// if npc_choice='E' exit the shop
npc_completed_++;
cout << dude << "Thank you for stopping by!'" << endl;
getchar();
}

/*Nooks_Cranny()
prompt at the beginning of the game
let the player buy either a rod a net, or fruit 
check for enough money and correct input
change bell count and fruit and tools
Parameters: none
Returns: none
*/
void Areas::Nooks_Cranny()
{
    if (areas_completed_==0)
    {
        cout << "Welcome to Nook's Cranny!" << endl;
        getchar();
        cout << "Timmy and Tommy 🦝🦝: 'You have 300 bells, how would you like to spend it?'" << endl;
        
        int choicett=0;
        do{
        cout << "====NOOK'S CRANNY====" << endl;
        cout << "1. Fishing Rod: 275 bells" << endl;
        cout << "2. Bug Net: 250 bells" << endl;
        cout << "3. " << STATS.getFruitNameCapital() << ": 50 bells" << endl;
        cout << "4. Exit" << endl;
        cin >> choicett;

        while (choicett>4||choicett<1)
        {
            cout << "Please enter a valid value." << endl;
            cin >> choicett;
        }
        switch(choicett)
        {
            case(1)://buy a fishing rod
            {
                //check valid input
                if(STATS.getNumBells()<275)
                {
                cout << "Timmy and Tommy 🦝🦝: 'We're sorry but you do not have enough bells to purchase that.'" << endl;
                getchar();
                }
                else
                {
                STATS.setNumBells(-275);
                STATS.ITEMS.TOOLS.setTool("rod");
                cout << "You now have " << STATS.getNumBells() << " bells." << endl;
                }
                continue;
            }
            case(2):// buy a bug net
            {
                //check valid input
                if(STATS.getNumBells()<250)
                {
                cout << "Timmy and Tommy 🦝🦝: 'We're sorry but you do not have enough bells to purchase that.'" << endl;
                getchar();
                }
                else
                {
                STATS.setNumBells(-250);
                STATS.ITEMS.TOOLS.setTool("net");
                cout << "You now have " << STATS.getNumBells() << " bells." << endl;
                }
                continue;
            }
            case(3):// buy fruit
            {
                int number=0;
                cout << "Timmy and Tommy 🦝🦝: 'How many " << STATS.getFruitNamePlural() << " would you like to buy?'" << endl;
                cin >> number;
                while(number<0)
                {
                    cout << "Please enter a valid value." << endl;
                    cin >> number;
                }

                //check valid input
                if(STATS.getNumBells()<(50*number))
                {
                    cout << "Timmy and Tommy 🦝🦝: 'We're sorry but you do not have enough bells to purchase that.'" << endl;
                    getchar();
                }
                else
                {
                    STATS.setNumBells(-50*number);
                    STATS.setFruitCount(1*number);
                    cout << "You now have " << STATS.getNumBells() << " bells." << endl;
                }
                
                continue;
            }
        }
        }while(choicett!=4);// exit menu at 4
        cout << "Timmy and Tommy 🦝🦝: 'Thanks for stopping by! See you soon!'" << endl;
        getchar();
    }


}


/*Nook_Crannyend()
Sell everything before tom nook to check pay off debt
display all of the players items and then remove them from the inventory and add to bell count
Parameters: none
Returns: none
*/
void Areas::Nooks_CrannyEnd()
{
        cout << "Welcome back to Nook's Cranny!" << endl;
        getchar();
        cout << "Timmy and Tommy 🦝🦝: 'MAYDAY MAYDAY EVERYTHING MUST GO!!! If you want to pay he who shall not be named back, you need to sell EVERYTHING.'" << endl;
        getchar();
        cout << "Timmy and Tommy 🦝🦝: 'First, all fruit must go. You have " << STATS.getFruitCount() << " " << STATS.getFruitNamePlural() <<".'" << endl;
        getchar();
        cout << "Timmy and Tommy 🦝🦝: 'At 60 bells each, here's " << (60*STATS.getFruitCount()) << " bells.'" << endl;
        getchar();
        STATS.setNumBells(60*STATS.getFruitCount());
        cout << "Timmy and Tommy 🦝🦝: 'You now have " << STATS.getNumBells() << " bells.'" << endl;
        getchar();

        cout << "Timmy and Tommy 🦝🦝: 'On to your shells.'" << endl;
        getchar();
        STATS.setNumBells(STATS.ITEMS.displayEnd("shell"));
        getchar();
        cout << "Timmy and Tommy 🦝🦝: 'You now have " << STATS.getNumBells() << " bells.'" << endl;
        getchar();
       
        cout << "Timmy and Tommy 🦝🦝: 'Next: flowers.'" << endl;
        getchar();
        STATS.setNumBells(STATS.ITEMS.displayEnd("flower"));
        getchar();
        cout << "Timmy and Tommy 🦝🦝: 'You now have " << STATS.getNumBells() << " bells.'" << endl;
        getchar();
        
        cout << "Timmy and Tommy 🦝🦝: 'And then the bugs.'" << endl;
        getchar();
        STATS.setNumBells(STATS.ITEMS.displayEnd("bug"));
        getchar();
        cout << "Timmy and Tommy 🦝🦝: 'You now have " << STATS.getNumBells() << " bells.'" << endl;
        getchar();

        cout << "Timmy and Tommy 🦝🦝: 'And lastly the fish.'" << endl;
        getchar();
        STATS.setNumBells(STATS.ITEMS.displayEnd("fish"));
        getchar();
        cout << "Timmy and Tommy 🦝🦝: 'You have a total of " << STATS.getNumBells() << " bells.'" << endl;
        getchar();
        cout << "Timmy and Tommy 🦝🦝: 'AH! That's him! We're out of here! Good luck!'" << endl;
        getchar();
}

