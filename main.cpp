#include <iostream>
#include <string>
#include "tournament.h"
#include "auxFunctions.h"

using namespace std;

int main() {
    int num_of_players;
    int source;
    string file;

    do {
        cout << endl << "Input player names:\nFrom keyboard: 0\nFrom file: 1\n\nSELECT: ";
        cin >> source;
    } while (inputFail(cin));

    while (cin.get() != '\n');

    clearScreen();

    if (source) {
        cout << "Input file name and directory: ";
        getline(cin, file);
        clearScreen();
    } else {
        file = "";
    }

    do {
        cout << "Input number of players: ";
        cin >> num_of_players;
    } while (inputFail(cin));

    while (cin.get() != '\n');

    if (num_of_players <= 0 || num_of_players % 2) {
        int code;
        cerr << "Wrong Input!" << endl;
        if (num_of_players <= 0) {
            cerr << "Number of players cannot be negative or zero. ";
            code = 1;
        } else {
            cerr << "Cannot create teams of two with odd number of players. ";
            code = 2;
        }
        cerr <<  "Press any key to exit ... ";
        getchar();
        exit (code);
    }

    tournament ngv_event(file, num_of_players);

    ngv_event.set();
    if (!file.empty()) {
        ngv_event.printBoard(cout);
    }
    ngv_event.printGroups(cout);
    ngv_event.printMatchups(cout);


    cout << "Press Enter to exit ..." << endl;
    while (cin.get() != '\n');

    return 0;
}