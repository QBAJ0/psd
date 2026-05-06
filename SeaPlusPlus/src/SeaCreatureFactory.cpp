#include "SeaCreatureFactory.h"
#include "VertebrateCreature.h"
#include "InvertebrateCreature.h"

SeaCreature* SeaCreatureFactory::createCreature(const std::string& type, const std::string& species, double size, bool hasEggs) {
    if (type == "vertebrate") {
        return new VertebrateCreature(species, size, hasEggs);
    }

    if (type == "invertebrate") {
        return new InvertebrateCreature(species, size, hasEggs);
    }

    return nullptr;
}
