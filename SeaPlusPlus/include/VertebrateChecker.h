#ifndef VERTEBRATECHECKER_H
#define VERTEBRATECHECKER_H

#include "SeaChecker.h"

class VertebrateChecker : public SeaChecker {
public:
    VertebrateChecker();
    std::string check(const SeaCreature& creature) override;
};

#endif
