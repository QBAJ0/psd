#include "Regulation.h"

Regulation::Regulation() : species(""), minimumSize(0.0), bagLimit(0), eggCarryingAllowed(false) {}

Regulation::Regulation(const std::string& species, double minimumSize, int bagLimit, bool eggCarryingAllowed)
    : species(species), minimumSize(minimumSize), bagLimit(bagLimit), eggCarryingAllowed(eggCarryingAllowed) {}

std::string Regulation::getSpecies() const {
    return species;
}

double Regulation::getMinimumSize() const {
    return minimumSize;
}

int Regulation::getBagLimit() const {
    return bagLimit;
}

bool Regulation::isEggCarryingAllowed() const {
    return eggCarryingAllowed;
}
