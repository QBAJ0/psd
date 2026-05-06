#include "VertebrateChecker.h"

VertebrateChecker::VertebrateChecker() {
    regulations.push_back(Regulation("Snapper", 30.0, false));
    regulations.push_back(Regulation("Tuna", 50.0, false));
}

std::string VertebrateChecker::check(const SeaCreature& creature) {
    if (!isSizeLegal(creature)) {
        return "Must be released";
    }

    if (!isEggLegal(creature)) {
        return "Must be released";
    }

    return "Legal to keep";
}
