#include "VertebrateCreature.h"

VertebrateCreature::VertebrateCreature(const std::string& species, double size, bool hasEggs)
    : SeaCreature(species, size, hasEggs) {}

std::string VertebrateCreature::getCategory() const {
    return "vertebrate";
}
