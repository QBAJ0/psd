#ifndef BAGCHECKER_H
#define BAGCHECKER_H

#include <string>
#include <vector>
#include "Bag.h"
#include "Regulation.h"

class BagChecker {
private:
    std::vector<Regulation> regulations;

public:
    BagChecker();
    std::string checkBag(const Bag& bag) const;
    bool isBagLimitLegal(const Bag& bag, const Regulation& regulation) const;
};

#endif
