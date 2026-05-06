#ifndef BAG_H
#define BAG_H

#include <string>
#include <vector>
#include "SeaCreature.h"

class Bag {
private:
    std::vector<SeaCreature*> creatures;

public:
    ~Bag();

    void addCreature(SeaCreature* creature);
    void removeCreature(int index);
    const std::vector<SeaCreature*>& getCreatures() const;
    int countSpecies(const std::string& species) const;
    void clear();
    void saveToFile(const std::string& filename) const;
    void loadFromFile(const std::string& filename);
};

#endif
