#include <iostream>
#include <string>
#include "CommandParser.h"

using namespace std;

int main(int argc, char* argv[])
{
    CommandParser cp;

    cout << "ShowLab shell" << endl 
     << "--------------------------" << endl;

    while(true) {
    char input[256];
        cout << "> ";
        cin.getline(input, 256);
        cout << cp.parse(input) << std::endl;
    }
}
