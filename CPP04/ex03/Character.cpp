#include "Character.h"

Character::Character() : _materias() {
    for (int i = 0; i < 4; i++) {
        _materias[i] = NULL;
    }
}

Character::Character(std::string const &name) : _name(name), _materias() {
    for (int i = 0; i < 4; i++) {
        _materias[i] = NULL;
    }
}

Character::Character(const Character &other) : _name(other._name), _materias() {
    for (int i = 0; i < 4; i++) {
        if (other._materias[i])
            _materias[i] = other._materias[i]->clone();
        else
            _materias[i] = NULL;
    }
}

Character &Character::operator=(const Character &other) {
    if (this != &other) {
        _name = other._name;
        for (int i = 0; i < 4; i++) {
            delete _materias[i];
            _materias[i] = NULL;
        }
        for (int i = 0; i < 4; i++) {
            if (other._materias[i])
                _materias[i] = other._materias[i]->clone();
            else
                _materias[i] = NULL;
        }
    }
    return *this;
}

Character::~Character() {
    for (int i = 0; i < 4; i++) {
        delete _materias[i];
    }
}

std::string const &Character::getName() const { return _name; }

void Character::equip(AMateria *m) {
    for (int i = 0; i < 4; i++) {
        if (_materias[i] == NULL) {
            std::cout << "Character equipped " << m->getType() << std::endl;
            _materias[i] = m;
            return;
        }
    }
    std::cout << "Character can't equip more than 4 materias" << std::endl;
}

void Character::unequip(int idx) {
    if (idx >= 0 && idx < 4) {
        std::cout << "Character unequipped " << _materias[idx]->getType() << std::endl;
        _materias[idx] = NULL;
        return;
    }
    std::cout << "Invalid index" << std::endl;
}

void Character::use(int idx, ICharacter &target) {
    if (idx >= 0 && idx < 4 && _materias[idx]) {
        _materias[idx]->use(target);
        return;
    }
    std::cout << "Invalid index" << std::endl;
}
