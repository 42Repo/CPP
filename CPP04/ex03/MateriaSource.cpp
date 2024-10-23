#include "MateriaSource.h"

MateriaSource::MateriaSource() : _materias() {
    for (int i = 0; i < 4; i++) {
        _materias[i] = NULL;
    }
}

MateriaSource::MateriaSource(const MateriaSource &other) {
    for (int i = 0; i < 4; i++) {
        if (other._materias[i])
            _materias[i] = other._materias[i]->clone();
        else
            _materias[i] = NULL;
    }
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other) {
    if (this != &other) {
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

MateriaSource::~MateriaSource() {
    for (int i = 0; i < 4; i++) {
        delete _materias[i];
    }
}

void MateriaSource::learnMateria(AMateria *m) {
    for (int i = 0; i < 4; i++) {
        if (!_materias[i]) {
            std::cout << "MateriaSource learned " << m->getType() << std::endl;
            _materias[i] = m;
            return;
        }
    }
    std::cout << "MateriaSource can't learn more than 4 materias" << std::endl;
}

AMateria *MateriaSource::createMateria(std::string const &type) {
    for (int i = 0; i < 4; i++) {
        if (_materias[i] && _materias[i]->getType() == type) {
            std::cout << "MateriaSource created " << type << std::endl;
            return _materias[i]->clone();
        }
    }
    std::cout << "MateriaSource can't create materia of type " << type << std::endl;
    return NULL;
}
