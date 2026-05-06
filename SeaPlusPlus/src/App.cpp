#include "App.h"
#include <cctype>
#include <iostream>
#include <limits>
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
}  // namespace

void App::run() {
    std::string name;
    std::string license;

    std::cout << "Enter angler name: ";
    std::getline(std::cin, name);

    std::cout << "Enter license number: ";
    std::getline(std::cin, license);

    currentAngler = Angler(name, license);

    SeaCreature* creature = collectCreatureInfo();
    if (creature == nullptr) {
        std::cout << "Invalid input." << std::endl;
        return;
    }

    std::string result = engine.processCreature(*creature);
    displayResult(result);

    delete creature;
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
        return 0;
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
        return 0;
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

    if (!validateInput(type, size)) {
        return 0;
    }

    return factory.createCreature(type, species, size, hasEggs);
}

bool App::validateInput(const std::string& type, double size) const {
    (void)type;
    if (size <= 0.0) {
        return false;
    }
    return true;
}

void App::displayResult(const std::string& result) const {
    std::cout << result << std::endl;
}
