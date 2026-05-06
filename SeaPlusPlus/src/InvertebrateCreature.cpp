#include "InvertebrateCreature.h"

InvertebrateCreature::InvertebrateCreature(const std::string& species, double size, bool hasEggs)
    : SeaCreature(species, size, hasEggs) {}

std::string InvertebrateCreature::getCategory() const {
    return "invertebrate";
}
