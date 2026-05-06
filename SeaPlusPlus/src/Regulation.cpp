#include "Regulation.h"

Regulation::Regulation() : species(""), minimumSize(0.0), eggCarryingAllowed(false) {}

Regulation::Regulation(const std::string& species, double minimumSize, bool eggCarryingAllowed)
    : species(species), minimumSize(minimumSize), eggCarryingAllowed(eggCarryingAllowed) {}

std::string Regulation::getSpecies() const {
    return species;
}

double Regulation::getMinimumSize() const {
    return minimumSize;
}

bool Regulation::isEggCarryingAllowed() const {
    return eggCarryingAllowed;
}
