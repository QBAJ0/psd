#ifndef ANGLER_H
#define ANGLER_H

#include <string>

class Angler {
private:
    std::string name;
    std::string licenseNumber;

public:
    Angler();
    Angler(const std::string& name, const std::string& licenseNumber);

    std::string getName() const;
    std::string getLicenseNumber() const;
};

#endif
