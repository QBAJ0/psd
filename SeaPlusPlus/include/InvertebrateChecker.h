#ifndef INVERTEBRATECHECKER_H
#define INVERTEBRATECHECKER_H

#include "SeaChecker.h"

class InvertebrateChecker : public SeaChecker {
public:
    InvertebrateChecker();
    std::string check(const SeaCreature& creature) override;
};

#endif
