#include "Map.h"
#include <cassert>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    Map map;
    string username="";
    int house_size=0;

    cout <<"💐Welcome to Paradise Island!💐 (click enter to continue)" << endl;
    getchar();
    cout << "Please enter your name! (no spaces)" << endl;
    cin >> username;
    map.AREAS.STATS.setUsername(username);
}