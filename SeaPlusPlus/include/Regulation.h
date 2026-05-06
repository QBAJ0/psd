#ifndef REGULATION_H
#define REGULATION_H

#include <string>

class Regulation {
private:
    std::string species;
    double minimumSize;
    int bagLimit;
    bool eggCarryingAllowed;

public:
    Regulation();
    Regulation(const std::string& species, double minimumSize, int bagLimit, bool eggCarryingAllowed);

    std::string getSpecies() const;
    double getMinimumSize() const;
    int getBagLimit() const;
    bool isEggCarryingAllowed() const;
};

#endif
