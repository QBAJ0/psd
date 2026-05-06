#ifndef VERTEBRATECREATURE_H
#define VERTEBRATECREATURE_H

#include "SeaCreature.h"

class VertebrateCreature : public SeaCreature {
public:
    VertebrateCreature(const std::string& species, double size, bool hasEggs);
    std::string getCategory() const override;
};

#endif
