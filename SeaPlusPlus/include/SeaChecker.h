#ifndef SEACHECKER_H
#define SEACHECKER_H

#include <string>
#include <vector>
#include "SeaCreature.h"
#include "Regulation.h"

class SeaChecker {
protected:
    std::vector<Regulation> regulations;
    const Regulation* findRegulation(const std::string& species) const;

public:
    virtual ~SeaChecker();
    virtual std::string check(const SeaCreature& creature) = 0;
    bool isSizeLegal(const SeaCreature& creature) const;
    bool isEggLegal(const SeaCreature& creature) const;
};

#endif
