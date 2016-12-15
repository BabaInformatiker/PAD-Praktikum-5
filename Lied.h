#pragma once
#include <string>
#include "DynArray.h"

using namespace std;

enum genre { pop, rock, klassik, hard_rock };
        
class Lied {
public:
    //int eintragnr;
    string titel;
    string interpret;
    int erscheinungsjahr;
    int laenge;
    genre g;
};
