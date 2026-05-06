#include "App.h"
#include <cctype>
#include <fstream>
#include <iostream>
#include <limits>
#include <sstream>
#include <string>

namespace {
std::string toLower(const std::string& value) {
    std::string result = value;
    for (std::size_t i = 0; i < result.size(); ++i) {
        result[i] = static_cast<char>(std::tolower(static_cast<unsigned char>(result[i])));
    }
    return result;
}

std::string normalizeSpeciesForType(const std::string& type, const std::string& speciesInput) {
    std::string species = toLower(speciesInput);

    if (type == "vertebrate") {
        if (species == "snapper") {
            return "Snapper";
        }
        if (species == "tuna") {
            return "Tuna";
        }
    }

    if (type == "invertebrate") {
        if (species == "mud crab" || species == "mudcrab") {
            return "Mud Crab";
        }
        if (species == "lobster") {
            return "Lobster";
        }
    }

    return "";
}

std::string makeSessionFilename(const std::string& anglerName) {
    if (anglerName.empty()) {
        return "unknown_session.txt";
    }

    std::string filePart = anglerName;
    for (std::size_t i = 0; i < filePart.size(); ++i) {
        if (filePart[i] == ' ') {
            filePart[i] = '_';
        }
    }

    return filePart + "_session.txt";
}
}  // namespace

void App::run() {
    std::string choice;
    std::string name = "";
    std::string license = "";

    bool running = true;
    while (running) {
        std::cout << "\n1. Add catch\n";
        std::cout << "2. Check bag\n";
        std::cout << "3. Save session\n";
        std::cout << "4. Load session\n";
        std::cout << "5. Exit\n";
        std::cout << "Choose option: ";
        std::getline(std::cin, choice);

        if (choice == "1") {
            if (currentAngler.getName().empty()) {
                std::cout << "Enter angler name: ";
                std::getline(std::cin, name);

                std::cout << "Enter license number: ";
                std::getline(std::cin, license);

                currentAngler = Angler(name, license);
            }

            SeaCreature* creature = collectCreatureInfo();
            if (creature == nullptr) {
                std::cout << "Invalid input." << std::endl;
                continue;
            }

            std::string result = engine.processCreature(*creature);
            displayResult(result);

            if (result == "Legal to keep") {
                addCatchToBag(creature);
            } else {
                delete creature;
            }
        } else if (choice == "2") {
            displayResult(engine.processBag(currentBag));
        } else if (choice == "3") {
            if (currentAngler.getName().empty()) {
                std::cout << "No active angler session to save." << std::endl;
                continue;
            }

            saveSession();
            std::cout << "Session saved for " << currentAngler.getName() << "." << std::endl;

            currentAngler.setName("");
            currentAngler.setLicenseNumber("");
            currentBag.clear();
            std::cout << "Start a new session with option 1." << std::endl;
        } else if (choice == "4") {
            std::cout << "Enter angler name to load: ";
            std::getline(std::cin, name);
            if (name.empty()) {
                std::cout << "Invalid angler name." << std::endl;
                continue;
            }

            loadSession(name);
            std::cout << "Session loaded." << std::endl;
        } else if (choice == "5") {
            running = false;
        } else {
            std::cout << "Invalid option." << std::endl;
        }
    }
}

void App::addCatchToBag(SeaCreature* creature) {
    currentBag.addCreature(creature);
}

void App::saveSession() const {
    std::string filename = makeSessionFilename(currentAngler.getName());
    std::ofstream output(filename.c_str());
    if (!output) {
        return;
    }

    output << currentAngler.getName() << "\n";
    output << currentAngler.getLicenseNumber() << "\n";
    output << "Bag includes:\n";
    output << "Snapper: " << currentBag.countSpecies("Snapper") << "\n";
    output << "Tuna: " << currentBag.countSpecies("Tuna") << "\n";
    output << "Mud Crab: " << currentBag.countSpecies("Mud Crab") << "\n";
    output << "Lobster: " << currentBag.countSpecies("Lobster") << "\n";
    output << "Creatures:\n";

    const std::vector<SeaCreature*>& creatures = currentBag.getCreatures();
    for (std::size_t i = 0; i < creatures.size(); ++i) {
        output << creatures[i]->getCategory() << ",";
        output << creatures[i]->getSpecies() << ",";
        output << creatures[i]->getSize() << ",";
        output << (creatures[i]->hasEggs() ? 1 : 0) << "\n";
    }
}

void App::loadSession(const std::string& anglerName) {
    std::string filename = makeSessionFilename(anglerName);
    std::ifstream input(filename.c_str());
    if (!input) {
        std::cout << "Session file not found." << std::endl;
        return;
    }

    currentBag.clear();

    std::string loadedName;
    std::string loadedLicense;
    std::getline(input, loadedName);
    std::getline(input, loadedLicense);
    currentAngler = Angler(loadedName, loadedLicense);

    std::string line;
    while (std::getline(input, line)) {
        if (line.empty() || line.find(',') == std::string::npos) {
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
            currentBag.addCreature(creature);
        }
    }
}

SeaCreature* App::collectCreatureInfo() {
    std::string type;
    std::string speciesInput;
    double size = 0.0;
    std::string eggsInput;
    bool hasEggs = false;

    std::cout << "Enter creature type (vertebrate/invertebrate): ";
    std::getline(std::cin, type);
    type = toLower(type);

    if (type != "vertebrate" && type != "invertebrate") {
        std::cout << "Warning: invalid creature type. Please choose vertebrate or invertebrate." << std::endl;
        return nullptr;
    }

    if (type == "vertebrate") {
        std::cout << "Enter species (Snapper, Tuna): ";
    } else {
        std::cout << "Enter species (Mud Crab, Lobster): ";
    }
    std::getline(std::cin, speciesInput);

    std::string species = normalizeSpeciesForType(type, speciesInput);
    if (species.empty()) {
        std::cout << "Warning: that species is not in the database. You need to have it checked." << std::endl;
        return nullptr;
    }

    std::cout << "Enter size in cm: ";
    std::cin >> size;
    if (std::cin.fail()) {
        std::cout << "Warning: invalid size. Please enter a number." << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return nullptr;
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "Is the creature carrying eggs? (Yes/No): ";
    std::getline(std::cin, eggsInput);

    if (eggsInput == "yes" || eggsInput == "Yes" || eggsInput == "y" || eggsInput == "Y") {
        hasEggs = true;
    }

    if (!validateInput(size)) {
        return nullptr;
    }

    return factory.createCreature(type, species, size, hasEggs);
}

bool App::validateInput(double size) const {
    if (size <= 0.0) {
        return false;
    }
    return true;
}

void App::displayResult(const std::string& result) const {
    std::cout << result << std::endl;
}
