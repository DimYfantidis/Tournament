#include <iostream>
#include <cstring>
#include <random>
#include <ctime>
#include <algorithm>

using namespace std;

const char *ORDINAL_SUFFIX[] = {
        "st", "nd", "rd", "th"
};

void printMatchups(const int group_number) {
    std::mt19937_64 generator(time(nullptr) + 2);
    std::uniform_int_distribution<int> distribution(1, group_number);
    int i = 0;
    int k;

    auto *matchups = new int[group_number];
    int group_pairs = group_number / 2;

    while(i < group_number) {
        k = distribution(generator);
        if (find(matchups, matchups + i, k) == matchups + i) {
            matchups[i++] = k;
        }
    }
    int g1, g2;
    cout << "MATCHUPS: " << endl;
    for (i = 0; i < group_pairs; ++i) {
        g1 = matchups[2 * i];
        g2 = matchups[2 * i + 1];
        cout << g1 << (g1 < 5 ? ORDINAL_SUFFIX[g1 - 1] : ORDINAL_SUFFIX[3]) << " VS "
             << g2 << (g2 < 5 ? ORDINAL_SUFFIX[g2 - 1] : ORDINAL_SUFFIX[3]) << endl;
    }
    if (group_number % 2) {
        int left_out = matchups[group_number - 1];
        cout << "(" << left_out << (left_out < 5 ? ORDINAL_SUFFIX[left_out - 1] : ORDINAL_SUFFIX[3])
             << " group qualifies to the next round)" << endl;
    }
    cout << endl;
    delete[] matchups;
}

void printGroups(const int group_number, char **players, const int *pairs) {
    cout << endl;
    for (int i = 0; i < group_number; ++i) {
        cout << i + 1 << (i < 4 ? ORDINAL_SUFFIX[i] : ORDINAL_SUFFIX[3]) << " Group" << endl
             << "- " << players[pairs[2 * i]] << endl
             << "- " << players[pairs[2 * i + 1]] << endl
             << endl;
    }
    cout << endl;
}

int *createGroups(const int num_of_players) {
    auto *pairs = new int[num_of_players];
    std::mt19937_64 generator(time(nullptr) + 5);
    std::uniform_int_distribution<int> distribution(0,num_of_players - 1);
    int i = 0;
    int k;

    while(i < num_of_players) {
        k = distribution(generator);
        if (find(pairs, pairs + i, k) == pairs + i) {
            pairs[i++] = k;
        }
    }
    return pairs;
}

char *readFromKeyboard() {
    auto *read = new char[1000];
    fgets(read, 1000, stdin);
    read[strcspn(read,"\n")] = '\0';

    auto *result = new char[strlen(read) + 1];
    strcpy(result, read);

    delete[] read;
    return result;
}

char **createBoard(int N) {
    auto **board = new char *[N];
    for (int i = 0; i < N; ++i) {
        cout << "[" << i + 1 << "]: ";
        board[i] = readFromKeyboard();
    }
    return board;
}

int main() {
    int num_of_players;

    cout << "Input number of players: ";
    cin >> num_of_players;

    while (getchar() != '\n' && getchar() != EOF);

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

    cout << "Enter player names: " << endl;
    auto **player_board = createBoard(num_of_players);

    cout << endl << "Creating " << num_of_players / 2 << " random teams of two ..." << endl;
    auto *player_pairs  = createGroups(num_of_players);

    cout << "Groups created:" << endl;
    printGroups(num_of_players / 2, player_board, player_pairs);

    cout << "Creating Matchups ...\n" << endl;
    printMatchups(num_of_players / 2);


    cout << "Press Enter to exit ..." << endl;
    while (getchar() != '\n');

    return 0;
}