#ifndef SEAPLUSPLUSENGINE_H
#define SEAPLUSPLUSENGINE_H

#include <string>
#include "SeaCreature.h"
#include "VertebrateChecker.h"
#include "InvertebrateChecker.h"

class SeaPlusPlusEngine {
private:
    VertebrateChecker vertebrateChecker;
    InvertebrateChecker invertebrateChecker;

public:
    std::string processCreature(const SeaCreature& creature);
};

#endif
