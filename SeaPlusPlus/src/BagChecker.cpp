#include "BagChecker.h"
#include <sstream>

BagChecker::BagChecker() {
    regulations.push_back(Regulation("Snapper", 30.0, 10, false));
    regulations.push_back(Regulation("Tuna", 50.0, 5, false));
    regulations.push_back(Regulation("Mud Crab", 8.5, 10, false));
    regulations.push_back(Regulation("Lobster", 10.0, 5, false));
}

bool BagChecker::isBagLimitLegal(const Bag& bag, const Regulation& regulation) const {
    return bag.countSpecies(regulation.getSpecies()) <= regulation.getBagLimit();
}

std::string BagChecker::checkBag(const Bag& bag) const {
    for (std::size_t i = 0; i < regulations.size(); ++i) {
        const Regulation& regulation = regulations[i];
        int speciesCount = bag.countSpecies(regulation.getSpecies());
        if (speciesCount > regulation.getBagLimit()) {
            std::stringstream message;
            message << "Bag limit exceeded: " << regulation.getSpecies()
                    << " has " << speciesCount
                    << ", limit is " << regulation.getBagLimit();
            return message.str();
        }
    }

    return "Bag is legal";
}
