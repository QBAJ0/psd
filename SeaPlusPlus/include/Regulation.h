#ifndef REGULATION_H
#define REGULATION_H

#include <string>

class Regulation {
private:
    std::string species;
    double minimumSize;
    bool eggCarryingAllowed;

public:
    Regulation();
    Regulation(const std::string& species, double minimumSize, bool eggCarryingAllowed);

    std::string getSpecies() const;
    double getMinimumSize() const;
    bool isEggCarryingAllowed() const;
};

#endif
