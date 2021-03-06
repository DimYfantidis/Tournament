#ifndef TOURNAMENT_H
#define TOURNAMENT_H

#include <iostream>
#include <fstream>
#include <string>
#include <random>
#include <ctime>
#include <algorithm>

using namespace std;

class tournament {
private:
    int num_of_players;
    bool active;
    string filename;
    string * player_board;
    int * player_pairs;
    int * matchups;

    void setBoard();
    void generateGroups();
    void generatePairs();
public:
    tournament(const string &, int);
    tournament(const char *, int);
    tournament(const tournament &);
    ~tournament();

    void set();
    void reset(const string &, int);
    void reset(const char *, int);
    void clear();


    string * getBoard() const;
    int numOfPlayers() const;
    int numOfGroups() const;

    void shuffle();
    bool isEmpty();

    void printBoard(ostream &) const;
    void printGroups(ostream &) const;
    void printMatchups(ostream &) const;
};


#endif //TOURNAMENT_H
