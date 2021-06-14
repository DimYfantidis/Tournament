#ifndef AUX_FUNCTIONS_H
#define AUX_FUNCTIONS_H
#include <iostream>

void clearScreen() {
#ifdef _WIN32
    system("CLS");
#elif __linux__
    system("clear");
#elif 	macintosh || Macintosh || __APPLE__ && __MACH__
        system("clear");
#endif
}

bool inputFail(std::istream &input) {
    if (input.fail()) {
        input.clear();
        while (input.get() != '\n');
        clearScreen();
        return true;
    }
    return false;
}

unsigned int digits(int N) {
    if (N < 0) {
        N *= (-1);
    }
    unsigned int d;
    for (d = 0; N > 0; ++d) {
        N /= 10;
    }
    return d;
}

#endif //AUX_FUNCTIONS_H
