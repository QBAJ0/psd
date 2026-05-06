#ifndef APP_H
#define APP_H

#include <string>
#include "SeaPlusPlusEngine.h"
#include "Angler.h"
#include "SeaCreatureFactory.h"

class App {
private:
    SeaPlusPlusEngine engine;
    Angler currentAngler;
    SeaCreatureFactory factory;

public:
    void run();
    SeaCreature* collectCreatureInfo();
    bool validateInput(const std::string& type, double size) const;
    void displayResult(const std::string& result) const;
};

#endif
