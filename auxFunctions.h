#ifndef AUX_FUNCTIONS_H
#define AUX_FUNCTIONS_H

#include <iostream>
#include <fstream>
#include <cstring>

inline static void clearScreen() {
#ifdef _WIN32
    system("CLS");
#elif __linux__ || macintosh || Macintosh || __APPLE__ && __MACH__
    system("clear");
#endif
}

static bool inputFail(std::istream &input) {
    if (input.fail()) {
        input.clear();
        while (input.get() != '\n');
        clearScreen();
        return true;
    }
    return false;
}

inline static void fileError() {
    cerr << "File Error!" << endl;
    cout << "Press Enter to exit ..." << endl;
    while (cin.get() != '\n');
    exit(-1);
}

inline static unsigned int digits(int N) {
    if (N < 0) {
        N *= (-1);
    }
    unsigned int d;
    for (d = 0; N > 0; ++d) {
        N /= 10;
    }
    return d;
}

inline static char *printSpaces(unsigned int d_current, unsigned int d_max) {
    auto *spaces = new char[25];
    unsigned int i;
    for (i = 0; i < d_max - d_current; ++i) {
        spaces[i] = ' ';
    }
    spaces[i] = '\0';
    auto *result = new char[strlen(spaces) + 1];
    strcpy(result, spaces);

    delete[] spaces;
    return result;
}

inline static int linesInFile(const string &f_name) {
    int lines = 0;
    string temp;

    ifstream inFile;
    inFile.open(f_name, ios::in);
    if (inFile.is_open()) {
        while (!inFile.eof()) {
            getline(inFile, temp);
            if (!temp.empty()) {
                ++lines;
            }
        }
        inFile.close();
    } else {
        fileError();
    }
    return lines;
}

#endif //AUX_FUNCTIONS_H