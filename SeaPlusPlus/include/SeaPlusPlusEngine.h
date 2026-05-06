#ifndef SEAPLUSPLUSENGINE_H
#define SEAPLUSPLUSENGINE_H

#include <string>
#include "SeaCreature.h"
#include "VertebrateChecker.h"
#include "InvertebrateChecker.h"
#include "BagChecker.h"

class SeaPlusPlusEngine {
private:
    VertebrateChecker vertebrateChecker;
    InvertebrateChecker invertebrateChecker;
    BagChecker bagChecker;

public:
    std::string processCreature(const SeaCreature& creature);
    std::string processBag(const Bag& bag);
};

#endif
