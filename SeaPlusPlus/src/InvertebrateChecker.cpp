#include "InvertebrateChecker.h"

InvertebrateChecker::InvertebrateChecker() {
    regulations.push_back(Regulation("Mud Crab", 8.5, 10, false));
    regulations.push_back(Regulation("Lobster", 10.0, 5, false));
}

std::string InvertebrateChecker::check(const SeaCreature& creature) {
    if (!isSizeLegal(creature)) {
        return "Must be released";
    }

    if (!isEggLegal(creature)) {
        return "Must be released";
    }

    return "Legal to keep";
}
