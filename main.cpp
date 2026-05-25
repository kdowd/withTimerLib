#include <iostream>
#include "libs/TermColour.h"
#include "libs/Timercpp.h"

using namespace std;


int getUserChoice()
{
    Timer messageTimer = Timer();
    bool loop = true;
    int userNumber = 0;

    messageTimer.setTimeout([&]() {
        cout << termcolor::bright_magenta << "Please choose from following menu" << endl;
    }, 1000);

    messageTimer.setTimeout([&]() {
        cout << termcolor::italic << termcolor::yellow << R"(
    1. Register
    2. Unregister
    3. Login
    4. Logout
    5. End Programme
)" << endl;
   }, 2000);

    messageTimer.setTimeout([&]() {
        messageTimer.stop();
        cout << "Your choice: ";
        cin >> userNumber;
        loop = false;

      }, 3000);

    // cant leave function until timeouts are done
    while(loop == true);

    return userNumber;
}


int main()
{
    int uc = getUserChoice();
    cout << "user chose " << termcolor::bright_red << uc << endl;

    while(true);
    return 0;
}