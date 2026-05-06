#ifndef APP_H
#define APP_H

#include <string>
#include "SeaPlusPlusEngine.h"
#include "Angler.h"
#include "SeaCreatureFactory.h"
#include "Bag.h"

class App {
private:
    SeaPlusPlusEngine engine;
    Angler currentAngler;
    Bag currentBag;
    SeaCreatureFactory factory;

public:
    void run();
    SeaCreature* collectCreatureInfo();
    bool validateInput(double size) const;
    void displayResult(const std::string& result) const;
    void addCatchToBag(SeaCreature* creature);
    void saveSession() const;
    void loadSession(const std::string& anglerName);
};

#endif
