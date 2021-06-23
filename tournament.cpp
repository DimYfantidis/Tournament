#include "tournament.h"
#include "auxFunctions.h"

static const char *ORDINAL_SUFFIX[] = {
        "st", "nd", "rd", "th"
};

// --------------------- PRIVATE ---------------------

void tournament::setBoard() {
    if (!filename.empty()) {
        //Reads players from file:
        ifstream inFile;
        inFile.open(filename, ios::in);
        if (inFile.is_open()) {
            for (int i = 0; i < num_of_players; ++i) {
                do {
                    getline(inFile, player_board[i]);
                } while (player_board[i].empty());
            }
            inFile.close();
        } else {
            cerr << "File Error!" << endl;
            cout << "Press Enter to exit ..." << endl;
            while (cin.get() != '\n');
            exit(-1);
        }

    } else {
        //Reads players from keyboard since filename is empty string.
        unsigned int d = digits(num_of_players);
        cout << endl << "Input player names:" << endl;
        for (int i = 0; i < num_of_players; ++i) {
            cout << "[" <<  i + 1 << "]: " << printSpaces(digits(i + 1), d);
            do {
                getline(cin, player_board[i]);
            } while (player_board[i].empty());
        }
    }
}

void tournament::generatePairs() {
    std::mt19937_64 generator(time(nullptr) + 5);
    std::uniform_int_distribution<int> distribution(0,num_of_players - 1);
    int i = 0;
    int k;

    while(i < numOfPlayers()) {
        k = distribution(generator);
        if (find(&player_pairs[0], &player_pairs[i], k) == &player_pairs[i]) {
            player_pairs[i++] = k;
        }
    }
}

void tournament::generateGroups() {
    std::mt19937_64 generator(time(nullptr) + 2);
    std::uniform_int_distribution<int> distribution(1, numOfGroups());
    int i = 0;

    int k;
    while(i < numOfGroups()) {
        k = distribution(generator);
        if (find(&matchups[0], &matchups[i], k) == &matchups[i]) {
            matchups[i++] = k;
        }
    }
}


// --------------------- PUBLIC ---------------------

tournament::tournament(const string &f_name, int N) {
    if (!f_name.empty()) {
        int lines = linesInFile(f_name);
        num_of_players = lines < N ? lines : N;
    } else {
        num_of_players = N;
    }
    player_board = new string[num_of_players];
    player_pairs = new int[num_of_players];
    matchups = new int[num_of_players / 2];
    filename = f_name;
    active = false;
}

tournament::tournament(const char *f_name, int N) {
    if (strcmp(f_name, "") != 0 || f_name != nullptr) {
        int lines = linesInFile(filename);
        num_of_players = lines < N ? lines : N;
    } else {
        num_of_players = N;
    }
    player_board = new string[num_of_players];
    player_pairs = new int[num_of_players];
    matchups = new int[num_of_players / 2];
    filename = f_name;
    active = false;
}

tournament::tournament(const tournament &prototype) {
    num_of_players = prototype.num_of_players;

    player_board = new string[prototype.num_of_players];
    for (int i = 0; i < num_of_players; ++i) {
        player_board[i] = prototype.player_board[i];
    }
    player_pairs = new int[prototype.num_of_players];
    for (int i = 0; i < num_of_players; ++i) {
        player_pairs[i] = player_pairs[i];
    }
    matchups = new int[prototype.numOfGroups()];
    for (int i = 0; i < prototype.numOfGroups(); ++i) {
        matchups[i] = matchups[i];
    }

    filename = prototype.filename;
    active = prototype.active;
}

tournament::~tournament() {
    clear();
}

bool tournament::isEmpty() {
    return player_board == nullptr && player_pairs == nullptr && matchups == nullptr;
}

void tournament::set() {
    if (active) {
        cerr << "Tournament is active!" << endl;
        return;
    }
    setBoard();
    generatePairs();
    generateGroups();

    active = true;
}

void tournament::reset(const string &f_name, int N) {
    if (!isEmpty()) {
        delete[] player_board;
        delete[] player_pairs;
        delete[] matchups;
    }
    num_of_players = N;
    player_board = new string[N];
    player_pairs = new int[N];
    matchups = new int[N / 2];
    filename = f_name;

    active = false;
}

void tournament::reset(const char *f_name, int N) {
    if (!isEmpty()) {
        delete[] player_board;
        delete[] player_pairs;
        delete[] matchups;
    }
    num_of_players = N;
    player_board = new string[N];
    player_pairs = new int[N];
    matchups = new int[N / 2];
    filename = f_name;
    active = false;
}

void tournament::clear() {
    if (!isEmpty()) {
        delete[] player_board;
        delete[] player_pairs;
        delete[] matchups;
    }
    player_board = nullptr;
    player_pairs = nullptr;
    matchups = nullptr;
    active = false;
    num_of_players = 0;
}

string * tournament::getBoard() const {
    return player_board;
}

int tournament::numOfPlayers() const {
    return num_of_players;
}

int tournament::numOfGroups() const {
    return num_of_players / 2;
}

void tournament::shuffle() {
    if (isEmpty()) {
        return;
    }
    delete[] player_pairs;
    delete[] matchups;

    player_pairs = new int[numOfPlayers()];
    matchups = new int[numOfGroups()];

    generatePairs();
    generateGroups();
}

void tournament::printBoard(ostream &output) const {
    unsigned int d = digits(num_of_players);
    cout << endl << "Player Board:" << endl;
    for (int i = 0; i < num_of_players; ++i) {
        output << "[" <<  i + 1 << "]: "
               << printSpaces(digits(i + 1), d)
               << player_board[i] << endl;
    }
}

void tournament::printGroups(ostream &output) const {
    output << endl;
    for (int i = 0; i < numOfGroups(); ++i) {
        output << i + 1 << (i < 4 ? ORDINAL_SUFFIX[i] : ORDINAL_SUFFIX[3]) << " Group" << endl
             << "- " << player_board[player_pairs[2 * i]] << endl
             << "- " << player_board[player_pairs[2 * i + 1]] << endl
             << endl;
    }
    output << endl;
}

void tournament::printMatchups(ostream &output) const {
    int g1, g2;
    int group_pairs = numOfGroups() / 2;

    cout << "MATCHUPS: " << endl;
    for (int i = 0; i < group_pairs; ++i) {
        g1 = matchups[2 * i];
        g2 = matchups[2 * i + 1];
        cout << g1 << (g1 < 5 ? ORDINAL_SUFFIX[g1 - 1] : ORDINAL_SUFFIX[3]) << " VS "
             << g2 << (g2 < 5 ? ORDINAL_SUFFIX[g2 - 1] : ORDINAL_SUFFIX[3]) << endl;
    }
    if (numOfGroups() % 2) {
        int left_out = matchups[numOfGroups() - 1];
        cout << "(" << left_out << (left_out < 5 ? ORDINAL_SUFFIX[left_out - 1] : ORDINAL_SUFFIX[3])
             << " group qualifies to the next round)" << endl;
    }
    cout << endl;
}
