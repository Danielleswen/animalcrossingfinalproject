#include <iostream>
#include "Menu.h"

using namespace std;

int randomNumbers(int min, int max);

int main()
{
  string username="";
  int house_size=0;
   Menu men;
   cout <<"💐Welcome to Paradise Island!💐 (click enter to continue)" << endl;
    getchar();
    cout << "Please enter your name! (no spaces)" << endl;
    cin >> username;
    men.MAP.AREAS.STATS.setUsername(username);
   

    getchar();
    cout << "Tom Nook 🦝: 'Alright " << men.MAP.AREAS.STATS.getUsername() << ", welcome to your potential new home.'" << endl;
    getchar();
    cout << "Tom Nook 🦝: 'What size house were you thinking?'" << endl;
    getchar();
    cout << "Tom Nook 🦝: 'We have Small, Medium, or Large.' (1,2,3)" << endl;
    cin >> house_size;
    while (house_size>3||house_size<0)
    {
        cout << "Please enter a valid value." << endl;
        cin >> house_size;
    }
    men.MAP.AREAS.STATS.setDebt(house_size);
    getchar();
    cout << "Tom Nook 🦝: 'Okay then... your total comes out to be " << men.MAP.AREAS.STATS.getDebt() << " bells.'" << endl;
    getchar();
    cout << "Tom Nook 🦝: 'Oh? You didn't come with any money? How convenient.'" << endl;
    getchar();
    cout << "Tom Nook 🦝: 'Well unfortunately you don't succeed in business by handing things out for free.'" << endl;
    getchar();
    cout << "Tom Nook 🦝: '...What?'" << endl;
    getchar();
    cout << "Tom Nook 🦝: 'WHAT?!'" << endl;
    getchar();
    cout << "Tom Nook 🦝: 'Isabelle, I can't hear you. PLEASE speak up.'" << endl;
    getchar();
    cout << "Isabelle 🐶: 'Well I just had an idea Tom...'" << endl;
    getchar();
    cout << "Tom Nook 🦝: ' '" << endl;
    getchar();
    cout << "Isabelle 🐶: ' '" << endl;
    getchar();
    cout << "Tom Nook 🦝: 'Well are you going to tell us?!'" << endl;
    getchar();
    cout << "Isabelle 🐶: 'I- yes. Well, I was thinking " << men.MAP.AREAS.STATS.getUsername() << " could spend a day on the island and collect resources to pay you back.'" << endl;
    getchar();
    cout << "Tom Nook 🦝: 'Oh... well that's not a half bad idea. But I don't care. Just get me the money, " << men.MAP.AREAS.STATS.getUsername() << ". Figure it out.'" << endl;
    getchar();
    cout << "..." << endl;
    getchar();
    cout << "Isabelle 🐶: 'Ha, well that's Tom for you! Anywho.'" << endl;
    getchar();
    cout << "Isabelle 🐶: 'On Paradise Island, you'll find plenty to do. We have a Beach, Meadow, Forest, and River!' (🌸)" << endl;
    getchar();
    cout << "Isabelle 🐶: 'To get into the Beach, you need to have at least 3 " << men.MAP.AREAS.STATS.getFruitNamePlural() << ", just so you don't get hungry on your adventure.'" << endl;
    getchar();
    cout << "Isabelle 🐶: 'Once you reach the Meadow, you'll need proof of having 100 bells to enter, no charge though!'" << endl;
    getchar();
    cout << "Isabelle 🐶: 'In our Forest, there's bugs everywhere, so it's highly recommended that you have a bug net.'" << endl;
    getchar();
    cout << "Isabelle 🐶: 'I also heard we had a special event going on at the River today! So make sure to grab a fishing rod and check that out!'" << endl;
    getchar();
    cout << "Isabelle 🐶: 'In case you want to try to get into an area without what you need, I heard that our groundskeeper Leif will let you play him to get in!'" << endl;
    getchar();
    cout << "Isabelle 🐶: 'But be careful! Tom's patience is constantly running out! If you don't finish in time you'll have to leave!'" << endl;
    getchar();
    cout << "Isabelle 🐶: 'Here, take 300 bells to get yourself some items from Nook's Cranny.'" << endl;
    getchar();
    cout << "Isabelle 🐶: 'You might also run into Flick or CJ out there, and they'll sell you items or buy yours!' (🛒)" << endl;
    getchar();

    men.MAP.AREAS.Nooks_Cranny();//merchant

    getchar();
    cout << "Isabelle 🐶: 'I think you're all ready to go! Stay safe and make sure to eat every once and a while! You can find " << men.MAP.AREAS.STATS.getFruitNamePlural() << " on the trees!" << endl;
    getchar();
    cout << "💐Off to Paradise Island!💐" << endl;
    getchar();
   

    //START PHASE 2// display stats, map, and menu after every turn, loop until patience runs out, they reach the exit, they quit, or they run out of fullness

    do{
        men.MAP.AREAS.STATS.DisplayStats();
        men.MAP.displayMap();
        men.checkMenuType();
    }
    while(men.MAP.AREAS.STATS.getTomPatience()>0 && men.MAP.isDungeonExit(men.MAP.getPlayerRow(),men.MAP.getPlayerCol())==false && men.getEndValue()==false && men.MAP.AREAS.STATS.getFullness()>0); 
   
   //START PHASE 3// save the stats for the scoreboard before they get sold. Different endings for patience run out, fullness run out, they quit, or they reach the exit. Display scoreboard

   men.MAP.AREAS.STATS.SaveStats();//save number of items before they all get sold

    if (men.MAP.AREAS.STATS.getFullness()<=0)// run out of fullness
    {
        cout << "Leif : '...hello?'" << endl;
        getchar();
        cout << "Leif : 'Wake up! Are you okay?'" << endl;
        getchar();
        cout << "Leif : 'Isabelle, Tom! Come here!'" << endl;
        getchar();

        cout << "You passed out from hunger!" << endl;
        getchar();
        cout << "They had to fly you to the mainland to get you to a hospital." << endl;
        cout << "" << endl;
        men.MAP.AREAS.STATS.displayScoreboard();
    }

    else if (men.MAP.AREAS.STATS.getTomPatience()==0)// tom patience runs out
    {
        cout << "Tom's Patience has reached 0." << endl;
        getchar();
        cout << "Tom Nook 🦝: '" << men.MAP.AREAS.STATS.getUsername() << "!!! I have HAD it. Your house is sold to someone else. Anyone else. You don't get the house.'" << endl;
        getchar();
        cout << "Tom Nook 🦝: 'Good luck finding a new house.'" << endl;
        getchar();
        cout << "Isabelle 🐶: 'So close! We'll miss you!'" << endl;
        cout << "" << endl;
        men.MAP.AREAS.STATS.displayScoreboard();
    }

    else if(men.MAP.isDungeonExit(men.MAP.getPlayerRow(),men.MAP.getPlayerCol())==true)// they reach the end
    {
        men.MAP.AREAS.Nooks_CrannyEnd();// go and sell all their stuff

        cout << "Tom Nook 🦝: 'Well well well.'" << endl;
        getchar();
        cout << "Tom Nook 🦝: 'Your debt is " << men.MAP.AREAS.STATS.getDebt() << " bells and you made " << men.MAP.AREAS.STATS.getNumBells() << " bells.'" << endl;
        getchar();

        if(men.MAP.AREAS.STATS.getNumBells() >=men.MAP.AREAS.STATS.getDebt())// if the total money is greater or equal to the debt (they win!)
        {
            cout << "Tom Nook 🦝: 'Congratulations. You get to stay.'" << endl;
            getchar();
            cout << "Isabelle 🐶: 'YAY!!! You did it! Good job! Welcome to your new home!'" << endl;
            getchar();

            cout << "💐Thanks for joining! See you next time!💐" << endl;
            getchar();
            cout << "" << endl;
            men.MAP.AREAS.STATS.displayScoreboard();
        }

        else// they don't have enough money
        {
            cout << "Tom Nook 🦝: 'Well that's too bad. Have a safe trip back.'" << endl;
            getchar();
            cout << "Isabelle 🐶: 'So close! We'll miss you!'" << endl;
            getchar();
            cout << "" << endl;
            men.MAP.AREAS.STATS.displayScoreboard();
        }

    }

    else if(men.getEndValue()==true)//the player quits
    {
        cout << "💐Thanks for joining! See you next time!💐" << endl;
        cout << "" << endl;
        men.MAP.AREAS.STATS.displayScoreboard();
    }


}