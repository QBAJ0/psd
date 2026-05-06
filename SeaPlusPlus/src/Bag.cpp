#include "Bag.h"
#include "SeaCreatureFactory.h"
#include <fstream>
#include <sstream>

Bag::~Bag() {
    clear();
}

void Bag::addCreature(SeaCreature* creature) {
    if (creature != nullptr) {
        creatures.push_back(creature);
    }
}

void Bag::removeCreature(int index) {
    if (index < 0 || index >= static_cast<int>(creatures.size())) {
        return;
    }

    delete creatures[static_cast<std::size_t>(index)];
    creatures.erase(creatures.begin() + index);
}

const std::vector<SeaCreature*>& Bag::getCreatures() const {
    return creatures;
}

int Bag::countSpecies(const std::string& species) const {
    int count = 0;
    for (std::size_t i = 0; i < creatures.size(); ++i) {
        if (creatures[i]->getSpecies() == species) {
            ++count;
        }
    }
    return count;
}

void Bag::clear() {
    for (std::size_t i = 0; i < creatures.size(); ++i) {
        delete creatures[i];
    }
    creatures.clear();
}

void Bag::saveToFile(const std::string& filename) const {
    std::ofstream output(filename.c_str());
    if (!output) {
        return;
    }

    output << "Bag includes:\n";
    output << "Snapper: " << countSpecies("Snapper") << "\n";
    output << "Tuna: " << countSpecies("Tuna") << "\n";
    output << "Mud Crab: " << countSpecies("Mud Crab") << "\n";
    output << "Lobster: " << countSpecies("Lobster") << "\n";
    output << "\n";
    output << "Creatures:\n";

    for (std::size_t i = 0; i < creatures.size(); ++i) {
        output << creatures[i]->getCategory() << ",";
        output << creatures[i]->getSpecies() << ",";
        output << creatures[i]->getSize() << ",";
        output << (creatures[i]->hasEggs() ? 1 : 0) << "\n";
    }
}

void Bag::loadFromFile(const std::string& filename) {
    std::ifstream input(filename.c_str());
    if (!input) {
        return;
    }

    clear();

    SeaCreatureFactory factory;
    std::string line;
    while (std::getline(input, line)) {
        if (line.empty()) {
            continue;
        }
        if (line.find(',') == std::string::npos) {
            continue;
        }

        std::stringstream lineStream(line);
        std::string type;
        std::string species;
        std::string sizeText;
        std::string eggsText;

        std::getline(lineStream, type, ',');
        std::getline(lineStream, species, ',');
        std::getline(lineStream, sizeText, ',');
        std::getline(lineStream, eggsText, ',');

        if (type.empty() || species.empty() || sizeText.empty() || eggsText.empty()) {
            continue;
        }

        double size = 0.0;
        std::stringstream sizeStream(sizeText);
        sizeStream >> size;
        if (sizeStream.fail()) {
            continue;
        }

        bool hasEggs = (eggsText == "1");
        SeaCreature* creature = factory.createCreature(type, species, size, hasEggs);
        if (creature != nullptr) {
            creatures.push_back(creature);
        }
    }
}
