#ifndef SEACREATUREFACTORY_H
#define SEACREATUREFACTORY_H

#include <string>
#include "SeaCreature.h"

class SeaCreatureFactory {
public:
    SeaCreature* createCreature(const std::string& type, const std::string& species, double size, bool hasEggs);
};

#endif
