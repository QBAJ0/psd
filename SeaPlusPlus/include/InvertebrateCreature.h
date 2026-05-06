#ifndef INVERTEBRATECREATURE_H
#define INVERTEBRATECREATURE_H

#include "SeaCreature.h"

class InvertebrateCreature : public SeaCreature {
public:
    InvertebrateCreature(const std::string& species, double size, bool hasEggs);
    std::string getCategory() const override;
};

#endif
