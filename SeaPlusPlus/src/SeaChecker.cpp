#include "SeaChecker.h"

SeaChecker::~SeaChecker() {}

const Regulation* SeaChecker::findRegulation(const std::string& species) const {
    for (std::size_t i = 0; i < regulations.size(); ++i) {
        if (regulations[i].getSpecies() == species) {
            return &regulations[i];
        }
    }
    return nullptr;
}

bool SeaChecker::isSizeLegal(const SeaCreature& creature) const {
    const Regulation* regulation = findRegulation(creature.getSpecies());
    if (regulation == nullptr) {
        return false;
    }
    return creature.getSize() >= regulation->getMinimumSize();
}

bool SeaChecker::isEggLegal(const SeaCreature& creature) const {
    const Regulation* regulation = findRegulation(creature.getSpecies());
    if (regulation == nullptr) {
        return false;
    }
    if (creature.hasEggs() && !regulation->isEggCarryingAllowed()) {
        return false;
    }
    return true;
}
