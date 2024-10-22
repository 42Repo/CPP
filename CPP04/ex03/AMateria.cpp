#include "AMateria.h"
#include "ICharacter.h"

AMateria::AMateria() : _type("Default") {}

AMateria::AMateria(std::string const &type) : _type(type) {}

AMateria::AMateria(const AMateria &other) : _type(other._type) {}

AMateria &AMateria::operator=(const AMateria &other) {
    if (this != &other) {
        this->_type = other._type;
    }
    return *this;
}

AMateria::~AMateria() {}

std::string const &AMateria::getType() const { return _type; }

void AMateria::use(ICharacter &target) {
    std::cout << "* uses some materia on " << target.getName() << " *" << std::endl;
}
