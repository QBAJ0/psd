#include "Angler.h"
#include <fstream>

Angler::Angler() : name(""), licenseNumber("") {}

Angler::Angler(const std::string& name, const std::string& licenseNumber)
    : name(name), licenseNumber(licenseNumber) {}

std::string Angler::getName() const {
    return name;
}

std::string Angler::getLicenseNumber() const {
    return licenseNumber;
}

void Angler::setName(const std::string& newName) {
    name = newName;
}

void Angler::setLicenseNumber(const std::string& newLicenseNumber) {
    licenseNumber = newLicenseNumber;
}

void Angler::saveToFile(const std::string& filename) const {
    std::ofstream output(filename.c_str());
    if (!output) {
        return;
    }

    output << name << "\n";
    output << licenseNumber << "\n";
}

void Angler::loadFromFile(const std::string& filename) {
    std::ifstream input(filename.c_str());
    if (!input) {
        return;
    }

    std::getline(input, name);
    std::getline(input, licenseNumber);
}
