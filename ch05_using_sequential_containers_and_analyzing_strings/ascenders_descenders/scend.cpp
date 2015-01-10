#include "scend.h"

bool isAscendOrDescend(char c) {

    switch (c) {

        case 'b':
        case 'd':
        case 'f':
        case 'h':
        case 'k':
        case 'l':
        case 't':
        case 'g':
        case 'j':
        case 'p':
        case 'q':
        case 'y':
            return true;
            break;
        default:
            return false;
    }

}
