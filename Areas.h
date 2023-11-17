
// CSCI 1300 Fall 2022
// Author: Danielle Swen
// Recitation: 202 – Christopher Ebuka Ojukwu
// Project 3 Areas.h

#ifndef AREAS_H  // match name of class
#define AREAS_H  // internally to access class
#include <iostream> // have after #define
#include "Stats.h"

using namespace std; 

/*Areas class keeps track of all of the different games and menus throughout the game, as well as the NPCs. Every game, buy/sell opportunity lives here
Can access stats, items, tools.
*/

class Areas {

public: 

Areas();//default constructor
Areas(int areas_completed, int npc_completed, string flick_answer, string cj_answer, string flick_riddle, string cj_riddle, string villager_name, string villager_emote);//parameterized constructor

//area functions
bool Beach(int how_many_fruit);

bool Meadow(int how_many_bells);

bool Forest(bool net_condition);

bool River(bool rod_condition);

bool Tom_challenge();

bool area_queue();

void setAreasCompleted(int previous_completed);

int getAreasCompleted();

//npc, villager, nooks cranny functions
void setNPCCompleted(int previous_completed);

int getNPCCompleted();

bool NPC_puzzle();

void Merchant();

int Villager_game();

void Nooks_Cranny();

void Nooks_CrannyEnd();

/*INHERITANCE*/
Stats STATS;

private:
int areas_completed_;
int npc_completed_;
string flick_answer_;
string cj_answer_;
string flick_riddle_;
string cj_riddle_;
string villager_name_;
string villager_emote_;
string villager_array_[20];

};
#endif