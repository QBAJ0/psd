#include "SeaCreature.h"

SeaCreature::SeaCreature(const std::string& species, double size, bool hasEggs)
    : species(species), size(size), eggCarrier(hasEggs) {}

SeaCreature::~SeaCreature() {}

std::string SeaCreature::getSpecies() const {
    return species;
}

double SeaCreature::getSize() const {
    return size;
}

bool SeaCreature::hasEggs() const {
    return eggCarrier;
}
