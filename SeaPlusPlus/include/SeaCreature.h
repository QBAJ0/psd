#ifndef SEACREATURE_H
#define SEACREATURE_H

#include <string>

class SeaCreature {
protected:
    std::string species;
    double size;
    bool eggCarrier;

public:
    SeaCreature(const std::string& species, double size, bool hasEggs);
    virtual ~SeaCreature();

    std::string getSpecies() const;
    double getSize() const;
    bool hasEggs() const;
    virtual std::string getCategory() const = 0;
};

#endif
