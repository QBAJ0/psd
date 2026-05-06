#include "Angler.h"

Angler::Angler() : name(""), licenseNumber("") {}

Angler::Angler(const std::string& name, const std::string& licenseNumber)
    : name(name), licenseNumber(licenseNumber) {}

std::string Angler::getName() const {
    return name;
}

std::string Angler::getLicenseNumber() const {
    return licenseNumber;
}
