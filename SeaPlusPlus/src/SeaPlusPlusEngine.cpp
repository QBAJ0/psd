#include "SeaPlusPlusEngine.h"

std::string SeaPlusPlusEngine::processCreature(const SeaCreature& creature) {
    if (creature.getCategory() == "vertebrate") {
        return vertebrateChecker.check(creature);
    }

    if (creature.getCategory() == "invertebrate") {
        return invertebrateChecker.check(creature);
    }

    return "Must be released";
}
