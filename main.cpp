#include <iostream>
#include "libs/TermColour.h"
#include "libs/Timercpp.h"

using namespace std;
Timer messageTimer = Timer();

void stuff()
{
    messageTimer.setInterval([&]() {
        cout << termcolor::bright_magenta << "Message, one per 1s..." << endl;
    }, 1000);

    messageTimer.setTimeout([&]() {
        cout << termcolor::bright_red  <<"Kill this timer after 6.4s!" << endl;
        messageTimer.stop();
    }, 6400);
}


int main()
{
    std::cout << termcolor::bright_cyan << "Hello, World!" << std::endl;
    stuff();
    while(true);
    return 0;
}